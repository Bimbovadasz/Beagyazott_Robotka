/*******************************************************************************
* File Name: DIRA.h  
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

#if !defined(CY_PINS_DIRA_H) /* Pins DIRA_H */
#define CY_PINS_DIRA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIRA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DIRA__PORT == 15 && ((DIRA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DIRA_Write(uint8 value);
void    DIRA_SetDriveMode(uint8 mode);
uint8   DIRA_ReadDataReg(void);
uint8   DIRA_Read(void);
void    DIRA_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIRA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DIRA_SetDriveMode() function.
     *  @{
     */
        #define DIRA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DIRA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DIRA_DM_RES_UP          PIN_DM_RES_UP
        #define DIRA_DM_RES_DWN         PIN_DM_RES_DWN
        #define DIRA_DM_OD_LO           PIN_DM_OD_LO
        #define DIRA_DM_OD_HI           PIN_DM_OD_HI
        #define DIRA_DM_STRONG          PIN_DM_STRONG
        #define DIRA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DIRA_MASK               DIRA__MASK
#define DIRA_SHIFT              DIRA__SHIFT
#define DIRA_WIDTH              1u

/* Interrupt constants */
#if defined(DIRA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIRA_SetInterruptMode() function.
     *  @{
     */
        #define DIRA_INTR_NONE      (uint16)(0x0000u)
        #define DIRA_INTR_RISING    (uint16)(0x0001u)
        #define DIRA_INTR_FALLING   (uint16)(0x0002u)
        #define DIRA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DIRA_INTR_MASK      (0x01u) 
#endif /* (DIRA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIRA_PS                     (* (reg8 *) DIRA__PS)
/* Data Register */
#define DIRA_DR                     (* (reg8 *) DIRA__DR)
/* Port Number */
#define DIRA_PRT_NUM                (* (reg8 *) DIRA__PRT) 
/* Connect to Analog Globals */                                                  
#define DIRA_AG                     (* (reg8 *) DIRA__AG)                       
/* Analog MUX bux enable */
#define DIRA_AMUX                   (* (reg8 *) DIRA__AMUX) 
/* Bidirectional Enable */                                                        
#define DIRA_BIE                    (* (reg8 *) DIRA__BIE)
/* Bit-mask for Aliased Register Access */
#define DIRA_BIT_MASK               (* (reg8 *) DIRA__BIT_MASK)
/* Bypass Enable */
#define DIRA_BYP                    (* (reg8 *) DIRA__BYP)
/* Port wide control signals */                                                   
#define DIRA_CTL                    (* (reg8 *) DIRA__CTL)
/* Drive Modes */
#define DIRA_DM0                    (* (reg8 *) DIRA__DM0) 
#define DIRA_DM1                    (* (reg8 *) DIRA__DM1)
#define DIRA_DM2                    (* (reg8 *) DIRA__DM2) 
/* Input Buffer Disable Override */
#define DIRA_INP_DIS                (* (reg8 *) DIRA__INP_DIS)
/* LCD Common or Segment Drive */
#define DIRA_LCD_COM_SEG            (* (reg8 *) DIRA__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIRA_LCD_EN                 (* (reg8 *) DIRA__LCD_EN)
/* Slew Rate Control */
#define DIRA_SLW                    (* (reg8 *) DIRA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIRA_PRTDSI__CAPS_SEL       (* (reg8 *) DIRA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIRA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIRA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIRA_PRTDSI__OE_SEL0        (* (reg8 *) DIRA__PRTDSI__OE_SEL0) 
#define DIRA_PRTDSI__OE_SEL1        (* (reg8 *) DIRA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIRA_PRTDSI__OUT_SEL0       (* (reg8 *) DIRA__PRTDSI__OUT_SEL0) 
#define DIRA_PRTDSI__OUT_SEL1       (* (reg8 *) DIRA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIRA_PRTDSI__SYNC_OUT       (* (reg8 *) DIRA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DIRA__SIO_CFG)
    #define DIRA_SIO_HYST_EN        (* (reg8 *) DIRA__SIO_HYST_EN)
    #define DIRA_SIO_REG_HIFREQ     (* (reg8 *) DIRA__SIO_REG_HIFREQ)
    #define DIRA_SIO_CFG            (* (reg8 *) DIRA__SIO_CFG)
    #define DIRA_SIO_DIFF           (* (reg8 *) DIRA__SIO_DIFF)
#endif /* (DIRA__SIO_CFG) */

/* Interrupt Registers */
#if defined(DIRA__INTSTAT)
    #define DIRA_INTSTAT            (* (reg8 *) DIRA__INTSTAT)
    #define DIRA_SNAP               (* (reg8 *) DIRA__SNAP)
    
	#define DIRA_0_INTTYPE_REG 		(* (reg8 *) DIRA__0__INTTYPE)
#endif /* (DIRA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DIRA_H */


/* [] END OF FILE */
