#ifndef ZDT_DRV_H
#define ZDT_DRV_H

#include "hal_data.h"

/* --- 张大头 57 电机常用指令集 (默认ID 0x01) --- */
#define ZDT_ID_Z  0x01
#define ZDT_ID_X  0x02
#define ZDT_ID_Y  0x03

#define ZDT_CMD_ENABLE    0xF3  // 使能/脱机
#define ZDT_CMD_ZERO      0x93  // 设置当前位置为零点
#define ZDT_CMD_POS_MOVE  0xFD  // 梯形加减速位置模式

/* --- 驱动函数声明 --- */

// 初始化 CAN 模块
fsp_err_t ZDT_Driver_Init(void);

// 电机使能 (enable=true: 锁轴, enable=false: 松轴)
void ZDT_Enable(uint8_t id, bool enable);

// 将当前位置设为零点
void ZDT_SetZero(uint8_t id);

// 位置控制
// pos: 目标脉冲数 (相对或绝对，看电机具体配置，通常上电归零后可视为绝对)
// speed: 速度 (RPM 或 PPS，视细分而定)
// acc: 加速度 (0-255)
void ZDT_MovePosition(uint8_t id, int32_t pos, uint16_t speed, uint8_t acc);

#endif