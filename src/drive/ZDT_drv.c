/* --- START OF FILE ZDT_drv.c --- */

#include "ZDT_drv.h"
#include <stdint.h>
#include <string.h> 
#include "r_can_api.h"
#include "Motor_thread.h"

extern const can_instance_t can0;

/* 
 * 底层发送函数
 */
static fsp_err_t ZDT_Send_Raw(uint32_t id, uint8_t *data, uint8_t dlc)
{
    can_frame_t frame;
    fsp_err_t err;
    static uint8_t mb_idx = 0; 
    
    frame.id = id;
    frame.id_mode = CAN_ID_MODE_EXTENDED; 
    frame.type    = CAN_FRAME_TYPE_DATA;
    
    frame.data_length_code = dlc; 
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

void ZDT_Enable(uint32_t id, bool enable)
{
    // PCAN 截图：F3 AB 01 00 6B (长度: 5)
    uint8_t data[5] = {0};
    data[0] = ZDT_CMD_ENABLE;       
    data[1] = 0xAB;                 
    data[2] = (uint8_t)enable;
    data[3] = 0x00; 
    data[4] = 0x6B; 
    
    ZDT_Send_Raw(id, data, 5); // 严格发 5 个字节
}

void ZDT_SetZero(uint32_t id)
{
    // 设置零点通常是：93 6B (长度: 2)
    uint8_t data[2] = {0};
    data[0] = ZDT_CMD_ZERO;         
    data[1] = 0x6B;
    
    ZDT_Send_Raw(id, data, 2); // 严格发 2 个字节
}

void ZDT_Gozero(uint32_t id, bool sync)
{
    uint8_t data[4] = {0};

    data[0] = ZDT_CMD_GOZERO; 
    data[1] = 0x02;           //02表示触发多圈无限位碰撞回零
    data[2] = sync ? 0x01 : 0x00; 
    data[3] = 0x6B;           
    
    ZDT_Send_Raw(id, data, 4); // 严格发 4 个字节
}

void ZDT_MovePosition(uint32_t id, int32_t pos, uint16_t speed, bool sync)
{
    // 获取绝对脉冲数
    uint32_t abs_pos = (pos >= 0) ? (uint32_t)pos : (uint32_t)(-pos);
    
    // 说明书规定：00表示正向，01表示负向
    uint8_t dir = (pos >= 0) ? 0x00 : 0x01; 

    // ====================================================
    // 第一帧：FB + 方向(1) + 速度(2) + 脉冲(4)
    // 刚好 8 个字节
    // ====================================================
    uint8_t frame1[8] = {
        ZDT_CMD_PASS_LIMIT,                     // 0: 功能码 0xFB
        dir,                                  // 1: 符号 (00=正, 01=负)
        (uint8_t)((speed >> 8) & 0xFF),       // 2: 最大转速 高位
        (uint8_t)(speed & 0xFF),              // 3: 最大转速 低位
        (uint8_t)((abs_pos >> 24) & 0xFF),    // 4: 位置角度 最高位
        (uint8_t)((abs_pos >> 16) & 0xFF),    // 5: 位置角度 次高位
        (uint8_t)((abs_pos >> 8) & 0xFF),     // 6: 位置角度 次低位
        (uint8_t)(abs_pos & 0xFF)             // 7: 位置角度 最低位
    };

    // ====================================================
    // 第二帧：FB + 绝对标志 + 同步标志 + 6B
    // ====================================================
    uint8_t frame2[8] = {
        ZDT_CMD_POS_MOVE,                     // 0: 第二帧首字节必须也是 0xFB
        0x01,                                 // 1: 相对/绝对标志 (强制写死 01=绝对模式)
        sync ? 0x01 : 0x00,                   // 2: 多机同步标志
        0x6B,                                 // 3: 校验字节 0x6B ！！！
    };

    // ================= 分包发送 =================
    
    // 发送第一包 (基础 ID)
    ZDT_Send_Raw(id, frame1, 8);
    
    // 给电机大脑 1 毫秒喘息解析时间
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
    
    // 发送第二包 (基础 ID + 1)
    ZDT_Send_Raw(id + 1, frame2, 4);
}

void ZDT_SyncTrigger(void)
{
    // 触发指令：FF 66 (长度: 2)
    uint8_t data[2] = {0};
    data[0] = 0xFF; 
    data[1] = 0x66; 
    data[2] = 0x6B;
    ZDT_Send_Raw(ZDT_ID_ALL, data, 3); // 严格发 3 个字节
}

void ZDT_Stop(uint32_t id)
{
    // 急停指令：FE 98 00 6B (长度: 4)
    uint8_t data[4] = {0};
    data[0] = ZDT_CMD_SYSTEM; 
    data[1] = ZDT_SUB_STOP;   
    data[2] = 0x00; 
    data[3] = 0x6B;           
    
    ZDT_Send_Raw(id, data, 4); // 严格发 4 个字节
}