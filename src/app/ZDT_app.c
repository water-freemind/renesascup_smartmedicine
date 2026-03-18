#include "ZDT_app.h"
#include "ZDT_drv.h"
#include "ra/fsp/src/bsp/mcu/all/bsp_mcu_api.h"
#include <stdint.h>

#define PULSE_PER_MM_XY  (3600.0f / 84.0f) // X/Y 轴每毫米对应的脉冲数 (以细分后每转 16384 脉冲为基准)

/*
    * 这里是张大头 57 电机的应用层代码，负责调用驱动层函数实现具体功能。
*/
void ZDT_Enable_ALL(void)
{
    ZDT_Enable(ZDT_ID_X, true);
    ZDT_Enable(ZDT_ID_Y, true); 
    ZDT_Enable(ZDT_ID_Z, true);
    ZDT_Enable(ZDT_ID_CATCH, true);
}

void ZDT_Gozero_ALL(void)
{
    // Z 轴单独回零，立即执行 (sync: false)
    ZDT_Gozero(ZDT_ID_Z, false);
    ZDT_Gozero(ZDT_ID_X, false);
    ZDT_Gozero(ZDT_ID_Y, false);
}
void Move_XY_To_mm(float x_mm, float y_mm, uint16_t speed, uint8_t acc, bool sync)
{
    // 1. 将毫米乘以比例系数，强制转换为 int32_t 脉冲数
    int32_t x_pulse = (int32_t)(x_mm * PULSE_PER_MM_XY);
    int32_t y_pulse = (int32_t)(y_mm * PULSE_PER_MM_XY);
    // 如果要求同步，先让电机憋着 (sync = true)
    ZDT_MovePosition(ZDT_ID_X, x_pulse, speed, acc, true);
    ZDT_MovePosition(ZDT_ID_Y, y_pulse, speed, acc, true);
}