#ifndef I2C_TOUCHPAD_DRV_H
#define I2C_TOUCHPAD_DRV_H

#include "hal_data.h"

/* FT6336U I2C 地址 (7-bit) */
#define FT6336U_I2C_ADDR    (0x38)

/* 寄存器定义 (参考 Datasheet Page 9-10) */
#define FT_REG_DEVIDE_MODE  (0x00)
#define FT_REG_TD_STATUS    (0x02) // 触摸点数
#define FT_REG_P1_XH        (0x03) // 第1个点 X 高位
#define FT_REG_P1_XL        (0x04) // 第1个点 X 低位
#define FT_REG_P1_YH        (0x05) // 第1个点 Y 高位
#define FT_REG_P1_YL        (0x06) // 第1个点 Y 低位

/* 触摸数据结构体 */
typedef struct {
    uint16_t x;
    uint16_t y;
    uint8_t  status; // 0:松开, 1:按下
} touch_data_t;

/* API 原型 */
fsp_err_t touchpad_driver_init(void);
fsp_err_t touchpad_driver_read(touch_data_t *p_data);

#endif /* I2C_TOUCHPAD_DRV_H */