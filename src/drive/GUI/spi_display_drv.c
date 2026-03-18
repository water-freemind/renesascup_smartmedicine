/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "spi_display_drv.h"
#include <stdio.h>

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define LCD_DC_PIN              BSP_IO_PORT_01_PIN_04
#define LCD_RESET_PIN           BSP_IO_PORT_01_PIN_05
#define LCD_PWM_PIN             BSP_IO_PORT_06_PIN_08

#define SPI_SEND_DATA           BSP_IO_LEVEL_HIGH
#define SPI_SEND_CMD            BSP_IO_LEVEL_LOW

/* ST7796S部分寄存器定义 */
#define LCD_DISPLAY_CMD_RAMCTRL           0xb0 // RAM Control
#define LCD_DISPLAY_CMD_CASET             0x2a // Column address set
#define LCD_DISPLAY_CMD_RASET             0x2b // Row address set
#define LCD_DISPLAY_CMD_RAMWR             0x2c // Memory write

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void spi1_wait_for_tx(void);
static void spi_display_init(void);

static fsp_err_t spi_send_data_cmd(uint8_t * uc_data, bsp_io_level_t uc_cmd, uint32_t len);
static fsp_err_t spi_display_backlight_opt(bsp_io_level_t opt);
static fsp_err_t spi_display_reset(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
/* Event flags for master */
static volatile spi_event_t g_master_event_flag;    // Master Transfer Event completion flag

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

fsp_err_t drv_spi_display_init(void)
{
    fsp_err_t err;

    /* 初始化I2C驱动 */
    err = g_spi1.p_api->open(&g_spi1_ctrl, &g_spi1_cfg);
    if (FSP_SUCCESS != err)
    {
        printf ("%s %d\r\n", __FUNCTION__, __LINE__);
        return err;
    }

    spi_display_init();

    return err;
}

void spi_display_set_window(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    uint8_t caset[4];
    uint8_t raset[4];

    caset[0] = (uint8_t)(x1 >> 8) & 0xFF;
    caset[1] = (uint8_t)(x1 & 0xff);
    caset[2] = (uint8_t)(x2 >> 8) & 0xFF;
    caset[3] = (uint8_t)(x2 & 0xff) ;

    raset[0] = (uint8_t)(y1 >> 8) & 0xFF;
    raset[1] = (uint8_t)(y1 & 0xff);
    raset[2] = (uint8_t)(y2 >> 8) & 0xFF;
    raset[3] = (uint8_t)(y2 & 0xff);

    spi_send_data_cmd((uint8_t []){LCD_DISPLAY_CMD_CASET}, SPI_SEND_CMD, 1); // Horiz
    spi_send_data_cmd(caset, SPI_SEND_DATA, 4);
    spi_send_data_cmd((uint8_t []){LCD_DISPLAY_CMD_RASET}, SPI_SEND_CMD, 1); // Vert
    spi_send_data_cmd(raset, SPI_SEND_DATA, 4);
    spi_send_data_cmd((uint8_t []){LCD_DISPLAY_CMD_RAMWR}, SPI_SEND_CMD, 1); // Memory write
}

fsp_err_t drv_spi_display_flush_data(uint8_t * data, uint32_t len)
{
    // 直接调用你的原生发送函数，它内部会自动把 DC 引脚拉高 (SPI_SEND_DATA)
    // 这样屏幕才会把接收到的字节当成颜色像素存进 GRAM！
    return spi_send_data_cmd(data, SPI_SEND_DATA, len);
}


void spi1_callback(spi_callback_args_t *p_args)
{
    /* 判断是否是发送完成触发的中断 */
    /* 如果是的话就将发送完成标志位置1 */
    if (SPI_EVENT_TRANSFER_COMPLETE == p_args->event)
    {
        g_master_event_flag = SPI_EVENT_TRANSFER_COMPLETE;
    }
    else
    {
        g_master_event_flag = SPI_EVENT_TRANSFER_ABORTED;
    }
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
static void spi1_wait_for_tx(void)
{
    while(!g_master_event_flag);
    g_master_event_flag = false;
}


static void spi_display_init(void)
{
    spi_display_reset();
    spi_display_backlight_opt(BSP_IO_LEVEL_HIGH); // 打开背光

    /* 1. 退出睡眠模式并严格延时 120ms */
    spi_send_data_cmd((uint8_t[]){0x11}, SPI_SEND_CMD, 1);
    R_BSP_SoftwareDelay(120, BSP_DELAY_UNITS_MILLISECONDS);

    /* 2. 厂家提供的电源与 Gamma 配置序列 (解决偏色、发白、变黄问题) */
    spi_send_data_cmd((uint8_t[]){0xf0}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0xc3}, SPI_SEND_DATA, 1);
    spi_send_data_cmd((uint8_t[]){0xf0}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0x96}, SPI_SEND_DATA, 1);

    spi_send_data_cmd((uint8_t[]){0x36}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0xE0}, SPI_SEND_DATA, 1); // 0x48 是竖屏，0x60 是横屏

    spi_send_data_cmd((uint8_t[]){0x3a}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0x55}, SPI_SEND_DATA, 1); // 16-bit 像素格式

    spi_send_data_cmd((uint8_t[]){0xb4}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0x01}, SPI_SEND_DATA, 1);
    spi_send_data_cmd((uint8_t[]){0xb7}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0xc6}, SPI_SEND_DATA, 1);

    spi_send_data_cmd((uint8_t[]){0xe8}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0x40, 0x8A, 0x00, 0x00, 0x29, 0x19, 0xA5, 0x33}, SPI_SEND_DATA, 8);

    spi_send_data_cmd((uint8_t[]){0xc1}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0x06}, SPI_SEND_DATA, 1);
    spi_send_data_cmd((uint8_t[]){0xc2}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0xa7}, SPI_SEND_DATA, 1);
    spi_send_data_cmd((uint8_t[]){0xc5}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0x18}, SPI_SEND_DATA, 1);

    spi_send_data_cmd((uint8_t[]){0xe0}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0xF0, 0x09, 0x0B, 0x06, 0x04, 0x15, 0x2F, 0x54, 0x42, 0x3C, 0x17, 0x14, 0x18, 0x1B}, SPI_SEND_DATA, 14);

    spi_send_data_cmd((uint8_t[]){0xe1}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0xF0, 0x09, 0x0B, 0x06, 0x04, 0x03, 0x2D, 0x43, 0x42, 0x3B, 0x16, 0x14, 0x17, 0x1B}, SPI_SEND_DATA, 14);

    spi_send_data_cmd((uint8_t[]){0xf0}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0x3c}, SPI_SEND_DATA, 1);
    spi_send_data_cmd((uint8_t[]){0xf0}, SPI_SEND_CMD, 1);
    spi_send_data_cmd((uint8_t[]){0x69}, SPI_SEND_DATA, 1);

    /* 3. 开启屏幕颜色反转 (IPS 屏幕必须开启此项，否则色彩错乱) */
    spi_send_data_cmd((uint8_t[]){0x21}, SPI_SEND_CMD, 1); // 0x21: INVON

    /* 4. 开启显示 */
    spi_send_data_cmd((uint8_t[]){0x29}, SPI_SEND_CMD, 1);
}

