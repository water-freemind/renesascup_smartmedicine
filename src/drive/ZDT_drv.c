#include "ZDT_drv.h"
#include <string.h> 
#include "r_can_api.h"

/* 确保 can0 在 hal_data.c 中已定义 (RASC配置名为 can0) */
extern const can_instance_t can0;

static fsp_err_t ZDT_Send_Raw(uint32_t id, uint8_t *data)
{
    can_frame_t frame;
    
    frame.id = id;
    frame.id_mode = CAN_ID_MODE_STANDARD; 
    frame.type    = CAN_FRAME_TYPE_DATA;
    frame.data_length_code = 8;
    frame.options = 0;

    memset(frame.data, 0, 8);
    memcpy(frame.data, data, 8);

    /* 调用 FSP 写函数 */
    return can0.p_api->write(can0.p_ctrl, 0, &frame);
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

void ZDT_SetZero(uint8_t id)
{
    uint8_t data[8] = {0};
    data[0] = ZDT_CMD_ZERO;         // 0x93
    ZDT_Send_Raw(id, data);
}

/* 
 * 梯形加减速位置控制
 * sync = true:  开启多机同步标志（等待 Trigger 指令才动）
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
    uint8_t data[8] = {0};
    
    /* 
     * CAN 广播同步触发指令 
     * ID: 0x00
     * Data: FF 66 ...
     */
    data[0] = 0xFF; 
    data[1] = 0x66; 
    
    ZDT_Send_Raw(0x00, data);
}

void ZDT_Stop(uint8_t id)// 紧急停止
{
    uint8_t data[8] = {0};
    data[0] = ZDT_CMD_SYSTEM;
    data[1] = ZDT_SUB_STOP;
    data[2] = 0x00; 
    ZDT_Send_Raw(id, data);
}