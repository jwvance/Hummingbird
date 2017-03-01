#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* LCD_LCDPort */
#define LCD_LCDPort__0__MASK 0x01u
#define LCD_LCDPort__0__PC CYREG_PRT2_PC0
#define LCD_LCDPort__0__PORT 2u
#define LCD_LCDPort__0__SHIFT 0
#define LCD_LCDPort__1__MASK 0x02u
#define LCD_LCDPort__1__PC CYREG_PRT2_PC1
#define LCD_LCDPort__1__PORT 2u
#define LCD_LCDPort__1__SHIFT 1
#define LCD_LCDPort__2__MASK 0x04u
#define LCD_LCDPort__2__PC CYREG_PRT2_PC2
#define LCD_LCDPort__2__PORT 2u
#define LCD_LCDPort__2__SHIFT 2
#define LCD_LCDPort__3__MASK 0x08u
#define LCD_LCDPort__3__PC CYREG_PRT2_PC3
#define LCD_LCDPort__3__PORT 2u
#define LCD_LCDPort__3__SHIFT 3
#define LCD_LCDPort__4__MASK 0x10u
#define LCD_LCDPort__4__PC CYREG_PRT2_PC4
#define LCD_LCDPort__4__PORT 2u
#define LCD_LCDPort__4__SHIFT 4
#define LCD_LCDPort__5__MASK 0x20u
#define LCD_LCDPort__5__PC CYREG_PRT2_PC5
#define LCD_LCDPort__5__PORT 2u
#define LCD_LCDPort__5__SHIFT 5
#define LCD_LCDPort__6__MASK 0x40u
#define LCD_LCDPort__6__PC CYREG_PRT2_PC6
#define LCD_LCDPort__6__PORT 2u
#define LCD_LCDPort__6__SHIFT 6
#define LCD_LCDPort__AG CYREG_PRT2_AG
#define LCD_LCDPort__AMUX CYREG_PRT2_AMUX
#define LCD_LCDPort__BIE CYREG_PRT2_BIE
#define LCD_LCDPort__BIT_MASK CYREG_PRT2_BIT_MASK
#define LCD_LCDPort__BYP CYREG_PRT2_BYP
#define LCD_LCDPort__CTL CYREG_PRT2_CTL
#define LCD_LCDPort__DM0 CYREG_PRT2_DM0
#define LCD_LCDPort__DM1 CYREG_PRT2_DM1
#define LCD_LCDPort__DM2 CYREG_PRT2_DM2
#define LCD_LCDPort__DR CYREG_PRT2_DR
#define LCD_LCDPort__INP_DIS CYREG_PRT2_INP_DIS
#define LCD_LCDPort__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LCD_LCDPort__LCD_EN CYREG_PRT2_LCD_EN
#define LCD_LCDPort__MASK 0x7Fu
#define LCD_LCDPort__PORT 2u
#define LCD_LCDPort__PRT CYREG_PRT2_PRT
#define LCD_LCDPort__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LCD_LCDPort__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LCD_LCDPort__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LCD_LCDPort__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LCD_LCDPort__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LCD_LCDPort__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LCD_LCDPort__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LCD_LCDPort__PS CYREG_PRT2_PS
#define LCD_LCDPort__SHIFT 0
#define LCD_LCDPort__SLW CYREG_PRT2_SLW

