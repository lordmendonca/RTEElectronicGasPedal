/*******************************************************************************
* File Name: testWDT.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_testWDT_H) /* Pins testWDT_H */
#define CY_PINS_testWDT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "testWDT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 testWDT__PORT == 15 && ((testWDT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    testWDT_Write(uint8 value);
void    testWDT_SetDriveMode(uint8 mode);
uint8   testWDT_ReadDataReg(void);
uint8   testWDT_Read(void);
void    testWDT_SetInterruptMode(uint16 position, uint16 mode);
uint8   testWDT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the testWDT_SetDriveMode() function.
     *  @{
     */
        #define testWDT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define testWDT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define testWDT_DM_RES_UP          PIN_DM_RES_UP
        #define testWDT_DM_RES_DWN         PIN_DM_RES_DWN
        #define testWDT_DM_OD_LO           PIN_DM_OD_LO
        #define testWDT_DM_OD_HI           PIN_DM_OD_HI
        #define testWDT_DM_STRONG          PIN_DM_STRONG
        #define testWDT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define testWDT_MASK               testWDT__MASK
#define testWDT_SHIFT              testWDT__SHIFT
#define testWDT_WIDTH              1u

/* Interrupt constants */
#if defined(testWDT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in testWDT_SetInterruptMode() function.
     *  @{
     */
        #define testWDT_INTR_NONE      (uint16)(0x0000u)
        #define testWDT_INTR_RISING    (uint16)(0x0001u)
        #define testWDT_INTR_FALLING   (uint16)(0x0002u)
        #define testWDT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define testWDT_INTR_MASK      (0x01u) 
#endif /* (testWDT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define testWDT_PS                     (* (reg8 *) testWDT__PS)
/* Data Register */
#define testWDT_DR                     (* (reg8 *) testWDT__DR)
/* Port Number */
#define testWDT_PRT_NUM                (* (reg8 *) testWDT__PRT) 
/* Connect to Analog Globals */                                                  
#define testWDT_AG                     (* (reg8 *) testWDT__AG)                       
/* Analog MUX bux enable */
#define testWDT_AMUX                   (* (reg8 *) testWDT__AMUX) 
/* Bidirectional Enable */                                                        
#define testWDT_BIE                    (* (reg8 *) testWDT__BIE)
/* Bit-mask for Aliased Register Access */
#define testWDT_BIT_MASK               (* (reg8 *) testWDT__BIT_MASK)
/* Bypass Enable */
#define testWDT_BYP                    (* (reg8 *) testWDT__BYP)
/* Port wide control signals */                                                   
#define testWDT_CTL                    (* (reg8 *) testWDT__CTL)
/* Drive Modes */
#define testWDT_DM0                    (* (reg8 *) testWDT__DM0) 
#define testWDT_DM1                    (* (reg8 *) testWDT__DM1)
#define testWDT_DM2                    (* (reg8 *) testWDT__DM2) 
/* Input Buffer Disable Override */
#define testWDT_INP_DIS                (* (reg8 *) testWDT__INP_DIS)
/* LCD Common or Segment Drive */
#define testWDT_LCD_COM_SEG            (* (reg8 *) testWDT__LCD_COM_SEG)
/* Enable Segment LCD */
#define testWDT_LCD_EN                 (* (reg8 *) testWDT__LCD_EN)
/* Slew Rate Control */
#define testWDT_SLW                    (* (reg8 *) testWDT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define testWDT_PRTDSI__CAPS_SEL       (* (reg8 *) testWDT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define testWDT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) testWDT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define testWDT_PRTDSI__OE_SEL0        (* (reg8 *) testWDT__PRTDSI__OE_SEL0) 
#define testWDT_PRTDSI__OE_SEL1        (* (reg8 *) testWDT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define testWDT_PRTDSI__OUT_SEL0       (* (reg8 *) testWDT__PRTDSI__OUT_SEL0) 
#define testWDT_PRTDSI__OUT_SEL1       (* (reg8 *) testWDT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define testWDT_PRTDSI__SYNC_OUT       (* (reg8 *) testWDT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(testWDT__SIO_CFG)
    #define testWDT_SIO_HYST_EN        (* (reg8 *) testWDT__SIO_HYST_EN)
    #define testWDT_SIO_REG_HIFREQ     (* (reg8 *) testWDT__SIO_REG_HIFREQ)
    #define testWDT_SIO_CFG            (* (reg8 *) testWDT__SIO_CFG)
    #define testWDT_SIO_DIFF           (* (reg8 *) testWDT__SIO_DIFF)
#endif /* (testWDT__SIO_CFG) */

/* Interrupt Registers */
#if defined(testWDT__INTSTAT)
    #define testWDT_INTSTAT            (* (reg8 *) testWDT__INTSTAT)
    #define testWDT_SNAP               (* (reg8 *) testWDT__SNAP)
    
	#define testWDT_0_INTTYPE_REG 		(* (reg8 *) testWDT__0__INTTYPE)
#endif /* (testWDT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_testWDT_H */


/* [] END OF FILE */
