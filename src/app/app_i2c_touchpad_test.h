#ifndef APP_I2C_TOUCHPAD_H
#define APP_I2C_TOUCHPAD_H

#include <stdbool.h>
#include <stdint.h>

/* 提供给 App 或 LVGL 调用的接口 */
void app_touchpad_init(void);
bool app_touchpad_read(int16_t *x, int16_t *y);

#endif /* APP_I2C_TOUCHPAD_H */