/* isr_1 */
#define isr_1__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_1__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_1__INTC_MASK 0x02u
#define isr_1__INTC_NUMBER 1u
#define isr_1__INTC_PRIOR_NUM 7u
#define isr_1__INTC_PRIOR_REG CYREG_NVIC_PRI_1
#define isr_1__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_1__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* MIC_IN */
#define MIC_IN__0__MASK 0x02u
#define MIC_IN__0__PC CYREG_PRT4_PC1
#define MIC_IN__0__PORT 4u
#define MIC_IN__0__SHIFT 1
#define MIC_IN__AG CYREG_PRT4_AG
#define MIC_IN__AMUX CYREG_PRT4_AMUX
#define MIC_IN__BIE CYREG_PRT4_BIE
#define MIC_IN__BIT_MASK CYREG_PRT4_BIT_MASK
#define MIC_IN__BYP CYREG_PRT4_BYP
#define MIC_IN__CTL CYREG_PRT4_CTL
#define MIC_IN__DM0 CYREG_PRT4_DM0
#define MIC_IN__DM1 CYREG_PRT4_DM1
#define MIC_IN__DM2 CYREG_PRT4_DM2
#define MIC_IN__DR CYREG_PRT4_DR
#define MIC_IN__INP_DIS CYREG_PRT4_INP_DIS
#define MIC_IN__LCD_COM_SEG CYREG_PRT4_LCD_COM_SEG
#define MIC_IN__LCD_EN CYREG_PRT4_LCD_EN
#define MIC_IN__MASK 0x02u
#define MIC_IN__PORT 4u
#define MIC_IN__PRT CYREG_PRT4_PRT
#define MIC_IN__PRTDSI__CAPS_SEL CYREG_PRT4_CAPS_SEL
#define MIC_IN__PRTDSI__DBL_SYNC_IN CYREG_PRT4_DBL_SYNC_IN
#define MIC_IN__PRTDSI__OE_SEL0 CYREG_PRT4_OE_SEL0
#define MIC_IN__PRTDSI__OE_SEL1 CYREG_PRT4_OE_SEL1
#define MIC_IN__PRTDSI__OUT_SEL0 CYREG_PRT4_OUT_SEL0
#define MIC_IN__PRTDSI__OUT_SEL1 CYREG_PRT4_OUT_SEL1
#define MIC_IN__PRTDSI__SYNC_OUT CYREG_PRT4_SYNC_OUT
#define MIC_IN__PS CYREG_PRT4_PS
#define MIC_IN__SHIFT 1
#define MIC_IN__SLW CYREG_PRT4_SLW

/* SDCard_Clock_1 */
#define SDCard_Clock_1__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define SDCard_Clock_1__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define SDCard_Clock_1__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define SDCard_Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define SDCard_Clock_1__INDEX 0x00u
#define SDCard_Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define SDCard_Clock_1__PM_ACT_MSK 0x01u
#define SDCard_Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define SDCard_Clock_1__PM_STBY_MSK 0x01u

/* SDCard_miso0 */
#define SDCard_miso0__0__MASK 0x40u
#define SDCard_miso0__0__PC CYREG_PRT6_PC6
#define SDCard_miso0__0__PORT 6u
#define SDCard_miso0__0__SHIFT 6
#define SDCard_miso0__AG CYREG_PRT6_AG
#define SDCard_miso0__AMUX CYREG_PRT6_AMUX
#define SDCard_miso0__BIE CYREG_PRT6_BIE
#define SDCard_miso0__BIT_MASK CYREG_PRT6_BIT_MASK
#define SDCard_miso0__BYP CYREG_PRT6_BYP
#define SDCard_miso0__CTL CYREG_PRT6_CTL
#define SDCard_miso0__DM0 CYREG_PRT6_DM0
#define SDCard_miso0__DM1 CYREG_PRT6_DM1
#define SDCard_miso0__DM2 CYREG_PRT6_DM2
#define SDCard_miso0__DR CYREG_PRT6_DR
#define SDCard_miso0__INP_DIS CYREG_PRT6_INP_DIS
#define SDCard_miso0__LCD_COM_SEG CYREG_PRT6_LCD_COM_SEG
#define SDCard_miso0__LCD_EN CYREG_PRT6_LCD_EN
#define SDCard_miso0__MASK 0x40u
#define SDCard_miso0__PORT 6u
#define SDCard_miso0__PRT CYREG_PRT6_PRT
#define SDCard_miso0__PRTDSI__CAPS_SEL CYREG_PRT6_CAPS_SEL
#define SDCard_miso0__PRTDSI__DBL_SYNC_IN CYREG_PRT6_DBL_SYNC_IN
#define SDCard_miso0__PRTDSI__OE_SEL0 CYREG_PRT6_OE_SEL0
#define SDCard_miso0__PRTDSI__OE_SEL1 CYREG_PRT6_OE_SEL1
#define SDCard_miso0__PRTDSI__OUT_SEL0 CYREG_PRT6_OUT_SEL0
#define SDCard_miso0__PRTDSI__OUT_SEL1 CYREG_PRT6_OUT_SEL1
#define SDCard_miso0__PRTDSI__SYNC_OUT CYREG_PRT6_SYNC_OUT
#define SDCard_miso0__PS CYREG_PRT6_PS
#define SDCard_miso0__SHIFT 6
#define SDCard_miso0__SLW CYREG_PRT6_SLW

