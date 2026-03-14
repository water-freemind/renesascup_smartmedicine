#include "Motor_thread.h"
#include "ZDT_app.h"
#include "app.h"

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

void can0_callback(can_callback_args_t *p_args)
{
    /* 这里处理 CAN 中断事件 */
    switch (p_args->event)
    {
        case CAN_EVENT_RX_COMPLETE:// 收到了一帧数据
            break;
        case CAN_EVENT_TX_COMPLETE:// 成功发送了一帧数据
            break;
        case CAN_EVENT_ERR_GLOBAL:
        case CAN_EVENT_ERR_CHANNEL:// CAN 错误事件
            break;
        default:
            break;
    }
}
/* Motor_thread entry function */
/* pvParameters contains TaskHandle_t */
void Motor_thread_entry(void * pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);

    /* TODO: add your own code here */
    ZDT_Driver_Init();// 初始化 CAN 驱动
    ZDT_Enable_ALL();// 使能所有电机
    ZDT_Gozero_ALL(1000, 50);// 所有电机回零，速度 1000， 加速度 50

    while(1)
    { 
        
        vTaskDelay(1);
    }
}
