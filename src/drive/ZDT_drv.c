/* --- START OF FILE ZDT_drv.c --- */

#include "ZDT_drv.h"
#include <string.h> 
#include "r_can_api.h"
#include "Motor_thread.h"

extern const can_instance_t can0;

/* 
 * 修改点1：增加 dlc (数据长度) 参数，支持发送变长帧
 */
static fsp_err_t ZDT_Send_Raw(uint32_t id, uint8_t *data, uint8_t dlc)
{
    can_frame_t frame;
    fsp_err_t err;
    static uint8_t mb_idx = 0; 
    
    frame.id = id;
    frame.id_mode = CAN_ID_MODE_STANDARD; 
    frame.type    = CAN_FRAME_TYPE_DATA;
    frame.data_length_code = dlc; // 使用传入的真实长度
    frame.options = 0;

    memset(frame.data, 0, 8);
    // 防止越界
    if (dlc > 8) dlc = 8;
    memcpy(frame.data, data, dlc);

    uint32_t timeout = 50000; 
    do 
    {
        err = can0.p_api->write(can0.p_ctrl, mb_idx, &frame);
        
        if (err == FSP_ERR_IN_USE)
        {
            mb_idx++;
            if (mb_idx > 7) mb_idx = 0;
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
            timeout--;
        }
    } while ((err == FSP_ERR_IN_USE) && (timeout > 0));

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
    data[0] = ZDT_CMD_ENABLE;       
    data[1] = 0xAB;                 
    data[2] = (uint8_t)enable;
    data[3] = 0x00; // 同步位
    data[4] = 0x6B; // 校验位
    ZDT_Send_Raw(id, data, 8);
}

void ZDT_SetZero(uint8_t id)
{
    uint8_t data[8] = {0};
    data[0] = ZDT_CMD_ZERO;         
    data[1] = 0x6B;
    ZDT_Send_Raw(id, data, 8);
}

void ZDT_Gozero(uint8_t id,bool sync)
{
    uint8_t data[8] = {0};

    data[0] = ZDT_CMD_GOZERO; // 0x9A
    data[1] = 0x01;           // 设置完原点回零参数后，可以发送该命令触发原点回零功能。其中，00表示触发单圈就近回零，01表示触发单圈方向回零，02表示触发多圈无限位碰撞回零，03表示触发多圈有限位开关回零
    data[2] = sync ? 0x01 : 0x00; // 同步标志
    data[3] = 0x6B;           // 校验位
    
    ZDT_Send_Raw(id, data, 8);
}

/* 
 * 🔥 核心修复：12字节负载的梯形加减速位置控制 (完全匹配说明书)
 * 因为 CAN 一帧只有 8 字节，这里必须拆分成两帧发送！
 */
void ZDT_MovePosition(uint8_t id, int32_t pos, uint16_t speed, uint8_t acc, bool sync)
{
    uint8_t payload[16] = {0}; // 准备一个足够大的数组装两帧数据

    // 获取绝对脉冲数用于拆分
    uint32_t abs_pos = (pos >= 0) ? (uint32_t)pos : (uint32_t)(-pos);

    // ================== 组装完整的 12 字节指令 ==================
    payload[0] = ZDT_CMD_POS_MOVE;             // 0: 指令 0xFD
    payload[1] = (pos >= 0) ? 0x01 : 0x00;     // 1: 方向 (00=CW, 01=CCW)
    
    payload[2] = (uint8_t)((speed >> 8) & 0xFF);// 2: 速度高位
    payload[3] = (uint8_t)(speed & 0xFF);       // 3: 速度低位
    
    payload[4] = acc;                          // 4: 加速度
    
    payload[5] = (uint8_t)((abs_pos >> 24) & 0xFF); // 5: 脉冲最高位
    payload[6] = (uint8_t)((abs_pos >> 16) & 0xFF); // 6: 脉冲次高位
    payload[7] = (uint8_t)((abs_pos >> 8) & 0xFF);  // 7: 脉冲次低位
    payload[8] = (uint8_t)(abs_pos & 0xFF);         // 8: 脉冲最低位
    
    // 【重要】：这里假设你需要绝对位置模式。如果需要相对模式，请填 0x00
    payload[9] = 0x01;                         // 9: 相对/绝对模式 (01=绝对)
    
    payload[10] = sync ? 0x01 : 0x00;          // 10: 多机同步标志
    
    payload[11] = 0x6B;                        // 11: 校验位 0x6B

    // ================== 拆成两帧发送 ==================
    // 第一帧：发送前 8 个字节
    ZDT_Send_Raw(id, &payload[0], 8);
    
    // 第二帧：发送剩余的 4 个字节 (从 payload[8] 到 payload[11])
    // 凑满 8 字节发送，后面自动用 0 补齐，兼容性最好
    ZDT_Send_Raw(id, &payload[8], 8);
}

void ZDT_SyncTrigger(void)
{
    uint8_t data[8] = {0};
    data[0] = 0xFF; 
    data[1] = 0x66; 
    ZDT_Send_Raw(ZDT_ID_ALL, data, 8);
}

void ZDT_Stop(uint8_t id)
{
    uint8_t data[8] = {0};
    data[0] = ZDT_CMD_SYSTEM; // 0xFE
    data[1] = ZDT_SUB_STOP;   // 0x98
    data[2] = 0x00; 
    data[3] = 0x6B;           // 校验位
    ZDT_Send_Raw(id, data, 8);
}