/* SDCard_mosi0 */
#define SDCard_mosi0__0__MASK 0x40u
#define SDCard_mosi0__0__PC CYREG_PRT0_PC6
#define SDCard_mosi0__0__PORT 0u
#define SDCard_mosi0__0__SHIFT 6
#define SDCard_mosi0__AG CYREG_PRT0_AG
#define SDCard_mosi0__AMUX CYREG_PRT0_AMUX
#define SDCard_mosi0__BIE CYREG_PRT0_BIE
#define SDCard_mosi0__BIT_MASK CYREG_PRT0_BIT_MASK
#define SDCard_mosi0__BYP CYREG_PRT0_BYP
#define SDCard_mosi0__CTL CYREG_PRT0_CTL
#define SDCard_mosi0__DM0 CYREG_PRT0_DM0
#define SDCard_mosi0__DM1 CYREG_PRT0_DM1
#define SDCard_mosi0__DM2 CYREG_PRT0_DM2
#define SDCard_mosi0__DR CYREG_PRT0_DR
#define SDCard_mosi0__INP_DIS CYREG_PRT0_INP_DIS
#define SDCard_mosi0__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define SDCard_mosi0__LCD_EN CYREG_PRT0_LCD_EN
#define SDCard_mosi0__MASK 0x40u
#define SDCard_mosi0__PORT 0u
#define SDCard_mosi0__PRT CYREG_PRT0_PRT
#define SDCard_mosi0__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define SDCard_mosi0__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define SDCard_mosi0__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define SDCard_mosi0__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define SDCard_mosi0__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define SDCard_mosi0__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define SDCard_mosi0__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define SDCard_mosi0__PS CYREG_PRT0_PS
#define SDCard_mosi0__SHIFT 6
#define SDCard_mosi0__SLW CYREG_PRT0_SLW

/* SDCard_sclk0 */
#define SDCard_sclk0__0__MASK 0x01u
#define SDCard_sclk0__0__PC CYREG_PRT6_PC0
#define SDCard_sclk0__0__PORT 6u
#define SDCard_sclk0__0__SHIFT 0
#define SDCard_sclk0__AG CYREG_PRT6_AG
#define SDCard_sclk0__AMUX CYREG_PRT6_AMUX
#define SDCard_sclk0__BIE CYREG_PRT6_BIE
#define SDCard_sclk0__BIT_MASK CYREG_PRT6_BIT_MASK
#define SDCard_sclk0__BYP CYREG_PRT6_BYP
#define SDCard_sclk0__CTL CYREG_PRT6_CTL
#define SDCard_sclk0__DM0 CYREG_PRT6_DM0
#define SDCard_sclk0__DM1 CYREG_PRT6_DM1
#define SDCard_sclk0__DM2 CYREG_PRT6_DM2
#define SDCard_sclk0__DR CYREG_PRT6_DR
#define SDCard_sclk0__INP_DIS CYREG_PRT6_INP_DIS
#define SDCard_sclk0__LCD_COM_SEG CYREG_PRT6_LCD_COM_SEG
#define SDCard_sclk0__LCD_EN CYREG_PRT6_LCD_EN
#define SDCard_sclk0__MASK 0x01u
#define SDCard_sclk0__PORT 6u
#define SDCard_sclk0__PRT CYREG_PRT6_PRT
#define SDCard_sclk0__PRTDSI__CAPS_SEL CYREG_PRT6_CAPS_SEL
#define SDCard_sclk0__PRTDSI__DBL_SYNC_IN CYREG_PRT6_DBL_SYNC_IN
#define SDCard_sclk0__PRTDSI__OE_SEL0 CYREG_PRT6_OE_SEL0
#define SDCard_sclk0__PRTDSI__OE_SEL1 CYREG_PRT6_OE_SEL1
#define SDCard_sclk0__PRTDSI__OUT_SEL0 CYREG_PRT6_OUT_SEL0
#define SDCard_sclk0__PRTDSI__OUT_SEL1 CYREG_PRT6_OUT_SEL1
#define SDCard_sclk0__PRTDSI__SYNC_OUT CYREG_PRT6_SYNC_OUT
#define SDCard_sclk0__PS CYREG_PRT6_PS
#define SDCard_sclk0__SHIFT 0
#define SDCard_sclk0__SLW CYREG_PRT6_SLW

