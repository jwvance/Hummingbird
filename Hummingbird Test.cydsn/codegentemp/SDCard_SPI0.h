/*******************************************************************************
* File Name: SDCard_SPI0.h
* Version 2.40
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the SPI Master Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_SDCard_SPI0_H)
#define CY_SPIM_SDCard_SPI0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component SPI_Master_v2_40 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define SDCard_SPI0_INTERNAL_CLOCK             (0u)

#if(0u != SDCard_SPI0_INTERNAL_CLOCK)
    #include "SDCard_SPI0_IntClock.h"
#endif /* (0u != SDCard_SPI0_INTERNAL_CLOCK) */

#define SDCard_SPI0_MODE                       (1u)
#define SDCard_SPI0_DATA_WIDTH                 (8u)
#define SDCard_SPI0_MODE_USE_ZERO              (1u)
#define SDCard_SPI0_BIDIRECTIONAL_MODE         (0u)

/* Internal interrupt handling */
#define SDCard_SPI0_TX_BUFFER_SIZE             (4u)
#define SDCard_SPI0_RX_BUFFER_SIZE             (4u)
#define SDCard_SPI0_INTERNAL_TX_INT_ENABLED    (0u)
#define SDCard_SPI0_INTERNAL_RX_INT_ENABLED    (0u)

#define SDCard_SPI0_SINGLE_REG_SIZE            (8u)
#define SDCard_SPI0_USE_SECOND_DATAPATH        (SDCard_SPI0_DATA_WIDTH > SDCard_SPI0_SINGLE_REG_SIZE)

#define SDCard_SPI0_FIFO_SIZE                  (4u)
#define SDCard_SPI0_TX_SOFTWARE_BUF_ENABLED    ((0u != SDCard_SPI0_INTERNAL_TX_INT_ENABLED) && \
                                                     (SDCard_SPI0_TX_BUFFER_SIZE > SDCard_SPI0_FIFO_SIZE))

#define SDCard_SPI0_RX_SOFTWARE_BUF_ENABLED    ((0u != SDCard_SPI0_INTERNAL_RX_INT_ENABLED) && \
                                                     (SDCard_SPI0_RX_BUFFER_SIZE > SDCard_SPI0_FIFO_SIZE))


/***************************************
*        Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
    uint8 cntrPeriod;
    #if(CY_UDB_V0)
        uint8 saveSrTxIntMask;
        uint8 saveSrRxIntMask;
    #endif /* (CY_UDB_V0) */

} SDCard_SPI0_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  SDCard_SPI0_Init(void)                           ;
void  SDCard_SPI0_Enable(void)                         ;
void  SDCard_SPI0_Start(void)                          ;
void  SDCard_SPI0_Stop(void)                           ;

void  SDCard_SPI0_EnableTxInt(void)                    ;
void  SDCard_SPI0_EnableRxInt(void)                    ;
void  SDCard_SPI0_DisableTxInt(void)                   ;
void  SDCard_SPI0_DisableRxInt(void)                   ;

void  SDCard_SPI0_Sleep(void)                          ;
void  SDCard_SPI0_Wakeup(void)                         ;
void  SDCard_SPI0_SaveConfig(void)                     ;
void  SDCard_SPI0_RestoreConfig(void)                  ;

void  SDCard_SPI0_SetTxInterruptMode(uint8 intSrc)     ;
void  SDCard_SPI0_SetRxInterruptMode(uint8 intSrc)     ;
uint8 SDCard_SPI0_ReadTxStatus(void)                   ;
uint8 SDCard_SPI0_ReadRxStatus(void)                   ;
void  SDCard_SPI0_WriteTxData(uint8 txData)  \
                                                            ;
uint8 SDCard_SPI0_ReadRxData(void) \
                                                            ;
uint8 SDCard_SPI0_GetRxBufferSize(void)                ;
uint8 SDCard_SPI0_GetTxBufferSize(void)                ;
void  SDCard_SPI0_ClearRxBuffer(void)                  ;
void  SDCard_SPI0_ClearTxBuffer(void)                  ;
void  SDCard_SPI0_ClearFIFO(void)                              ;
void  SDCard_SPI0_PutArray(const uint8 buffer[], uint8 byteCount) \
                                                            ;

