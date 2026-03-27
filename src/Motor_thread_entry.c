#include "Motor_thread.h"
#include "ZDT_app.h"
#include "ZDT_drv.h"
#include "projdefs.h"
#include "uart_drv.h"
#include "ZDT_app.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "uart_app.h"
//canid 过滤器配置
const canfd_afl_entry_t my_can_filter[1] = 
{
    {
        // 1. ID 配置
        .id = 
        {
            .id         = 0x00,
            .frame_type = CAN_FRAME_TYPE_DATA,
            .id_mode    = CAN_ID_MODE_STANDARD
        },
        // 2. 掩码配置 (不关心任何 ID 位，接收所有数据帧)
        .mask = 
        {
            .mask_id         = 0x00,
            .mask_frame_type = 0,
            .mask_id_mode    = 0
        },
        // 3. 目标配置 (指定数据存入 RX FIFO 0)
        .destination = 
        {
            .minimum_dlc       = CANFD_MINIMUM_DLC_0, // 接收任意长度
            .rx_buffer         = (canfd_rx_mb_t)0,    // 不使用专用 RX Message Buffer
            .fifo_select_flags = CANFD_RX_FIFO_0      // 关键！指定数据存入 RX FIFO 0
        }
    }
};
volatile bool g_is_x_done = false;
volatile bool g_is_y_done = false;
volatile bool g_is_z_done = false;
volatile bool g_is_catch_done = false;
volatile uint16_t x_position;
volatile uint16_t y_position;
volatile uint16_t z_position;
volatile uint16_t catch_position;
void can0_callback(can_callback_args_t *p_args)
{
    // 如果是“接收完成”中断
    if (CAN_EVENT_RX_COMPLETE == p_args->event)
    {
        can_frame_t *rx_frame = &p_args->frame;

        //判断是否是“运动到位”报文 (长度为3，内容为 FD 9F 6B)
        if (rx_frame->data_length_code == 3 &&
            rx_frame->data[0] == 0xFD &&
            rx_frame->data[1] == 0x9F &&
            rx_frame->data[2] == 0x6B)
        {
            //判断是哪个电机发来的
            if (rx_frame->id == ZDT_ID_X) {
                g_is_x_done = true;
            } 
            else if (rx_frame->id == ZDT_ID_Y) {
                g_is_y_done = true;
            } 
            else if (rx_frame->id == ZDT_ID_Z) {
                g_is_z_done = true;
            }
            else if (rx_frame->id == ZDT_ID_CATCH) {
                g_is_catch_done = true;
            }
        }
    }
}

/* Motor_thread entry function */
/* pvParameters contains TaskHandle_t */
extern volatile uint16_t medata[data_length];
extern volatile uint8_t is_receving;
extern volatile uint8_t is_cd;
volatile uint8_t scan_flag = 0 ; 
QueueHandle_t g_motor_queue = NULL; //创建消息队列

void Motor_thread_entry(void * pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);

    /* TODO: add your own code here */
    ZDT_Driver_Init();// 初始化 CAN 驱动
    ZDT_Enable_ALL();// 使能所有电机
    ZDT_Gozero_ALL();
    vTaskDelay(4000);
    
    /* 创建信箱实体 (容量为10，每封信容量MotorMsg_t ) */
    // g_motor_queue = xQueueCreate(10, sizeof(MotorMsg_t));
    // if (g_motor_queue == NULL) {
    //     while(1); // 内存不足创建失败，卡死
    // }
    //第一格 50 第二格250 第三格420
    //storeMedicine(420,0,85,4);
    getMedicine(250, cabinet_first_floor, 96, 3);
    // MotorMsg_t rx_msg;
    while(1)
    { 
        // 处理GUI界面返回的信件队列
        // if (xQueueReceive(g_motor_queue, &rx_msg,pdMS_TO_TICKS(50)) == pdTRUE)
        // {
        //     if (rx_msg.cmd == CMD_ZERO_ALL) {
        //         ZDT_Gozero_ALL();
        //     }
        //     else if (rx_msg.cmd == CMD_MOVE_XY_MM) {
        //         Move_XY_To_mm(rx_msg.target_x, rx_msg.target_y, 2000, 100, true);
        //     }
        //     else if (rx_msg.cmd == CMD_SCAN) {
        //         scan_flag = 1;   
        //     }
        // }
        // if(is_cd==1){
        //     getMedicine(medata[2], medata[3], medata[0], 2);
        // }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