/* SDCard_SPI0_BSPIM */
#define SDCard_SPI0_BSPIM_BitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define SDCard_SPI0_BSPIM_BitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB12_13_CTL
#define SDCard_SPI0_BSPIM_BitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB12_13_CTL
#define SDCard_SPI0_BSPIM_BitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB12_13_CTL
#define SDCard_SPI0_BSPIM_BitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB12_13_CTL
#define SDCard_SPI0_BSPIM_BitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB12_13_MSK
#define SDCard_SPI0_BSPIM_BitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB12_13_MSK
#define SDCard_SPI0_BSPIM_BitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB12_13_MSK
#define SDCard_SPI0_BSPIM_BitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB12_13_MSK
#define SDCard_SPI0_BSPIM_BitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define SDCard_SPI0_BSPIM_BitCounter__CONTROL_REG CYREG_B0_UDB12_CTL
#define SDCard_SPI0_BSPIM_BitCounter__CONTROL_ST_REG CYREG_B0_UDB12_ST_CTL
#define SDCard_SPI0_BSPIM_BitCounter__COUNT_REG CYREG_B0_UDB12_CTL
#define SDCard_SPI0_BSPIM_BitCounter__COUNT_ST_REG CYREG_B0_UDB12_ST_CTL
#define SDCard_SPI0_BSPIM_BitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB12_MSK_ACTL
#define SDCard_SPI0_BSPIM_BitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB12_MSK_ACTL
#define SDCard_SPI0_BSPIM_BitCounter__PERIOD_REG CYREG_B0_UDB12_MSK
#define SDCard_SPI0_BSPIM_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define SDCard_SPI0_BSPIM_BitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB12_13_ST
#define SDCard_SPI0_BSPIM_BitCounter_ST__MASK_REG CYREG_B0_UDB12_MSK
#define SDCard_SPI0_BSPIM_BitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB12_MSK_ACTL
#define SDCard_SPI0_BSPIM_BitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB12_MSK_ACTL
#define SDCard_SPI0_BSPIM_BitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define SDCard_SPI0_BSPIM_BitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB12_ST_CTL
#define SDCard_SPI0_BSPIM_BitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB12_ST_CTL
#define SDCard_SPI0_BSPIM_BitCounter_ST__STATUS_REG CYREG_B0_UDB12_ST
#define SDCard_SPI0_BSPIM_RxStsReg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define SDCard_SPI0_BSPIM_RxStsReg__16BIT_STATUS_REG CYREG_B0_UDB13_14_ST
#define SDCard_SPI0_BSPIM_RxStsReg__4__MASK 0x10u
#define SDCard_SPI0_BSPIM_RxStsReg__4__POS 4
#define SDCard_SPI0_BSPIM_RxStsReg__5__MASK 0x20u
#define SDCard_SPI0_BSPIM_RxStsReg__5__POS 5
#define SDCard_SPI0_BSPIM_RxStsReg__6__MASK 0x40u
#define SDCard_SPI0_BSPIM_RxStsReg__6__POS 6
#define SDCard_SPI0_BSPIM_RxStsReg__MASK 0x70u
#define SDCard_SPI0_BSPIM_RxStsReg__MASK_REG CYREG_B0_UDB13_MSK
#define SDCard_SPI0_BSPIM_RxStsReg__STATUS_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define SDCard_SPI0_BSPIM_RxStsReg__STATUS_REG CYREG_B0_UDB13_ST
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__16BIT_A0_REG CYREG_B0_UDB13_14_A0
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__16BIT_A1_REG CYREG_B0_UDB13_14_A1
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__16BIT_D0_REG CYREG_B0_UDB13_14_D0
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__16BIT_D1_REG CYREG_B0_UDB13_14_D1
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__16BIT_F0_REG CYREG_B0_UDB13_14_F0
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__16BIT_F1_REG CYREG_B0_UDB13_14_F1
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__A0_A1_REG CYREG_B0_UDB13_A0_A1
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__A0_REG CYREG_B0_UDB13_A0
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__A1_REG CYREG_B0_UDB13_A1
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__D0_D1_REG CYREG_B0_UDB13_D0_D1
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__D0_REG CYREG_B0_UDB13_D0
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__D1_REG CYREG_B0_UDB13_D1
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__F0_F1_REG CYREG_B0_UDB13_F0_F1
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__F0_REG CYREG_B0_UDB13_F0
#define SDCard_SPI0_BSPIM_sR8_Dp_u0__F1_REG CYREG_B0_UDB13_F1
#define SDCard_SPI0_BSPIM_TxStsReg__0__MASK 0x01u
#define SDCard_SPI0_BSPIM_TxStsReg__0__POS 0
#define SDCard_SPI0_BSPIM_TxStsReg__1__MASK 0x02u
#define SDCard_SPI0_BSPIM_TxStsReg__1__POS 1
#define SDCard_SPI0_BSPIM_TxStsReg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB14_15_ACTL
#define SDCard_SPI0_BSPIM_TxStsReg__16BIT_STATUS_REG CYREG_B0_UDB14_15_ST
#define SDCard_SPI0_BSPIM_TxStsReg__2__MASK 0x04u
#define SDCard_SPI0_BSPIM_TxStsReg__2__POS 2
#define SDCard_SPI0_BSPIM_TxStsReg__3__MASK 0x08u
#define SDCard_SPI0_BSPIM_TxStsReg__3__POS 3
#define SDCard_SPI0_BSPIM_TxStsReg__4__MASK 0x10u
#define SDCard_SPI0_BSPIM_TxStsReg__4__POS 4
#define SDCard_SPI0_BSPIM_TxStsReg__MASK 0x1Fu
#define SDCard_SPI0_BSPIM_TxStsReg__MASK_REG CYREG_B0_UDB14_MSK
#define SDCard_SPI0_BSPIM_TxStsReg__STATUS_AUX_CTL_REG CYREG_B0_UDB14_ACTL
#define SDCard_SPI0_BSPIM_TxStsReg__STATUS_REG CYREG_B0_UDB14_ST