#if(0u != SDCard_SPI0_BIDIRECTIONAL_MODE)
    void  SDCard_SPI0_TxEnable(void)                   ;
    void  SDCard_SPI0_TxDisable(void)                  ;
#endif /* (0u != SDCard_SPI0_BIDIRECTIONAL_MODE) */

CY_ISR_PROTO(SDCard_SPI0_TX_ISR);
CY_ISR_PROTO(SDCard_SPI0_RX_ISR);


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 SDCard_SPI0_initVar;


/***************************************
*           API Constants
***************************************/

#define SDCard_SPI0_TX_ISR_NUMBER     ((uint8) (SDCard_SPI0_TxInternalInterrupt__INTC_NUMBER))
#define SDCard_SPI0_RX_ISR_NUMBER     ((uint8) (SDCard_SPI0_RxInternalInterrupt__INTC_NUMBER))

#define SDCard_SPI0_TX_ISR_PRIORITY   ((uint8) (SDCard_SPI0_TxInternalInterrupt__INTC_PRIOR_NUM))
#define SDCard_SPI0_RX_ISR_PRIORITY   ((uint8) (SDCard_SPI0_RxInternalInterrupt__INTC_PRIOR_NUM))


/***************************************
*    Initial Parameter Constants
***************************************/

#define SDCard_SPI0_INT_ON_SPI_DONE    ((uint8) (0u   << SDCard_SPI0_STS_SPI_DONE_SHIFT))
#define SDCard_SPI0_INT_ON_TX_EMPTY    ((uint8) (0u   << SDCard_SPI0_STS_TX_FIFO_EMPTY_SHIFT))
#define SDCard_SPI0_INT_ON_TX_NOT_FULL ((uint8) (0u << \
                                                                           SDCard_SPI0_STS_TX_FIFO_NOT_FULL_SHIFT))
#define SDCard_SPI0_INT_ON_BYTE_COMP   ((uint8) (0u  << SDCard_SPI0_STS_BYTE_COMPLETE_SHIFT))
#define SDCard_SPI0_INT_ON_SPI_IDLE    ((uint8) (0u   << SDCard_SPI0_STS_SPI_IDLE_SHIFT))

/* Disable TX_NOT_FULL if software buffer is used */
#define SDCard_SPI0_INT_ON_TX_NOT_FULL_DEF ((SDCard_SPI0_TX_SOFTWARE_BUF_ENABLED) ? \
                                                                        (0u) : (SDCard_SPI0_INT_ON_TX_NOT_FULL))

/* TX interrupt mask */
#define SDCard_SPI0_TX_INIT_INTERRUPTS_MASK    (SDCard_SPI0_INT_ON_SPI_DONE  | \
                                                     SDCard_SPI0_INT_ON_TX_EMPTY  | \
                                                     SDCard_SPI0_INT_ON_TX_NOT_FULL_DEF | \
                                                     SDCard_SPI0_INT_ON_BYTE_COMP | \
                                                     SDCard_SPI0_INT_ON_SPI_IDLE)

#define SDCard_SPI0_INT_ON_RX_FULL         ((uint8) (0u << \
                                                                          SDCard_SPI0_STS_RX_FIFO_FULL_SHIFT))
#define SDCard_SPI0_INT_ON_RX_NOT_EMPTY    ((uint8) (0u << \
                                                                          SDCard_SPI0_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define SDCard_SPI0_INT_ON_RX_OVER         ((uint8) (0u << \
                                                                          SDCard_SPI0_STS_RX_FIFO_OVERRUN_SHIFT))

/* RX interrupt mask */
#define SDCard_SPI0_RX_INIT_INTERRUPTS_MASK    (SDCard_SPI0_INT_ON_RX_FULL      | \
                                                     SDCard_SPI0_INT_ON_RX_NOT_EMPTY | \
                                                     SDCard_SPI0_INT_ON_RX_OVER)
