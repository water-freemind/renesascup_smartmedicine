#include "ZDT_drv.h"
#include <string.h> 
#include "r_can_api.h"
#include "Motor_thread.h"

extern const can_instance_t can0;

static fsp_err_t ZDT_Send_Raw(uint32_t id, uint8_t *data)
{
    can_frame_t frame;
    fsp_err_t err;
    
    /* 静态变量：每次发送换一个邮箱 (0~7 轮换)，防止单点拥堵 */
    static uint8_t mb_idx = 0; 
    
    frame.id = id;
    frame.id_mode = CAN_ID_MODE_STANDARD; 
    frame.type    = CAN_FRAME_TYPE_DATA;
    frame.data_length_code = 8;
    frame.options = 0;

    memset(frame.data, 0, 8);
    memcpy(frame.data, data, 8);

    /* 设置一个超时计数器，防止死机 */
    uint32_t timeout = 50000; // 大约等待 50 毫秒
    
    do 
    {
        // 尝试写入当前选中的邮箱
        err = can0.p_api->write(can0.p_ctrl, mb_idx, &frame);
        
        if (err == FSP_ERR_IN_USE)
        {
            // 如果这个邮箱正在忙，换下一个邮箱
            mb_idx++;
            if (mb_idx > 7) mb_idx = 0;
            
            // 使用纯硬件延时 1 微秒 (不依赖 FreeRTOS，绝对安全)
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
            timeout--;
        }
        
    } while ((err == FSP_ERR_IN_USE) && (timeout > 0));

    // 如果发送成功，指向下一个空闲邮箱，为下一次发送做准备
    if (err == FSP_SUCCESS)
    {
        mb_idx++;
        if (mb_idx > 7) mb_idx = 0;
    }

    return err;
}
/* --- 外部接口实现 --- */

fsp_err_t ZDT_Driver_Init(void)
{
    return can0.p_api->open(can0.p_ctrl, can0.p_cfg);
}

void ZDT_Enable(uint8_t id, bool enable)
{
    uint8_t data[8] = {0};
    data[0] = ZDT_CMD_ENABLE;       // 0xF3
    data[1] = 0xAB;                 // 校验
    data[2] = (uint8_t)enable;      // 1=Enable
    ZDT_Send_Raw(id, data);
}

void ZDT_SetZero(uint8_t id)//设置单圈回零的零点位置
{
    uint8_t data[8] = {0};
    data[0] = ZDT_CMD_ZERO;         // 0x93
    ZDT_Send_Raw(id, data);
}

void ZDT_Gozero(uint8_t id, uint16_t speed, uint8_t acc, bool sync)
{
    uint8_t data[8] = {0};

    data[0] = ZDT_CMD_ZERO; // 主指令: 0x9A
    data[1] = 0x02;           // 回零模式--堵转碰撞回零
    
    // 多机同步标志: 0x00 代表立即执行，0x01 代表等待广播
    // (具体等待标志是 0x01 还是别的，请参考你的说明书，通常是 1)
    if (sync) {
        data[2] = 0x01; 
    } else {
        data[2] = 0x00;
    }
    ZDT_Send_Raw(id, data);
}
/* 
 * 梯形加减速位置控制
 * sync = true:  开启多机同步标志（等待 Trigger 指令才动）
 * 位置控制
 * pos: 目标脉冲数 (相对或绝对，看电机具体配置，通常上电归零后可视为绝对)
 * speed: 速度 (RPM 或 PPS，视细分而定) 0.1RPM - 3000.0RPM+
 * acc: 加速度 (0-255)
 */
void ZDT_MovePosition(uint8_t id, int32_t pos, uint16_t speed, uint8_t acc, bool sync)
{
    uint8_t data[8] = {0};
    uint8_t mode = (pos >= 0) ? 0x01 : 0x00; // 0x01=正向, 0x00=反向

    if (sync){mode |= 0x10;}// 同步标志位在模式字节的第4位

    data[0] = ZDT_CMD_POS_MOVE;     // 0xFD
    data[1] = mode;                 // 模式字节

    data[2] = (uint8_t)((speed >> 8) & 0xFF);
    data[3] = (uint8_t)(speed & 0xFF);
    data[4] = acc;
    
    data[5] = (uint8_t)((pos >> 16) & 0xFF);
    data[6] = (uint8_t)((pos >> 8) & 0xFF);
    data[7] = (uint8_t)(pos & 0xFF);

    ZDT_Send_Raw(id, data);
}

/* 
 * 广播触发同步开始
 */
void ZDT_SyncTrigger(void)
{
    uint8_t data[8] = {ZDT_ID_ALL};//广播帧
    /* 
     * CAN 广播同步触发指令 
     * ID: 0x00
     * Data: FF 66 ...
     */
    data[0] = 0xFF; 
    data[1] = 0x66; 
    
    ZDT_Send_Raw(ZDT_ID_ALL, data);
}

void ZDT_Stop(uint8_t id)// 紧急停止
{
    uint8_t data[8] = {0};
    data[0] = ZDT_CMD_SYSTEM;
    data[1] = ZDT_SUB_STOP;
    data[2] = 0x00; 
    ZDT_Send_Raw(id, data);
}