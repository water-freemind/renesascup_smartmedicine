#include "GUI_Thread.h"
#include "uart_app.h"
#include "app_spi_display_test.h"
#include "app_i2c_touchpad_test.h"
#include <stdio.h>
/* GUI_Thread entry function */
/* pvParameters contains TaskHandle_t */
void GUI_Thread_entry(void * pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);
    /* 1. 初始化触摸屏 */
    printf("Initializing Touchpad...\n");
    
    /* 这里的 app_touchpad_init 会调用底层的 touchpad_driver_init */
    app_touchpad_init(); 

    /* 定义变量存储坐标 */
    int16_t x = 0;
    int16_t y = 0;
    bool is_pressed = false;

    while (1)
    {
        //读取触摸状态
        is_pressed = app_touchpad_read(&x, &y);

        app_spi_display_test();
        //如果按下，打印坐标
        if (is_pressed)
        {
            printf("Touch Detected! X: %d, Y: %d\n", x, y);
        }
        else
        {
            //printf("Released.\n");
        }
        /* 延时 50ms (模拟 LVGL 的轮询周期) */
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}