/* Nubmer of bits to receive/transmit */
#define SDCard_SPI0_BITCTR_INIT            (((uint8) (SDCard_SPI0_DATA_WIDTH << 1u)) - 1u)


/***************************************
*             Registers
***************************************/

#if(CY_PSOC3 || CY_PSOC5)
    #define SDCard_SPI0_TXDATA_REG (* (reg8 *) \
                                                SDCard_SPI0_BSPIM_sR8_Dp_u0__F0_REG)
    #define SDCard_SPI0_TXDATA_PTR (  (reg8 *) \
                                                SDCard_SPI0_BSPIM_sR8_Dp_u0__F0_REG)
    #define SDCard_SPI0_RXDATA_REG (* (reg8 *) \
                                                SDCard_SPI0_BSPIM_sR8_Dp_u0__F1_REG)
    #define SDCard_SPI0_RXDATA_PTR (  (reg8 *) \
                                                SDCard_SPI0_BSPIM_sR8_Dp_u0__F1_REG)
#else   /* PSOC4 */
    #if(SDCard_SPI0_USE_SECOND_DATAPATH)
        #define SDCard_SPI0_TXDATA_REG (* (reg16 *) \
                                          SDCard_SPI0_BSPIM_sR8_Dp_u0__16BIT_F0_REG)
        #define SDCard_SPI0_TXDATA_PTR (  (reg16 *) \
                                          SDCard_SPI0_BSPIM_sR8_Dp_u0__16BIT_F0_REG)
        #define SDCard_SPI0_RXDATA_REG (* (reg16 *) \
                                          SDCard_SPI0_BSPIM_sR8_Dp_u0__16BIT_F1_REG)
        #define SDCard_SPI0_RXDATA_PTR         (  (reg16 *) \
                                          SDCard_SPI0_BSPIM_sR8_Dp_u0__16BIT_F1_REG)
    #else
        #define SDCard_SPI0_TXDATA_REG (* (reg8 *) \
                                                SDCard_SPI0_BSPIM_sR8_Dp_u0__F0_REG)
        #define SDCard_SPI0_TXDATA_PTR (  (reg8 *) \
                                                SDCard_SPI0_BSPIM_sR8_Dp_u0__F0_REG)
        #define SDCard_SPI0_RXDATA_REG (* (reg8 *) \
                                                SDCard_SPI0_BSPIM_sR8_Dp_u0__F1_REG)
        #define SDCard_SPI0_RXDATA_PTR (  (reg8 *) \
                                                SDCard_SPI0_BSPIM_sR8_Dp_u0__F1_REG)
    #endif /* (SDCard_SPI0_USE_SECOND_DATAPATH) */
#endif     /* (CY_PSOC3 || CY_PSOC5) */

#define SDCard_SPI0_AUX_CONTROL_DP0_REG (* (reg8 *) \
                                        SDCard_SPI0_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)
#define SDCard_SPI0_AUX_CONTROL_DP0_PTR (  (reg8 *) \
                                        SDCard_SPI0_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)

#if(SDCard_SPI0_USE_SECOND_DATAPATH)
    #define SDCard_SPI0_AUX_CONTROL_DP1_REG  (* (reg8 *) \
                                        SDCard_SPI0_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
    #define SDCard_SPI0_AUX_CONTROL_DP1_PTR  (  (reg8 *) \
                                        SDCard_SPI0_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
#endif /* (SDCard_SPI0_USE_SECOND_DATAPATH) */

#define SDCard_SPI0_COUNTER_PERIOD_REG     (* (reg8 *) SDCard_SPI0_BSPIM_BitCounter__PERIOD_REG)
#define SDCard_SPI0_COUNTER_PERIOD_PTR     (  (reg8 *) SDCard_SPI0_BSPIM_BitCounter__PERIOD_REG)
#define SDCard_SPI0_COUNTER_CONTROL_REG    (* (reg8 *) SDCard_SPI0_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)
#define SDCard_SPI0_COUNTER_CONTROL_PTR    (  (reg8 *) SDCard_SPI0_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)