/* SDCard_SPI0_CS */
#define SDCard_SPI0_CS__0__MASK 0x80u
#define SDCard_SPI0_CS__0__PC CYREG_PRT0_PC7
#define SDCard_SPI0_CS__0__PORT 0u
#define SDCard_SPI0_CS__0__SHIFT 7
#define SDCard_SPI0_CS__AG CYREG_PRT0_AG
#define SDCard_SPI0_CS__AMUX CYREG_PRT0_AMUX
#define SDCard_SPI0_CS__BIE CYREG_PRT0_BIE
#define SDCard_SPI0_CS__BIT_MASK CYREG_PRT0_BIT_MASK
#define SDCard_SPI0_CS__BYP CYREG_PRT0_BYP
#define SDCard_SPI0_CS__CTL CYREG_PRT0_CTL
#define SDCard_SPI0_CS__DM0 CYREG_PRT0_DM0
#define SDCard_SPI0_CS__DM1 CYREG_PRT0_DM1
#define SDCard_SPI0_CS__DM2 CYREG_PRT0_DM2
#define SDCard_SPI0_CS__DR CYREG_PRT0_DR
#define SDCard_SPI0_CS__INP_DIS CYREG_PRT0_INP_DIS
#define SDCard_SPI0_CS__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define SDCard_SPI0_CS__LCD_EN CYREG_PRT0_LCD_EN
#define SDCard_SPI0_CS__MASK 0x80u
#define SDCard_SPI0_CS__PORT 0u
#define SDCard_SPI0_CS__PRT CYREG_PRT0_PRT
#define SDCard_SPI0_CS__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define SDCard_SPI0_CS__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define SDCard_SPI0_CS__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define SDCard_SPI0_CS__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define SDCard_SPI0_CS__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define SDCard_SPI0_CS__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define SDCard_SPI0_CS__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define SDCard_SPI0_CS__PS CYREG_PRT0_PS
#define SDCard_SPI0_CS__SHIFT 7
#define SDCard_SPI0_CS__SLW CYREG_PRT0_SLW

/* MIC_GND */
#define MIC_GND__0__MASK 0x01u
#define MIC_GND__0__PC CYREG_PRT4_PC0
#define MIC_GND__0__PORT 4u
#define MIC_GND__0__SHIFT 0
#define MIC_GND__AG CYREG_PRT4_AG
#define MIC_GND__AMUX CYREG_PRT4_AMUX
#define MIC_GND__BIE CYREG_PRT4_BIE
#define MIC_GND__BIT_MASK CYREG_PRT4_BIT_MASK
#define MIC_GND__BYP CYREG_PRT4_BYP
#define MIC_GND__CTL CYREG_PRT4_CTL
#define MIC_GND__DM0 CYREG_PRT4_DM0
#define MIC_GND__DM1 CYREG_PRT4_DM1
#define MIC_GND__DM2 CYREG_PRT4_DM2
#define MIC_GND__DR CYREG_PRT4_DR
#define MIC_GND__INP_DIS CYREG_PRT4_INP_DIS
#define MIC_GND__LCD_COM_SEG CYREG_PRT4_LCD_COM_SEG
#define MIC_GND__LCD_EN CYREG_PRT4_LCD_EN
#define MIC_GND__MASK 0x01u
#define MIC_GND__PORT 4u
#define MIC_GND__PRT CYREG_PRT4_PRT
#define MIC_GND__PRTDSI__CAPS_SEL CYREG_PRT4_CAPS_SEL
#define MIC_GND__PRTDSI__DBL_SYNC_IN CYREG_PRT4_DBL_SYNC_IN
#define MIC_GND__PRTDSI__OE_SEL0 CYREG_PRT4_OE_SEL0
#define MIC_GND__PRTDSI__OE_SEL1 CYREG_PRT4_OE_SEL1
#define MIC_GND__PRTDSI__OUT_SEL0 CYREG_PRT4_OUT_SEL0
#define MIC_GND__PRTDSI__OUT_SEL1 CYREG_PRT4_OUT_SEL1
#define MIC_GND__PRTDSI__SYNC_OUT CYREG_PRT4_SYNC_OUT
#define MIC_GND__PS CYREG_PRT4_PS
#define MIC_GND__SHIFT 0
#define MIC_GND__SLW CYREG_PRT4_SLW

