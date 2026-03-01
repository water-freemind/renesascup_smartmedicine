#include "bsp_pin_cfg.h"
#include "hal_data.h" 
#include "led_drv.h"

void LED_Spark(void)
{
    bsp_io_level_t level;
    // 第一步：读取当前LED引脚的电平
    R_IOPORT_PinRead(&g_ioport_ctrl, LED, &level);
    // 第二步：对当前电平取反
    level = !level;
    // 第三步：写入新的电平
    R_IOPORT_PinWrite(&g_ioport_ctrl, LED, level);
}