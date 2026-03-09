#include "GUI_Thread.h"
#include "app.h"
#include <stdio.h>
/* GUI_Thread entry function */
/* pvParameters contains TaskHandle_t */
void GUI_Thread_entry(void * pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);

    printf("Initializing Touchpad...\n");
    app_lvgl_test();
    while (1)
    {
        vTaskDelay(5);
    }
}