/* Timer_1_TimerUDB */
#define Timer_1_TimerUDB_rstSts_stsreg__0__MASK 0x01u
#define Timer_1_TimerUDB_rstSts_stsreg__0__POS 0
#define Timer_1_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB06_07_ACTL
#define Timer_1_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG CYREG_B1_UDB06_07_ST
#define Timer_1_TimerUDB_rstSts_stsreg__2__MASK 0x04u
#define Timer_1_TimerUDB_rstSts_stsreg__2__POS 2
#define Timer_1_TimerUDB_rstSts_stsreg__3__MASK 0x08u
#define Timer_1_TimerUDB_rstSts_stsreg__3__POS 3
#define Timer_1_TimerUDB_rstSts_stsreg__MASK 0x0Du
#define Timer_1_TimerUDB_rstSts_stsreg__MASK_REG CYREG_B1_UDB06_MSK
#define Timer_1_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG CYREG_B1_UDB06_ACTL
#define Timer_1_TimerUDB_rstSts_stsreg__STATUS_REG CYREG_B1_UDB06_ST
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B1_UDB04_05_ACTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B1_UDB04_05_CTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B1_UDB04_05_CTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B1_UDB04_05_CTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B1_UDB04_05_CTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG CYREG_B1_UDB04_05_MSK
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B1_UDB04_05_MSK
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B1_UDB04_05_MSK
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B1_UDB04_05_MSK
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK 0x80u
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS 7
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B1_UDB04_ACTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG CYREG_B1_UDB04_CTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG CYREG_B1_UDB04_ST_CTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG CYREG_B1_UDB04_CTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG CYREG_B1_UDB04_ST_CTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK 0x80u
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B1_UDB04_MSK_ACTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B1_UDB04_MSK_ACTL
#define Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG CYREG_B1_UDB04_MSK
#define Timer_1_TimerUDB_sT24_timerdp_u0__16BIT_A0_REG CYREG_B1_UDB04_05_A0
#define Timer_1_TimerUDB_sT24_timerdp_u0__16BIT_A1_REG CYREG_B1_UDB04_05_A1
#define Timer_1_TimerUDB_sT24_timerdp_u0__16BIT_D0_REG CYREG_B1_UDB04_05_D0
#define Timer_1_TimerUDB_sT24_timerdp_u0__16BIT_D1_REG CYREG_B1_UDB04_05_D1
#define Timer_1_TimerUDB_sT24_timerdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB04_05_ACTL
#define Timer_1_TimerUDB_sT24_timerdp_u0__16BIT_F0_REG CYREG_B1_UDB04_05_F0
#define Timer_1_TimerUDB_sT24_timerdp_u0__16BIT_F1_REG CYREG_B1_UDB04_05_F1
#define Timer_1_TimerUDB_sT24_timerdp_u0__A0_A1_REG CYREG_B1_UDB04_A0_A1
#define Timer_1_TimerUDB_sT24_timerdp_u0__A0_REG CYREG_B1_UDB04_A0
#define Timer_1_TimerUDB_sT24_timerdp_u0__A1_REG CYREG_B1_UDB04_A1
#define Timer_1_TimerUDB_sT24_timerdp_u0__D0_D1_REG CYREG_B1_UDB04_D0_D1
#define Timer_1_TimerUDB_sT24_timerdp_u0__D0_REG CYREG_B1_UDB04_D0
#define Timer_1_TimerUDB_sT24_timerdp_u0__D1_REG CYREG_B1_UDB04_D1
#define Timer_1_TimerUDB_sT24_timerdp_u0__DP_AUX_CTL_REG CYREG_B1_UDB04_ACTL
#define Timer_1_TimerUDB_sT24_timerdp_u0__F0_F1_REG CYREG_B1_UDB04_F0_F1
#define Timer_1_TimerUDB_sT24_timerdp_u0__F0_REG CYREG_B1_UDB04_F0
#define Timer_1_TimerUDB_sT24_timerdp_u0__F1_REG CYREG_B1_UDB04_F1
#define Timer_1_TimerUDB_sT24_timerdp_u0__MSK_DP_AUX_CTL_REG CYREG_B1_UDB04_MSK_ACTL
#define Timer_1_TimerUDB_sT24_timerdp_u0__PER_DP_AUX_CTL_REG CYREG_B1_UDB04_MSK_ACTL
#define Timer_1_TimerUDB_sT24_timerdp_u1__16BIT_A0_REG CYREG_B1_UDB05_06_A0
#define Timer_1_TimerUDB_sT24_timerdp_u1__16BIT_A1_REG CYREG_B1_UDB05_06_A1
#define Timer_1_TimerUDB_sT24_timerdp_u1__16BIT_D0_REG CYREG_B1_UDB05_06_D0
#define Timer_1_TimerUDB_sT24_timerdp_u1__16BIT_D1_REG CYREG_B1_UDB05_06_D1
#define Timer_1_TimerUDB_sT24_timerdp_u1__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB05_06_ACTL
#define Timer_1_TimerUDB_sT24_timerdp_u1__16BIT_F0_REG CYREG_B1_UDB05_06_F0
#define Timer_1_TimerUDB_sT24_timerdp_u1__16BIT_F1_REG CYREG_B1_UDB05_06_F1
#define Timer_1_TimerUDB_sT24_timerdp_u1__A0_A1_REG CYREG_B1_UDB05_A0_A1
#define Timer_1_TimerUDB_sT24_timerdp_u1__A0_REG CYREG_B1_UDB05_A0
#define Timer_1_TimerUDB_sT24_timerdp_u1__A1_REG CYREG_B1_UDB05_A1
#define Timer_1_TimerUDB_sT24_timerdp_u1__D0_D1_REG CYREG_B1_UDB05_D0_D1
#define Timer_1_TimerUDB_sT24_timerdp_u1__D0_REG CYREG_B1_UDB05_D0
#define Timer_1_TimerUDB_sT24_timerdp_u1__D1_REG CYREG_B1_UDB05_D1
#define Timer_1_TimerUDB_sT24_timerdp_u1__DP_AUX_CTL_REG CYREG_B1_UDB05_ACTL
#define Timer_1_TimerUDB_sT24_timerdp_u1__F0_F1_REG CYREG_B1_UDB05_F0_F1
#define Timer_1_TimerUDB_sT24_timerdp_u1__F0_REG CYREG_B1_UDB05_F0
#define Timer_1_TimerUDB_sT24_timerdp_u1__F1_REG CYREG_B1_UDB05_F1
#define Timer_1_TimerUDB_sT24_timerdp_u2__16BIT_A0_REG CYREG_B1_UDB06_07_A0
#define Timer_1_TimerUDB_sT24_timerdp_u2__16BIT_A1_REG CYREG_B1_UDB06_07_A1
#define Timer_1_TimerUDB_sT24_timerdp_u2__16BIT_D0_REG CYREG_B1_UDB06_07_D0
#define Timer_1_TimerUDB_sT24_timerdp_u2__16BIT_D1_REG CYREG_B1_UDB06_07_D1
#define Timer_1_TimerUDB_sT24_timerdp_u2__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB06_07_ACTL
#define Timer_1_TimerUDB_sT24_timerdp_u2__16BIT_F0_REG CYREG_B1_UDB06_07_F0
#define Timer_1_TimerUDB_sT24_timerdp_u2__16BIT_F1_REG CYREG_B1_UDB06_07_F1
#define Timer_1_TimerUDB_sT24_timerdp_u2__A0_A1_REG CYREG_B1_UDB06_A0_A1
#define Timer_1_TimerUDB_sT24_timerdp_u2__A0_REG CYREG_B1_UDB06_A0
#define Timer_1_TimerUDB_sT24_timerdp_u2__A1_REG CYREG_B1_UDB06_A1
#define Timer_1_TimerUDB_sT24_timerdp_u2__D0_D1_REG CYREG_B1_UDB06_D0_D1
#define Timer_1_TimerUDB_sT24_timerdp_u2__D0_REG CYREG_B1_UDB06_D0
#define Timer_1_TimerUDB_sT24_timerdp_u2__D1_REG CYREG_B1_UDB06_D1
#define Timer_1_TimerUDB_sT24_timerdp_u2__DP_AUX_CTL_REG CYREG_B1_UDB06_ACTL
#define Timer_1_TimerUDB_sT24_timerdp_u2__F0_F1_REG CYREG_B1_UDB06_F0_F1
#define Timer_1_TimerUDB_sT24_timerdp_u2__F0_REG CYREG_B1_UDB06_F0
#define Timer_1_TimerUDB_sT24_timerdp_u2__F1_REG CYREG_B1_UDB06_F1

