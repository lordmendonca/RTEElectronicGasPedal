/*******************************************************************************
* File Name: brakePedal.h  
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

#if !defined(CY_PINS_brakePedal_H) /* Pins brakePedal_H */
#define CY_PINS_brakePedal_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "brakePedal_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 brakePedal__PORT == 15 && ((brakePedal__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    brakePedal_Write(uint8 value);
void    brakePedal_SetDriveMode(uint8 mode);
uint8   brakePedal_ReadDataReg(void);
uint8   brakePedal_Read(void);
void    brakePedal_SetInterruptMode(uint16 position, uint16 mode);
uint8   brakePedal_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the brakePedal_SetDriveMode() function.
     *  @{
     */
        #define brakePedal_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define brakePedal_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define brakePedal_DM_RES_UP          PIN_DM_RES_UP
        #define brakePedal_DM_RES_DWN         PIN_DM_RES_DWN
        #define brakePedal_DM_OD_LO           PIN_DM_OD_LO
        #define brakePedal_DM_OD_HI           PIN_DM_OD_HI
        #define brakePedal_DM_STRONG          PIN_DM_STRONG
        #define brakePedal_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define brakePedal_MASK               brakePedal__MASK
#define brakePedal_SHIFT              brakePedal__SHIFT
#define brakePedal_WIDTH              1u

/* Interrupt constants */
#if defined(brakePedal__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in brakePedal_SetInterruptMode() function.
     *  @{
     */
        #define brakePedal_INTR_NONE      (uint16)(0x0000u)
        #define brakePedal_INTR_RISING    (uint16)(0x0001u)
        #define brakePedal_INTR_FALLING   (uint16)(0x0002u)
        #define brakePedal_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define brakePedal_INTR_MASK      (0x01u) 
#endif /* (brakePedal__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define brakePedal_PS                     (* (reg8 *) brakePedal__PS)
/* Data Register */
#define brakePedal_DR                     (* (reg8 *) brakePedal__DR)
/* Port Number */
#define brakePedal_PRT_NUM                (* (reg8 *) brakePedal__PRT) 
/* Connect to Analog Globals */                                                  
#define brakePedal_AG                     (* (reg8 *) brakePedal__AG)                       
/* Analog MUX bux enable */
#define brakePedal_AMUX                   (* (reg8 *) brakePedal__AMUX) 
/* Bidirectional Enable */                                                        
#define brakePedal_BIE                    (* (reg8 *) brakePedal__BIE)
/* Bit-mask for Aliased Register Access */
#define brakePedal_BIT_MASK               (* (reg8 *) brakePedal__BIT_MASK)
/* Bypass Enable */
#define brakePedal_BYP                    (* (reg8 *) brakePedal__BYP)
/* Port wide control signals */                                                   
#define brakePedal_CTL                    (* (reg8 *) brakePedal__CTL)
/* Drive Modes */
#define brakePedal_DM0                    (* (reg8 *) brakePedal__DM0) 
#define brakePedal_DM1                    (* (reg8 *) brakePedal__DM1)
#define brakePedal_DM2                    (* (reg8 *) brakePedal__DM2) 
/* Input Buffer Disable Override */
#define brakePedal_INP_DIS                (* (reg8 *) brakePedal__INP_DIS)
/* LCD Common or Segment Drive */
#define brakePedal_LCD_COM_SEG            (* (reg8 *) brakePedal__LCD_COM_SEG)
/* Enable Segment LCD */
#define brakePedal_LCD_EN                 (* (reg8 *) brakePedal__LCD_EN)
/* Slew Rate Control */
#define brakePedal_SLW                    (* (reg8 *) brakePedal__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define brakePedal_PRTDSI__CAPS_SEL       (* (reg8 *) brakePedal__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define brakePedal_PRTDSI__DBL_SYNC_IN    (* (reg8 *) brakePedal__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define brakePedal_PRTDSI__OE_SEL0        (* (reg8 *) brakePedal__PRTDSI__OE_SEL0) 
#define brakePedal_PRTDSI__OE_SEL1        (* (reg8 *) brakePedal__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define brakePedal_PRTDSI__OUT_SEL0       (* (reg8 *) brakePedal__PRTDSI__OUT_SEL0) 
#define brakePedal_PRTDSI__OUT_SEL1       (* (reg8 *) brakePedal__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define brakePedal_PRTDSI__SYNC_OUT       (* (reg8 *) brakePedal__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(brakePedal__SIO_CFG)
    #define brakePedal_SIO_HYST_EN        (* (reg8 *) brakePedal__SIO_HYST_EN)
    #define brakePedal_SIO_REG_HIFREQ     (* (reg8 *) brakePedal__SIO_REG_HIFREQ)
    #define brakePedal_SIO_CFG            (* (reg8 *) brakePedal__SIO_CFG)
    #define brakePedal_SIO_DIFF           (* (reg8 *) brakePedal__SIO_DIFF)
#endif /* (brakePedal__SIO_CFG) */

/* Interrupt Registers */
#if defined(brakePedal__INTSTAT)
    #define brakePedal_INTSTAT            (* (reg8 *) brakePedal__INTSTAT)
    #define brakePedal_SNAP               (* (reg8 *) brakePedal__SNAP)
    
	#define brakePedal_0_INTTYPE_REG 		(* (reg8 *) brakePedal__0__INTTYPE)
#endif /* (brakePedal__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_brakePedal_H */


/* [] END OF FILE */
