#include "app.h"
#include "uart_drv.h"
#include "gpt_timer_drv.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lvgl.h"
#include <stdio.h>
#include "ZDT_app.h"

#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

lv_ui guider_ui;
extern volatile uint8_t is_receving;
extern volatile uint8_t is_cd;
extern volatile uint8_t scan_flag; 

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

    setup_ui(&guider_ui);     // 加载控件、布局、样式
    events_init(&guider_ui);  // 绑定事件 (比如按钮点击)
    custom_init(&guider_ui);  // 加载自定义代码

    while(1)
    {
        if (scan_flag==1){
            if (is_receving==0)
            {
                is_cd=1;
                scan_flag=0;
                setup_scr_scrHome(&guider_ui); 
                lv_scr_load(guider_ui.scrHome);
            }
        }
        lv_task_handler(); 
        vTaskDelay(pdMS_TO_TICKS(5)); 
    }
}