/* ADC_SAR_1_ADC_SAR */
#define ADC_SAR_1_ADC_SAR__CLK CYREG_SAR0_CLK
#define ADC_SAR_1_ADC_SAR__CSR0 CYREG_SAR0_CSR0
#define ADC_SAR_1_ADC_SAR__CSR1 CYREG_SAR0_CSR1
#define ADC_SAR_1_ADC_SAR__CSR2 CYREG_SAR0_CSR2
#define ADC_SAR_1_ADC_SAR__CSR3 CYREG_SAR0_CSR3
#define ADC_SAR_1_ADC_SAR__CSR4 CYREG_SAR0_CSR4
#define ADC_SAR_1_ADC_SAR__CSR5 CYREG_SAR0_CSR5
#define ADC_SAR_1_ADC_SAR__CSR6 CYREG_SAR0_CSR6
#define ADC_SAR_1_ADC_SAR__PM_ACT_CFG CYREG_PM_ACT_CFG11
#define ADC_SAR_1_ADC_SAR__PM_ACT_MSK 0x01u
#define ADC_SAR_1_ADC_SAR__PM_STBY_CFG CYREG_PM_STBY_CFG11
#define ADC_SAR_1_ADC_SAR__PM_STBY_MSK 0x01u
#define ADC_SAR_1_ADC_SAR__SW0 CYREG_SAR0_SW0
#define ADC_SAR_1_ADC_SAR__SW2 CYREG_SAR0_SW2
#define ADC_SAR_1_ADC_SAR__SW3 CYREG_SAR0_SW3
#define ADC_SAR_1_ADC_SAR__SW4 CYREG_SAR0_SW4
#define ADC_SAR_1_ADC_SAR__SW6 CYREG_SAR0_SW6
#define ADC_SAR_1_ADC_SAR__TR0 CYREG_SAR0_TR0
#define ADC_SAR_1_ADC_SAR__WRK0 CYREG_SAR0_WRK0
#define ADC_SAR_1_ADC_SAR__WRK1 CYREG_SAR0_WRK1

