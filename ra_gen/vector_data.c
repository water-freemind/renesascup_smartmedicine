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
        };
        #endif
        #endif