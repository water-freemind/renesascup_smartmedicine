#include "ZDT_app.h"
#include "ZDT_drv.h"
#include <stdint.h>

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

void ZDT_Disable_ALL(void)
{
    ZDT_Enable(ZDT_ID_X, false);
    ZDT_Enable(ZDT_ID_Y, false); 
    ZDT_Enable(ZDT_ID_Z, false);
    ZDT_Enable(ZDT_ID_CATCH, false);
}

void ZDT_Gozero_ALL(uint16_t speed, uint8_t acc)
{

    // Z 轴单独回零，立即执行 (sync: false)
    ZDT_Gozero(ZDT_ID_Z, speed, acc, false);

    vTaskDelay(pdMS_TO_TICKS(3000)); 

    // X 和 Y 轴回零，开启同步标志 (sync: true)，等待 Trigger 指令
    ZDT_Gozero(ZDT_ID_X, speed, acc, true);
    ZDT_Gozero(ZDT_ID_Y, speed, acc, true);
    
    ZDT_SyncTrigger();// 发送广播触发指令，X 和 Y 轴同时开始回零
    
    // 延时等待 X 和 Y 轴回零完成 (假设需要 5 秒)
    vTaskDelay(pdMS_TO_TICKS(5000));

}