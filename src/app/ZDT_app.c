#include "ZDT_app.h"
#include "ZDT_drv.h"

#include <stdint.h>

#include "uart_drv.h"

#define PULSE_PER_MM_XY  (3600.0f / 84.0f) // X/Y 轴每毫米对应的脉冲数 (以细分后每转 16384 脉冲为基准)
#define PULSE_PER_MM_Z   (1000.0f / 23.0f)  // Z /catch
#define zdt_stretch_max_pulse 133200
#define zdt_catch_max_pulse 2000
extern volatile bool g_is_x_done;
extern volatile bool g_is_y_done;
extern volatile bool g_is_z_done;
extern volatile bool g_is_catch_done;

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
    g_is_x_done = false;
    g_is_y_done = false;    
    g_is_z_done = false;
    g_is_catch_done = false;
    ZDT_Gozero(ZDT_ID_Z, false);
    vTaskDelay(4000);
    ZDT_Gozero(ZDT_ID_X, false);
    ZDT_Gozero(ZDT_ID_Y, false);
    //vTaskDelay(5000);
    ZDT_Gozero(ZDT_ID_CATCH, false);
}
void Move_XY_To_mm(float x_mm, float y_mm, uint16_t speed, uint8_t acc, bool sync)
{
    //将毫米乘以比例系数，强制转换为 int32_t 脉冲数
    if(x_mm > cabinet_width){x_mm = cabinet_width;}
    if(y_mm > cabinet_height){y_mm = cabinet_height;}// 安全限制，防止超出电机行程
    int32_t x_pulse = (int32_t)(x_mm * PULSE_PER_MM_XY);
    int32_t y_pulse = (int32_t)(y_mm * PULSE_PER_MM_XY);
    if (g_is_x_done == 0) {
        ZDT_MovePosition(ZDT_ID_X, x_pulse, speed, acc, sync);
        vTaskDelay(10);
    }
    if (g_is_y_done == 0) {
        ZDT_MovePosition(ZDT_ID_Y, y_pulse, speed, acc, sync);
        vTaskDelay(10);
    }
}


void Catch(uint16_t medicine_width_mm, uint16_t speed, uint8_t acc, uint8_t catch_strength_mm)
{
    float close_distance_mm = (130 - (float)medicine_width_mm) / 2.0f;

    if (close_distance_mm < 0.0f) {
        close_distance_mm = 0.0f;
    }

    float target_pulse_f = close_distance_mm * PULSE_PER_MM_Z;

    if (catch_strength_mm > 5) {
        catch_strength_mm = 5; 
    }
    float squeeze_pulse_f = (float)catch_strength_mm * PULSE_PER_MM_Z;
    
    int32_t catch_pulse = (int32_t)(target_pulse_f + squeeze_pulse_f);

    if (catch_pulse > (int32_t)zdt_catch_max_pulse) {
        catch_pulse = (int32_t)zdt_catch_max_pulse;
    }
    if (catch_pulse < 0) {
        catch_pulse = 0;
    }
    g_is_catch_done = false;
    ZDT_MovePosition(ZDT_ID_CATCH, catch_pulse, speed, acc, false);
    vTaskDelay(10);
}

void getMedicine(float x,float floor,uint16_t width,uint8_t catch_strength){
    Move_XY_To_mm(x, floor, 300, 60, 0);
    uint8_t status=0;
    uint8_t status2=0;
    while(status2==0)
    {   
        if(g_is_x_done == 1 && g_is_y_done == 1 && g_is_catch_done!=1){
            ZDT_MovePosition(ZDT_ID_Z, 130000, 1500, 0, 0);
            vTaskDelay(10);
            if(g_is_z_done == 1){
                g_is_z_done = 0;
                Catch(width, 150, 60, 2);
                g_is_x_done = 0;
                g_is_y_done = 0;
            } 
        }
        if(g_is_catch_done == 1){
                if(g_is_x_done == 0 && g_is_y_done == 0 && status==0){
                    Move_XY_To_mm(x, floor+30, 300, 60, 0);
                }
                if(g_is_x_done == 1 && g_is_y_done == 1 && status==0){
                    ZDT_Gozero(ZDT_ID_Z,0);
                    vTaskDelay(4000);
                    g_is_x_done = 0;
                    g_is_y_done = 0;
                    Move_XY_To_mm(0, cabinet_first_floor, 300, 60, 0);
                    status=1; 
                }
                if(g_is_x_done == 1 && g_is_y_done == 1 && status==1){
                        ZDT_Gozero(ZDT_ID_CATCH,0);
                        vTaskDelay(1000);
                        status2=1;
                }
                
        }
    }
    g_is_x_done = false;
    g_is_y_done = false;    
    g_is_z_done = false;
    g_is_catch_done = false;
}

