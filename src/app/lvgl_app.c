#include "app.h"
#include "uart_drv.h"
#include "gpt_timer_drv.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lvgl.h"
#include <stdio.h>

/* ================================================== */
/* 1. 引入 GUI Guider 生成的头文件                      */
/* ================================================== */
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

/* ================================================== */
/* 2. 声明全局的 UI 结构体对象                           */
/* ================================================== */
lv_ui guider_ui;

void app_lvgl(void)
{
    fsp_err_t err;

    err = drv_uart_init();
    if(FSP_SUCCESS != err) __BKPT();

    err = drv_gpt_timer_init();
    if(FSP_SUCCESS != err)
    {
        printf ("%s %d\r\n", __FUNCTION__, __LINE__);
        __BKPT();
    }

    /* LVGL 底层初始化 */
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    /* ================================================== */
    /* 3. 实例化并加载 GUI Guider 生成的 UI 界面             */
    /* ================================================== */
    setup_ui(&guider_ui);     // 加载控件、布局、样式
    events_init(&guider_ui);  // 绑定事件 (比如按钮点击)
    custom_init(&guider_ui);  // 加载自定义代码

    while(1)
    {
        lv_task_handler(); 
        
        // 【注意】：因为这个函数是在 RTOS 的 GUI_Thread 里被调用的
        // 最好使用 vTaskDelay，但如果你的底层必须用 R_BSP_SoftwareDelay，
        // 请确保这个线程的优先级设置得合适，不要阻塞了电机线程。
        vTaskDelay(pdMS_TO_TICKS(5)); 
    }
}