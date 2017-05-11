/*******************************************************************************
* File Name: UI_ADC.h
* Version 2.0
*
* Description:
*  Contains the function prototypes, constants and register definition of the
*  ADC SAR Sequencer Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_UI_ADC_H)
    #define CY_UI_ADC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "UI_ADC_TempBuf_dma.h"
#include "UI_ADC_FinalBuf_dma.h"
#include "UI_ADC_SAR.h"

#define UI_ADC_NUMBER_OF_CHANNELS    (4u)
#define UI_ADC_SAMPLE_MODE           (0u)
#define UI_ADC_CLOCK_SOURCE          (0u)

extern int16  UI_ADC_finalArray[UI_ADC_NUMBER_OF_CHANNELS];
extern uint32 UI_ADC_initVar;

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component ADC_SAR_SEQ_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*        Function Prototypes
***************************************/
void UI_ADC_Init(void);
void UI_ADC_Enable(void);
void UI_ADC_Disable(void);
void UI_ADC_Start(void);
void UI_ADC_Stop(void);

uint32 UI_ADC_IsEndConversion(uint8 retMode);
int16 UI_ADC_GetResult16(uint16 chan);
int16 UI_ADC_GetAdcResult(void);
void UI_ADC_SetOffset(int32 offset);
void UI_ADC_SetResolution(uint8 resolution);
void UI_ADC_SetScaledGain(int32 adcGain);
int32 UI_ADC_CountsTo_mVolts(int16 adcCounts);
int32 UI_ADC_CountsTo_uVolts(int16 adcCounts);
float32 UI_ADC_CountsTo_Volts(int16 adcCounts);
void UI_ADC_Sleep(void);
void UI_ADC_Wakeup(void);
void UI_ADC_SaveConfig(void);
void UI_ADC_RestoreConfig(void);

CY_ISR_PROTO( UI_ADC_ISR );

/* Obsolete API for backward compatibility.
*  Should not be used in new designs.
*/
void UI_ADC_SetGain(int32 adcGain);


/**************************************
*    Initial Parameter Constants
**************************************/
#define UI_ADC_IRQ_REMOVE             (0u)                /* Removes internal interrupt */


/***************************************
*             Registers
***************************************/
#define UI_ADC_CYCLE_COUNTER_AUX_CONTROL_REG \
                                               (*(reg8 *) UI_ADC_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define UI_ADC_CYCLE_COUNTER_AUX_CONTROL_PTR \
                                               ( (reg8 *) UI_ADC_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define UI_ADC_CONTROL_REG    (*(reg8 *) \
                                             UI_ADC_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define UI_ADC_CONTROL_PTR    ( (reg8 *) \
                                             UI_ADC_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define UI_ADC_COUNT_REG      (*(reg8 *) \
                                             UI_ADC_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define UI_ADC_COUNT_PTR      ( (reg8 *) \
                                             UI_ADC_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define UI_ADC_STATUS_REG     (*(reg8 *) UI_ADC_bSAR_SEQ_EOCSts__STATUS_REG)
#define UI_ADC_STATUS_PTR     ( (reg8 *) UI_ADC_bSAR_SEQ_EOCSts__STATUS_REG)

#define UI_ADC_SAR_DATA_ADDR_0 (UI_ADC_SAR_ADC_SAR__WRK0)
#define UI_ADC_SAR_DATA_ADDR_1 (UI_ADC_SAR_ADC_SAR__WRK1)
#define UI_ADC_SAR_DATA_ADDR_0_REG (*(reg8 *) \
                                              UI_ADC_SAR_ADC_SAR__WRK0)
#define UI_ADC_SAR_DATA_ADDR_1_REG (*(reg8 *) \
                                              UI_ADC_SAR_ADC_SAR__WRK1)


/**************************************
*       Register Constants
**************************************/

#if(UI_ADC_IRQ_REMOVE == 0u)

    /* Priority of the ADC_SAR_IRQ interrupt. */
    #define UI_ADC_INTC_PRIOR_NUMBER          (uint8)(UI_ADC_IRQ__INTC_PRIOR_NUM)

    /* ADC_SAR_IRQ interrupt number */
    #define UI_ADC_INTC_NUMBER                (uint8)(UI_ADC_IRQ__INTC_NUMBER)

#endif   /* End UI_ADC_IRQ_REMOVE */


/***************************************
*       API Constants
***************************************/

/* Constants for IsEndConversion() "retMode" parameter */
#define UI_ADC_RETURN_STATUS              (0x01u)
#define UI_ADC_WAIT_FOR_RESULT            (0x00u)

/* Defines for the Resolution parameter */
#define UI_ADC_BITS_12    UI_ADC_SAR__BITS_12
#define UI_ADC_BITS_10    UI_ADC_SAR__BITS_10
#define UI_ADC_BITS_8     UI_ADC_SAR__BITS_8

#define UI_ADC_CYCLE_COUNTER_ENABLE    (0x20u)
#define UI_ADC_BASE_COMPONENT_ENABLE   (0x01u)
#define UI_ADC_LOAD_COUNTER_PERIOD     (0x02u)
#define UI_ADC_SOFTWARE_SOC_PULSE      (0x04u)

/* Generic DMA Configuration parameters */
#define UI_ADC_TEMP_BYTES_PER_BURST     (uint8)(2u)
#define UI_ADC_TEMP_TRANSFER_COUNT      ((uint16)UI_ADC_NUMBER_OF_CHANNELS << 1u)
#define UI_ADC_FINAL_BYTES_PER_BURST    ((uint16)UI_ADC_NUMBER_OF_CHANNELS << 1u)
#define UI_ADC_REQUEST_PER_BURST        (uint8)(1u)

#define UI_ADC_GET_RESULT_INDEX_OFFSET    ((uint8)UI_ADC_NUMBER_OF_CHANNELS - 1u)

/* Define for Sample Mode  */
#define UI_ADC_SAMPLE_MODE_FREE_RUNNING    (0x00u)
#define UI_ADC_SAMPLE_MODE_SW_TRIGGERED    (0x01u)
#define UI_ADC_SAMPLE_MODE_HW_TRIGGERED    (0x02u)

/* Define for Clock Source  */
#define UI_ADC_CLOCK_INTERNAL              (0x00u)
#define UI_ADC_CLOCK_EXTERNAL              (0x01u)


/***************************************
*        Optional Function Prototypes
***************************************/
#if(UI_ADC_SAMPLE_MODE != UI_ADC_SAMPLE_MODE_HW_TRIGGERED)
    void UI_ADC_StartConvert(void);
    void UI_ADC_StopConvert(void);
#endif /* UI_ADC_SAMPLE_MODE != UI_ADC_SAMPLE_MODE_HW_TRIGGERED */

#endif  /* !defined(CY_UI_ADC_H) */

/* [] END OF FILE */
