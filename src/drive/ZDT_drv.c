#include "ZDT_drv.h"
#include <string.h> 
#include "r_can_api.h" 

extern const can_instance_t can0;
/// --- 内部函数声明 ---
static fsp_err_t ZDT_Send_Raw(uint32_t id, uint8_t *data)
{
    can_frame_t frame;
    
    /* 配置 CAN 帧参数 */
    frame.id = id;
    frame.id_mode = CAN_ID_MODE_STANDARD; // 标准帧 (11位ID)
    frame.type    = CAN_FRAME_TYPE_DATA;  // 数据帧
    frame.data_length_code = 8;           // DLC 固定为 8
    frame.options = 0;

    /* 清空并填充数据 */
    memset(frame.data, 0, 8);// 清零数据区
    memcpy(frame.data, data, 8);//复制指令数据到帧数据区

    return can0.p_api->write(can0.p_ctrl, 0, &frame);//
}

/* --- 外部接口实现 --- */

fsp_err_t ZDT_Driver_Init(void)
{
    /* 打开 CAN 模块 */
    return can0.p_api->open(can0.p_ctrl, can0.p_cfg);
}

void ZDT_Enable(uint8_t id, bool enable)
{
    uint8_t data[8] = {0};
    
    data[0] = ZDT_CMD_ENABLE;       // 指令: 0xF3
    data[1] = 0xAB;                 // 校验字节: 0xAB
    data[2] = (uint8_t)enable;      // 1=使能, 0=失能
    // data[3]~[7] 默认为 0
    
    ZDT_Send_Raw(id, data);
}

void ZDT_SetZero(uint8_t id)
{
    uint8_t data[8] = {0};
    
    data[0] = ZDT_CMD_ZERO;         // 指令: 0x93
    // data[1]~[7] 默认为 0
    
    ZDT_Send_Raw(id, data);
}

void ZDT_MovePosition(uint8_t id, int32_t pos, uint16_t speed, uint8_t acc)
{
    uint8_t data[8] = {0};
    // 假设 0x01 代表正向/绝对模式，具体视电机固件版本而定
    uint8_t dir_mode = (pos >= 0) ? 0x01 : 0x00; 

    data[0] = ZDT_CMD_POS_MOVE;     // 0xFD
    data[1] = dir_mode;             // 方向/模式
    data[2] = (uint8_t)((speed >> 8) & 0xFF);  // 速度高8位
    data[3] = (uint8_t)(speed & 0xFF);         // 速度低8位
    data[4] = acc;                  // 加速度
    
    // 位置数据 (通常是3个字节或4个字节，这里按常见的大端序处理)
    data[5] = (uint8_t)((pos >> 16) & 0xFF);   // Pos High
    data[6] = (uint8_t)((pos >> 8) & 0xFF);    // Pos Mid
    data[7] = (uint8_t)(pos & 0xFF);           // Pos Low

    ZDT_Send_Raw(id, data);
}

