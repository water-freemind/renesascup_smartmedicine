/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_pin_cfg.h"
#include "uart_drv.h"
#include <stdio.h>

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
/* 
 * 使用二值信号量替代原来的 volatile int 标志位 
 * 信号量比忙等待更高效，且是线程安全的
 */
static SemaphoreHandle_t g_uart7_tx_sem = NULL;

/* 标记是否已初始化 */
static bool g_uart_initialized = false;

/* 引用 FSP 生成的结构体 (确保名字和你 Configuration.xml 里的一致) */
extern const uart_instance_t g_uart7;

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/* 
 * 初始化函数
 * 必须在任务开始前或者第一个 printf 前调用
 */
fsp_err_t drv_uart_init(void)
{
    fsp_err_t err = FSP_SUCCESS;

    if (!g_uart_initialized)
    {
        /* 1. 打开串口 */
        err = g_uart7.p_api->open(g_uart7.p_ctrl, g_uart7.p_cfg);
        if(FSP_SUCCESS != err) 
        {
            /* 如果打开失败，可能已经被打开过，或者硬件故障 */
            // __BKPT(); 
        }

        /* 2. 创建二值信号量 */
        if (g_uart7_tx_sem == NULL)
        {
            g_uart7_tx_sem = xSemaphoreCreateBinary();
        }

        g_uart_initialized = true;
    }

    return err;
}

/* 
 * UART 回调函数
 * 请务必在 FSP 配置界面 -> Stacks -> g_uart7 -> Interrupts -> Callback 
 * 填入 "uart7_callback"
 */
void uart7_callback(uart_callback_args_t * p_args)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    switch (p_args->event)
    {
        case UART_EVENT_TX_COMPLETE:
        {
            /* 发送完成，释放信号量 */
            if (g_uart7_tx_sem != NULL)
            {
                xSemaphoreGiveFromISR(g_uart7_tx_sem, &xHigherPriorityTaskWoken);
            }
            break;
        }
        case UART_EVENT_RX_COMPLETE:
        {
            /* 接收处理逻辑 (如果需要) */
            break;
        }
        default:
        {
            break;
        }
    }

    /* 如果释放信号量唤醒了更高优先级的任务，进行任务切换 */
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/***********************************************************************************************************************
 * Stdio Redirection (Printf support)
 **********************************************************************************************************************/

/* 
 * 重写 _write 函数
 * 这是 printf 底层调用的核心函数
 * 
 * fd: 文件描述符 (1=stdout, 2=stderr)
 * pBuffer: 待发送数据的指针
 * size: 数据长度
 */
int _write(int fd, char *pBuffer, int size)
{
    (void)fd; // 忽略未使用参数警告
    fsp_err_t err;

    /* 确保已初始化 */
    if (!g_uart_initialized)
    {
        drv_uart_init();
    }

    /* 
     * 核心优化：直接发送整个 Buffer，而不是用 for 循环逐个字节发
     * 这样可以极大减少中断次数，提高 FreeRTOS 效率
     */
    err = g_uart7.p_api->write(g_uart7.p_ctrl, (uint8_t *)pBuffer, size);
    
    if (FSP_SUCCESS == err)
    {
        /* 
         * 阻塞当前任务，直到发送完成中断释放信号量 
         * 超时时间设为 100ms，防止硬件故障导致死锁
         */
        if (g_uart7_tx_sem != NULL)
        {
            xSemaphoreTake(g_uart7_tx_sem, pdMS_TO_TICKS(100));
        }
    }

    return size;
}

/* 
 * 兼容旧代码或某些特定库调用
 * 但 _write 才是主要入口
 */
int __io_putchar(int ch)
{
    _write(1, (char *)&ch, 1);
    return ch;
}