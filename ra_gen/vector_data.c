/* generated vector source file - do not edit */
        #include "bsp_api.h"
        /* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
        #if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_NUM_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = canfd_error_isr, /* CAN0 CHERR (Channel  error) */
            [1] = canfd_channel_tx_isr, /* CAN0 TX (Transmit interrupt) */
            [2] = canfd_common_fifo_rx_isr, /* CAN0 COMFRX (Common FIFO receive interrupt) */
            [3] = canfd_error_isr, /* CAN GLERR (Global error) */
            [4] = canfd_rx_fifo_isr, /* CAN RXF (Global receive FIFO interrupt) */
            [5] = sci_uart_rxi_isr, /* SCI7 RXI (Receive data full) */
            [6] = sci_uart_txi_isr, /* SCI7 TXI (Transmit data empty) */
            [7] = sci_uart_tei_isr, /* SCI7 TEI (Transmit end) */
            [8] = sci_uart_eri_isr, /* SCI7 ERI (Receive error) */
            [9] = iic_master_rxi_isr, /* IIC2 RXI (Receive data full) */
            [10] = iic_master_txi_isr, /* IIC2 TXI (Transmit data empty) */
            [11] = iic_master_tei_isr, /* IIC2 TEI (Transmit end) */
            [12] = iic_master_eri_isr, /* IIC2 ERI (Transfer error) */
            [13] = spi_rxi_isr, /* SPI1 RXI (Receive buffer full) */
            [14] = spi_tei_isr, /* SPI1 TEI (Transmission complete event) */
            [15] = spi_eri_isr, /* SPI1 ERI (Error) */
            [16] = dmac_int_isr, /* DMAC1 INT (DMAC1 transfer end) */
            [17] = gpt_counter_overflow_isr, /* GPT0 COUNTER OVERFLOW (Overflow) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_NUM_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_CAN0_CHERR,GROUP0), /* CAN0 CHERR (Channel  error) */
            [1] = BSP_PRV_VECT_ENUM(EVENT_CAN0_TX,GROUP1), /* CAN0 TX (Transmit interrupt) */
            [2] = BSP_PRV_VECT_ENUM(EVENT_CAN0_COMFRX,GROUP2), /* CAN0 COMFRX (Common FIFO receive interrupt) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_CAN_GLERR,GROUP3), /* CAN GLERR (Global error) */
            [4] = BSP_PRV_VECT_ENUM(EVENT_CAN_RXF,GROUP4), /* CAN RXF (Global receive FIFO interrupt) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_SCI7_RXI,GROUP5), /* SCI7 RXI (Receive data full) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_SCI7_TXI,GROUP6), /* SCI7 TXI (Transmit data empty) */
            [7] = BSP_PRV_VECT_ENUM(EVENT_SCI7_TEI,GROUP7), /* SCI7 TEI (Transmit end) */
            [8] = BSP_PRV_VECT_ENUM(EVENT_SCI7_ERI,GROUP0), /* SCI7 ERI (Receive error) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_IIC2_RXI,GROUP1), /* IIC2 RXI (Receive data full) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_IIC2_TXI,GROUP2), /* IIC2 TXI (Transmit data empty) */
            [11] = BSP_PRV_VECT_ENUM(EVENT_IIC2_TEI,GROUP3), /* IIC2 TEI (Transmit end) */
            [12] = BSP_PRV_VECT_ENUM(EVENT_IIC2_ERI,GROUP4), /* IIC2 ERI (Transfer error) */
            [13] = BSP_PRV_VECT_ENUM(EVENT_SPI1_RXI,GROUP5), /* SPI1 RXI (Receive buffer full) */
            [14] = BSP_PRV_VECT_ENUM(EVENT_SPI1_TEI,GROUP6), /* SPI1 TEI (Transmission complete event) */
            [15] = BSP_PRV_VECT_ENUM(EVENT_SPI1_ERI,GROUP7), /* SPI1 ERI (Error) */
            [16] = BSP_PRV_VECT_ENUM(EVENT_DMAC1_INT,GROUP0), /* DMAC1 INT (DMAC1 transfer end) */
            [17] = BSP_PRV_VECT_ENUM(EVENT_GPT0_COUNTER_OVERFLOW,GROUP1), /* GPT0 COUNTER OVERFLOW (Overflow) */
        };
        #endif
        #endif