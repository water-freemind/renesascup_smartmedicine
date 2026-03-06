#include "app_i2c_touchpad_test.h"
#include "i2c_touchpad_drv.h"
#include <stdio.h>

/* 屏幕分辨率 (用于翻转坐标) */
#define LCD_WIDTH   320
#define LCD_HEIGHT  480

void app_touchpad_init(void)
{
    /* 初始化底层驱动 */
    fsp_err_t err = touchpad_driver_init();
    if (FSP_SUCCESS != err)
    {
        printf("Touch Driver Init Failed: %d\n", err);
    }
    else
    {
        printf("Touch Driver Init Success\n");
    }
}

/* 
 * 此函数将被 LVGL 的 输入设备 read_cb 调用 
 * 返回 true 表示由按下状态，false 表示松开
 */
bool app_touchpad_read(int16_t *x, int16_t *y)
{
    touch_data_t raw_data;
    static int16_t last_x = 0;
    static int16_t last_y = 0;

    /* 1. 读取底层数据 */
    fsp_err_t err = touchpad_driver_read(&raw_data);
    if (FSP_SUCCESS != err)
    {
        return false; // 通信失败视作未按下
    }

    /* 2. 处理逻辑 */
    if (raw_data.status == 1) // 按下
    {
        /* 
         * TODO: 这里需要根据实际屏幕安装方向调整 X/Y
         * 比如：不需要转换直接赋值
         */
        *x = raw_data.x;
        *y = raw_data.y;

        /* 
         * 示例：如果触摸屏和显示屏反了，可能需要：
         * *x = LCD_WIDTH - raw_data.x;
         * *y = LCD_HEIGHT - raw_data.y; 
         */

        last_x = *x;
        last_y = *y;
        
        return true; // 返回按下状态
    }
    else
    {
        /* 松开时，LVGL 建议保持最后的坐标 */
        *x = last_x;
        *y = last_y;
        return false; // 返回松开状态
    }
}
