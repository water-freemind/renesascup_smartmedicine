#include "GUI_Thread.h"
#include "uart_app.h"
#include <stdio.h>
/* GUI_Thread entry function */
/* pvParameters contains TaskHandle_t */
void GUI_Thread_entry(void * pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);
    
    /* TODO: add your own code here */
    while (1)
    {
        printf("los....");
        vTaskDelay(1000);
    }
}