static fsp_err_t spi_send_data_cmd(uint8_t * uc_data, bsp_io_level_t uc_cmd, uint32_t len)
{
    fsp_err_t err = FSP_SUCCESS;     // Error status

    /* Master send data to device */
    err = g_ioport.p_api->pinWrite(g_ioport.p_ctrl, LCD_DC_PIN, uc_cmd);
    if(FSP_SUCCESS != err)
    {
        printf ("%s %d\r\n", __FUNCTION__, __LINE__);
        return err;
    }

    err = g_spi1.p_api->write(g_spi1.p_ctrl, uc_data, len, SPI_BIT_WIDTH_8_BITS);
    if(FSP_SUCCESS != err)
    {
        printf ("%s %d\r\n", __FUNCTION__, __LINE__);
        return err;
    }

    spi1_wait_for_tx();

    return err;
}

static fsp_err_t spi_display_backlight_opt(bsp_io_level_t opt)
{
    fsp_err_t err = FSP_SUCCESS;     // Error status

    g_ioport.p_api->pinWrite((ioport_ctrl_t * const )&g_ioport.p_ctrl, LCD_PWM_PIN, opt);
    return err;
}


static fsp_err_t spi_display_reset(void)
{
    fsp_err_t err = FSP_SUCCESS;     // Error status

    g_ioport.p_api->pinWrite((ioport_ctrl_t * const )&g_ioport.p_ctrl, LCD_RESET_PIN, BSP_IO_LEVEL_LOW);
    R_BSP_SoftwareDelay(120, BSP_DELAY_UNITS_MILLISECONDS); //延时120ms
    g_ioport.p_api->pinWrite((ioport_ctrl_t * const )&g_ioport.p_ctrl, LCD_RESET_PIN, BSP_IO_LEVEL_HIGH);
    R_BSP_SoftwareDelay(120, BSP_DELAY_UNITS_MILLISECONDS); //延时120ms

    return err;
}