#define SDCard_SPI0_TX_STATUS_REG          (* (reg8 *) SDCard_SPI0_BSPIM_TxStsReg__STATUS_REG)
#define SDCard_SPI0_TX_STATUS_PTR          (  (reg8 *) SDCard_SPI0_BSPIM_TxStsReg__STATUS_REG)
#define SDCard_SPI0_RX_STATUS_REG          (* (reg8 *) SDCard_SPI0_BSPIM_RxStsReg__STATUS_REG)
#define SDCard_SPI0_RX_STATUS_PTR          (  (reg8 *) SDCard_SPI0_BSPIM_RxStsReg__STATUS_REG)

#define SDCard_SPI0_CONTROL_REG            (* (reg8 *) \
                                      SDCard_SPI0_BSPIM_BidirMode_SyncCtl_CtrlReg__CONTROL_REG)
#define SDCard_SPI0_CONTROL_PTR            (  (reg8 *) \
                                      SDCard_SPI0_BSPIM_BidirMode_SyncCtl_CtrlReg__CONTROL_REG)

#define SDCard_SPI0_TX_STATUS_MASK_REG     (* (reg8 *) SDCard_SPI0_BSPIM_TxStsReg__MASK_REG)
#define SDCard_SPI0_TX_STATUS_MASK_PTR     (  (reg8 *) SDCard_SPI0_BSPIM_TxStsReg__MASK_REG)
#define SDCard_SPI0_RX_STATUS_MASK_REG     (* (reg8 *) SDCard_SPI0_BSPIM_RxStsReg__MASK_REG)
#define SDCard_SPI0_RX_STATUS_MASK_PTR     (  (reg8 *) SDCard_SPI0_BSPIM_RxStsReg__MASK_REG)

#define SDCard_SPI0_TX_STATUS_ACTL_REG     (* (reg8 *) SDCard_SPI0_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define SDCard_SPI0_TX_STATUS_ACTL_PTR     (  (reg8 *) SDCard_SPI0_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define SDCard_SPI0_RX_STATUS_ACTL_REG     (* (reg8 *) SDCard_SPI0_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)
#define SDCard_SPI0_RX_STATUS_ACTL_PTR     (  (reg8 *) SDCard_SPI0_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)

#if(SDCard_SPI0_USE_SECOND_DATAPATH)
    #define SDCard_SPI0_AUX_CONTROLDP1     (SDCard_SPI0_AUX_CONTROL_DP1_REG)
#endif /* (SDCard_SPI0_USE_SECOND_DATAPATH) */


/***************************************
*       Register Constants
***************************************/

/* Status Register Definitions */
#define SDCard_SPI0_STS_SPI_DONE_SHIFT             (0x00u)
#define SDCard_SPI0_STS_TX_FIFO_EMPTY_SHIFT        (0x01u)
#define SDCard_SPI0_STS_TX_FIFO_NOT_FULL_SHIFT     (0x02u)
#define SDCard_SPI0_STS_BYTE_COMPLETE_SHIFT        (0x03u)
#define SDCard_SPI0_STS_SPI_IDLE_SHIFT             (0x04u)
#define SDCard_SPI0_STS_RX_FIFO_FULL_SHIFT         (0x04u)
#define SDCard_SPI0_STS_RX_FIFO_NOT_EMPTY_SHIFT    (0x05u)
#define SDCard_SPI0_STS_RX_FIFO_OVERRUN_SHIFT      (0x06u)

