/*******************************************************************************
* File Name: OSShutdown.h  
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

#if !defined(CY_PINS_OSShutdown_H) /* Pins OSShutdown_H */
#define CY_PINS_OSShutdown_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OSShutdown_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OSShutdown__PORT == 15 && ((OSShutdown__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    OSShutdown_Write(uint8 value);
void    OSShutdown_SetDriveMode(uint8 mode);
uint8   OSShutdown_ReadDataReg(void);
uint8   OSShutdown_Read(void);
void    OSShutdown_SetInterruptMode(uint16 position, uint16 mode);
uint8   OSShutdown_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the OSShutdown_SetDriveMode() function.
     *  @{
     */
        #define OSShutdown_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define OSShutdown_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define OSShutdown_DM_RES_UP          PIN_DM_RES_UP
        #define OSShutdown_DM_RES_DWN         PIN_DM_RES_DWN
        #define OSShutdown_DM_OD_LO           PIN_DM_OD_LO
        #define OSShutdown_DM_OD_HI           PIN_DM_OD_HI
        #define OSShutdown_DM_STRONG          PIN_DM_STRONG
        #define OSShutdown_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define OSShutdown_MASK               OSShutdown__MASK
#define OSShutdown_SHIFT              OSShutdown__SHIFT
#define OSShutdown_WIDTH              1u

/* Interrupt constants */
#if defined(OSShutdown__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in OSShutdown_SetInterruptMode() function.
     *  @{
     */
        #define OSShutdown_INTR_NONE      (uint16)(0x0000u)
        #define OSShutdown_INTR_RISING    (uint16)(0x0001u)
        #define OSShutdown_INTR_FALLING   (uint16)(0x0002u)
        #define OSShutdown_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define OSShutdown_INTR_MASK      (0x01u) 
#endif /* (OSShutdown__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OSShutdown_PS                     (* (reg8 *) OSShutdown__PS)
/* Data Register */
#define OSShutdown_DR                     (* (reg8 *) OSShutdown__DR)
/* Port Number */
#define OSShutdown_PRT_NUM                (* (reg8 *) OSShutdown__PRT) 
/* Connect to Analog Globals */                                                  
#define OSShutdown_AG                     (* (reg8 *) OSShutdown__AG)                       
/* Analog MUX bux enable */
#define OSShutdown_AMUX                   (* (reg8 *) OSShutdown__AMUX) 
/* Bidirectional Enable */                                                        
#define OSShutdown_BIE                    (* (reg8 *) OSShutdown__BIE)
/* Bit-mask for Aliased Register Access */
#define OSShutdown_BIT_MASK               (* (reg8 *) OSShutdown__BIT_MASK)
/* Bypass Enable */
#define OSShutdown_BYP                    (* (reg8 *) OSShutdown__BYP)
/* Port wide control signals */                                                   
#define OSShutdown_CTL                    (* (reg8 *) OSShutdown__CTL)
/* Drive Modes */
#define OSShutdown_DM0                    (* (reg8 *) OSShutdown__DM0) 
#define OSShutdown_DM1                    (* (reg8 *) OSShutdown__DM1)
#define OSShutdown_DM2                    (* (reg8 *) OSShutdown__DM2) 
/* Input Buffer Disable Override */
#define OSShutdown_INP_DIS                (* (reg8 *) OSShutdown__INP_DIS)
/* LCD Common or Segment Drive */
#define OSShutdown_LCD_COM_SEG            (* (reg8 *) OSShutdown__LCD_COM_SEG)
/* Enable Segment LCD */
#define OSShutdown_LCD_EN                 (* (reg8 *) OSShutdown__LCD_EN)
/* Slew Rate Control */
#define OSShutdown_SLW                    (* (reg8 *) OSShutdown__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OSShutdown_PRTDSI__CAPS_SEL       (* (reg8 *) OSShutdown__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OSShutdown_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OSShutdown__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OSShutdown_PRTDSI__OE_SEL0        (* (reg8 *) OSShutdown__PRTDSI__OE_SEL0) 
#define OSShutdown_PRTDSI__OE_SEL1        (* (reg8 *) OSShutdown__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OSShutdown_PRTDSI__OUT_SEL0       (* (reg8 *) OSShutdown__PRTDSI__OUT_SEL0) 
#define OSShutdown_PRTDSI__OUT_SEL1       (* (reg8 *) OSShutdown__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OSShutdown_PRTDSI__SYNC_OUT       (* (reg8 *) OSShutdown__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(OSShutdown__SIO_CFG)
    #define OSShutdown_SIO_HYST_EN        (* (reg8 *) OSShutdown__SIO_HYST_EN)
    #define OSShutdown_SIO_REG_HIFREQ     (* (reg8 *) OSShutdown__SIO_REG_HIFREQ)
    #define OSShutdown_SIO_CFG            (* (reg8 *) OSShutdown__SIO_CFG)
    #define OSShutdown_SIO_DIFF           (* (reg8 *) OSShutdown__SIO_DIFF)
#endif /* (OSShutdown__SIO_CFG) */

/* Interrupt Registers */
#if defined(OSShutdown__INTSTAT)
    #define OSShutdown_INTSTAT            (* (reg8 *) OSShutdown__INTSTAT)
    #define OSShutdown_SNAP               (* (reg8 *) OSShutdown__SNAP)
    
	#define OSShutdown_0_INTTYPE_REG 		(* (reg8 *) OSShutdown__0__INTTYPE)
#endif /* (OSShutdown__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OSShutdown_H */


/* [] END OF FILE */
