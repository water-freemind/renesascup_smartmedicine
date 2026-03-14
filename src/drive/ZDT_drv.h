#ifndef ZDT_DRV_H
#define ZDT_DRV_H

#include "hal_data.h"

/* --- 张大头 57 电机常用指令集 (默认ID 0x01) --- */
#define ZDT_ID_X  0X01  
#define ZDT_ID_Y  0X02  
#define ZDT_ID_Z  0X03 
#define ZDT_ID_CATCH 0x04 // 抓手电机
#define ZDT_ID_ALL  0x00 // 广播 ID

#define ZDT_CMD_ENABLE    0xF3  // 使能/脱机
#define ZDT_CMD_ZERO      0x93  // 设置当前位置为零点
#define ZDT_CMD_POS_MOVE  0xFD  // 梯形加减速位置模式
#define ZDT_CMD_SYSTEM    0xFE  // 系统控制 (如复位)
#define ZDT_SUB_STOP      0x98  // 紧急停止
#define ZDT_CMD_GOZERO    0x9A  // 回零运动

//脉冲转长度 (单位: mm/pulse, 以细分后每转 16384 脉冲为基准)
#define PULSE_PER_REV  16384.0f //一圈是 16384 脉冲


/* --- 驱动函数声明 --- */

// 初始化 CAN 模块
fsp_err_t ZDT_Driver_Init(void);

// 电机使能 (enable=true: 锁轴, enable=false: 松轴)
void ZDT_Enable(uint8_t id, bool enable);

// 将当前位置设为零点
void ZDT_SetZero(uint8_t id);


void ZDT_MovePosition(uint8_t id, int32_t pos, uint16_t speed, uint8_t acc, bool sync);
void ZDT_SyncTrigger(void);
void ZDT_Gozero(uint8_t id, uint16_t speed, uint8_t acc, bool sync);
void ZDT_Stop(uint8_t id);// 紧急停止
#endif