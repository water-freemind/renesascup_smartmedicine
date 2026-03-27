#include "GUI_Thread.h"
#include <stdio.h>
#include "app.h"
#include "lvgl.h"
/* GUI_Thread entry function */
/* pvParameters contains TaskHandle_t */
void GUI_Thread_entry(void * pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);
    app_lvgl();
    while (1) {
        
    }
}