/* ADC_SAR_1_IRQ */
#define ADC_SAR_1_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define ADC_SAR_1_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define ADC_SAR_1_IRQ__INTC_MASK 0x01u
#define ADC_SAR_1_IRQ__INTC_NUMBER 0u
#define ADC_SAR_1_IRQ__INTC_PRIOR_NUM 7u
#define ADC_SAR_1_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define ADC_SAR_1_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define ADC_SAR_1_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* ADC_SAR_1_theACLK */
#define ADC_SAR_1_theACLK__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define ADC_SAR_1_theACLK__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define ADC_SAR_1_theACLK__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define ADC_SAR_1_theACLK__CFG2_SRC_SEL_MASK 0x07u
#define ADC_SAR_1_theACLK__INDEX 0x01u
#define ADC_SAR_1_theACLK__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define ADC_SAR_1_theACLK__PM_ACT_MSK 0x02u
#define ADC_SAR_1_theACLK__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define ADC_SAR_1_theACLK__PM_STBY_MSK 0x02u

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 48000000U
#define BCLK__BUS_CLK__KHZ 48000U
#define BCLK__BUS_CLK__MHZ 48U
#define CY_PROJECT_NAME "Hummingbird Test"
#define CY_VERSION "PSoC Creator  3.2 SP1"
#define CYDEV_CHIP_DIE_GEN4 2u
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 13u
#define CYDEV_CHIP_DIE_PSOC4A 6u
#define CYDEV_CHIP_DIE_PSOC5LP 12u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E123069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 6u
#define CYDEV_CHIP_MEMBER_4C 10u
#define CYDEV_CHIP_MEMBER_4D 3u
#define CYDEV_CHIP_MEMBER_4E 5u
#define CYDEV_CHIP_MEMBER_4F 7u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 4u
#define CYDEV_CHIP_MEMBER_4L 9u
#define CYDEV_CHIP_MEMBER_4M 8u
#define CYDEV_CHIP_MEMBER_5A 12u
#define CYDEV_CHIP_MEMBER_5B 11u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_GEN4_ES 17u
#define CYDEV_CHIP_REV_GEN4_ES2 33u
#define CYDEV_CHIP_REV_GEN4_PRODUCTION 17u
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4C_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000003u
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USB_CLK_OSC_LOCKING_ENABLED_AT_PWR_UP 
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