#define SDCard_SPI0_STS_SPI_DONE           ((uint8) (0x01u << SDCard_SPI0_STS_SPI_DONE_SHIFT))
#define SDCard_SPI0_STS_TX_FIFO_EMPTY      ((uint8) (0x01u << SDCard_SPI0_STS_TX_FIFO_EMPTY_SHIFT))
#define SDCard_SPI0_STS_TX_FIFO_NOT_FULL   ((uint8) (0x01u << SDCard_SPI0_STS_TX_FIFO_NOT_FULL_SHIFT))
#define SDCard_SPI0_STS_BYTE_COMPLETE      ((uint8) (0x01u << SDCard_SPI0_STS_BYTE_COMPLETE_SHIFT))
#define SDCard_SPI0_STS_SPI_IDLE           ((uint8) (0x01u << SDCard_SPI0_STS_SPI_IDLE_SHIFT))
#define SDCard_SPI0_STS_RX_FIFO_FULL       ((uint8) (0x01u << SDCard_SPI0_STS_RX_FIFO_FULL_SHIFT))
#define SDCard_SPI0_STS_RX_FIFO_NOT_EMPTY  ((uint8) (0x01u << SDCard_SPI0_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define SDCard_SPI0_STS_RX_FIFO_OVERRUN    ((uint8) (0x01u << SDCard_SPI0_STS_RX_FIFO_OVERRUN_SHIFT))

/* TX and RX masks for clear on read bits */
#define SDCard_SPI0_TX_STS_CLR_ON_RD_BYTES_MASK    (0x09u)
#define SDCard_SPI0_RX_STS_CLR_ON_RD_BYTES_MASK    (0x40u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define SDCard_SPI0_INT_ENABLE     (0x10u) /* Enable interrupt from statusi */
#define SDCard_SPI0_TX_FIFO_CLR    (0x01u) /* F0 - TX FIFO */
#define SDCard_SPI0_RX_FIFO_CLR    (0x02u) /* F1 - RX FIFO */
#define SDCard_SPI0_FIFO_CLR       (SDCard_SPI0_TX_FIFO_CLR | SDCard_SPI0_RX_FIFO_CLR)

/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define SDCard_SPI0_CNTR_ENABLE    (0x20u) /* Enable CNT7 */

/* Bi-Directional mode control bit */
#define SDCard_SPI0_CTRL_TX_SIGNAL_EN  (0x01u)

/* Datapath Auxillary Control Register definitions */
#define SDCard_SPI0_AUX_CTRL_FIFO0_CLR         (0x01u)
#define SDCard_SPI0_AUX_CTRL_FIFO1_CLR         (0x02u)
#define SDCard_SPI0_AUX_CTRL_FIFO0_LVL         (0x04u)
#define SDCard_SPI0_AUX_CTRL_FIFO1_LVL         (0x08u)
#define SDCard_SPI0_STATUS_ACTL_INT_EN_MASK    (0x10u)

/* Component disabled */
#define SDCard_SPI0_DISABLED   (0u)


/***************************************
*       Macros
***************************************/

/* Returns true if componentn enabled */
#define SDCard_SPI0_IS_ENABLED (0u != (SDCard_SPI0_TX_STATUS_ACTL_REG & SDCard_SPI0_INT_ENABLE))

/* Retuns TX status register */
#define SDCard_SPI0_GET_STATUS_TX(swTxSts) ( (uint8)(SDCard_SPI0_TX_STATUS_REG | \
                                                          ((swTxSts) & SDCard_SPI0_TX_STS_CLR_ON_RD_BYTES_MASK)) )
/* Retuns RX status register */
#define SDCard_SPI0_GET_STATUS_RX(swRxSts) ( (uint8)(SDCard_SPI0_RX_STATUS_REG | \
                                                          ((swRxSts) & SDCard_SPI0_RX_STS_CLR_ON_RD_BYTES_MASK)) )


/***************************************
*       Obsolete definitions
***************************************/

/* Following definitions are for version compatibility.
*  They are obsolete in SPIM v2_30.
*  Please do not use it in new projects
*/

#define SDCard_SPI0_WriteByte   SDCard_SPI0_WriteTxData
#define SDCard_SPI0_ReadByte    SDCard_SPI0_ReadRxData
void  SDCard_SPI0_SetInterruptMode(uint8 intSrc)       ;
uint8 SDCard_SPI0_ReadStatus(void)                     ;
void  SDCard_SPI0_EnableInt(void)                      ;
void  SDCard_SPI0_DisableInt(void)                     ;

