#include "i2c_touchpad_drv.h"
#include "GUI_Thread.h"
#include "semphr.h"
#include <stdio.h>
#include "SPI_Display_drv.h"

/* --- 1. 硬件资源引用 --- */
/* 确保这里的 g_i2c_master2 与 FSP Stack 名字一致 */
extern const i2c_master_instance_t g_i2c_master2;

/* --- 2. 信号量定义 --- */
static SemaphoreHandle_t g_i2c_done_sem = NULL;
static volatile bool g_i2c_err = false;

/* --- 3. I2C 回调函数 (FSP 中配置名为 i2c_master_callback) --- */
void i2c_master2_callback(i2c_master_callback_args_t *p_args)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (NULL != g_i2c_done_sem)
    {
        if (I2C_MASTER_EVENT_TX_COMPLETE == p_args->event || 
            I2C_MASTER_EVENT_RX_COMPLETE == p_args->event)
        {
            xSemaphoreGiveFromISR(g_i2c_done_sem, &xHigherPriorityTaskWoken);
        }
        else
        {
            g_i2c_err = true; // 记录错误
            xSemaphoreGiveFromISR(g_i2c_done_sem, &xHigherPriorityTaskWoken); // 防止死锁
        }
    }
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/* --- 4. 内部函数：I2C 寄存器读取 --- */
static fsp_err_t i2c_read_regs(uint8_t reg, uint8_t *buf, uint8_t len)
{
    fsp_err_t err;

    /* 步骤A: 发送寄存器地址 (Write) */
    g_i2c_err = false;
    err = g_i2c_master2.p_api->write(g_i2c_master2.p_ctrl, &reg, 1, true); // restart=true
    if (FSP_SUCCESS != err) return err;

    /* 等待发送完成 */
    if (pdTRUE != xSemaphoreTake(g_i2c_done_sem, pdMS_TO_TICKS(100))) return FSP_ERR_TIMEOUT;
    if (g_i2c_err) return FSP_ERR_ABORTED;

    /* 步骤B: 读取数据 (Read) */
    err = g_i2c_master2.p_api->read(g_i2c_master2.p_ctrl, buf, len, false); // restart=false
    if (FSP_SUCCESS != err) return err;

    /* 等待接收完成 */
    if (pdTRUE != xSemaphoreTake(g_i2c_done_sem, pdMS_TO_TICKS(100))) return FSP_ERR_TIMEOUT;
    if (g_i2c_err) return FSP_ERR_ABORTED;

    return FSP_SUCCESS;
}

/* --- 5. 外部接口：初始化 --- */
fsp_err_t touchpad_driver_init(void)
{
    fsp_err_t err;

    /* 创建二值信号量 */
    if (g_i2c_done_sem == NULL)
    {
        g_i2c_done_sem = xSemaphoreCreateBinary();
    }

    /* 打开 I2C 驱动 */
    err = g_i2c_master2.p_api->open(g_i2c_master2.p_ctrl, g_i2c_master2.p_cfg);
    
    /* 可以在这里复位芯片 (如果连接了 RST 引脚) */
    // R_BSP_PinWrite(RST_PIN, BSP_IO_LEVEL_LOW);
    // R_BSP_SoftwareDelay(5, BSP_DELAY_UNITS_MILLISECONDS);
    // R_BSP_PinWrite(RST_PIN, BSP_IO_LEVEL_HIGH);
    
    return err;
}

/* --- 6. 外部接口：读取坐标 --- */
fsp_err_t touchpad_driver_read(touch_data_t *p_data)
{
    uint8_t buf[6];
    fsp_err_t err;

    /* 读取触摸数据 */
    err = i2c_read_regs(FT_REG_TD_STATUS, buf, 5);
    if (FSP_SUCCESS != err) return err;

    uint8_t touch_points = buf[0] & 0x0F;

    if (touch_points > 0 && touch_points <= 5)
    {
        /* 1. 获取原始竖屏坐标 (X: 0~319, Y: 0~479) */
        uint16_t raw_x = ((uint16_t)(buf[1] & 0x0F) << 8) | buf[2];
        uint16_t raw_y = ((uint16_t)(buf[3] & 0x0F) << 8) | buf[4];

        /* 2. 顺时针旋转 90 度的坐标系转换 
         * 原理：
         * 顺时针倒过来后，原来的 Y 轴变成了现在的 X 轴的反向 (480 - 1 - raw_y)
         * 原来的 X 轴变成了现在的 Y 轴 (raw_x)
         */
        p_data->x = 480 - 1 - raw_y; // 新的 X 坐标 (0~479)
        p_data->y = raw_x;           // 新的 Y 坐标 (0~319)

        p_data->status = 1; // 标记为按下
    }
    else
    {
        p_data->status = 0; // 标记为松开
    }

    return FSP_SUCCESS;
}