/* Obsolete register names. Not to be used in new designs */
#define SDCard_SPI0_TXDATA                 (SDCard_SPI0_TXDATA_REG)
#define SDCard_SPI0_RXDATA                 (SDCard_SPI0_RXDATA_REG)
#define SDCard_SPI0_AUX_CONTROLDP0         (SDCard_SPI0_AUX_CONTROL_DP0_REG)
#define SDCard_SPI0_TXBUFFERREAD           (SDCard_SPI0_txBufferRead)
#define SDCard_SPI0_TXBUFFERWRITE          (SDCard_SPI0_txBufferWrite)
#define SDCard_SPI0_RXBUFFERREAD           (SDCard_SPI0_rxBufferRead)
#define SDCard_SPI0_RXBUFFERWRITE          (SDCard_SPI0_rxBufferWrite)

#define SDCard_SPI0_COUNTER_PERIOD         (SDCard_SPI0_COUNTER_PERIOD_REG)
#define SDCard_SPI0_COUNTER_CONTROL        (SDCard_SPI0_COUNTER_CONTROL_REG)
#define SDCard_SPI0_STATUS                 (SDCard_SPI0_TX_STATUS_REG)
#define SDCard_SPI0_CONTROL                (SDCard_SPI0_CONTROL_REG)
#define SDCard_SPI0_STATUS_MASK            (SDCard_SPI0_TX_STATUS_MASK_REG)
#define SDCard_SPI0_STATUS_ACTL            (SDCard_SPI0_TX_STATUS_ACTL_REG)

#define SDCard_SPI0_INIT_INTERRUPTS_MASK  (SDCard_SPI0_INT_ON_SPI_DONE     | \
                                                SDCard_SPI0_INT_ON_TX_EMPTY     | \
                                                SDCard_SPI0_INT_ON_TX_NOT_FULL_DEF  | \
                                                SDCard_SPI0_INT_ON_RX_FULL      | \
                                                SDCard_SPI0_INT_ON_RX_NOT_EMPTY | \
                                                SDCard_SPI0_INT_ON_RX_OVER      | \
                                                SDCard_SPI0_INT_ON_BYTE_COMP)
                                                
/* Following definitions are for version Compatibility.
*  They are obsolete in SPIM v2_40.
*  Please do not use it in new projects
*/

#define SDCard_SPI0_DataWidth                  (SDCard_SPI0_DATA_WIDTH)
#define SDCard_SPI0_InternalClockUsed          (SDCard_SPI0_INTERNAL_CLOCK)
#define SDCard_SPI0_InternalTxInterruptEnabled (SDCard_SPI0_INTERNAL_TX_INT_ENABLED)
#define SDCard_SPI0_InternalRxInterruptEnabled (SDCard_SPI0_INTERNAL_RX_INT_ENABLED)
#define SDCard_SPI0_ModeUseZero                (SDCard_SPI0_MODE_USE_ZERO)
#define SDCard_SPI0_BidirectionalMode          (SDCard_SPI0_BIDIRECTIONAL_MODE)
#define SDCard_SPI0_Mode                       (SDCard_SPI0_MODE)
#define SDCard_SPI0_DATAWIDHT                  (SDCard_SPI0_DATA_WIDTH)
#define SDCard_SPI0_InternalInterruptEnabled   (0u)

#define SDCard_SPI0_TXBUFFERSIZE   (SDCard_SPI0_TX_BUFFER_SIZE)
#define SDCard_SPI0_RXBUFFERSIZE   (SDCard_SPI0_RX_BUFFER_SIZE)

#define SDCard_SPI0_TXBUFFER       SDCard_SPI0_txBuffer
#define SDCard_SPI0_RXBUFFER       SDCard_SPI0_rxBuffer

#endif /* (CY_SPIM_SDCard_SPI0_H) */


/* [] END OF FILE */
