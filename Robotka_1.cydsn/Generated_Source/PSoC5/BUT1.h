/*******************************************************************************
* File Name: BUT1.h  
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

#if !defined(CY_PINS_BUT1_H) /* Pins BUT1_H */
#define CY_PINS_BUT1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BUT1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BUT1__PORT == 15 && ((BUT1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BUT1_Write(uint8 value);
void    BUT1_SetDriveMode(uint8 mode);
uint8   BUT1_ReadDataReg(void);
uint8   BUT1_Read(void);
void    BUT1_SetInterruptMode(uint16 position, uint16 mode);
uint8   BUT1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BUT1_SetDriveMode() function.
     *  @{
     */
        #define BUT1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BUT1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BUT1_DM_RES_UP          PIN_DM_RES_UP
        #define BUT1_DM_RES_DWN         PIN_DM_RES_DWN
        #define BUT1_DM_OD_LO           PIN_DM_OD_LO
        #define BUT1_DM_OD_HI           PIN_DM_OD_HI
        #define BUT1_DM_STRONG          PIN_DM_STRONG
        #define BUT1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BUT1_MASK               BUT1__MASK
#define BUT1_SHIFT              BUT1__SHIFT
#define BUT1_WIDTH              1u

/* Interrupt constants */
#if defined(BUT1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BUT1_SetInterruptMode() function.
     *  @{
     */
        #define BUT1_INTR_NONE      (uint16)(0x0000u)
        #define BUT1_INTR_RISING    (uint16)(0x0001u)
        #define BUT1_INTR_FALLING   (uint16)(0x0002u)
        #define BUT1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BUT1_INTR_MASK      (0x01u) 
#endif /* (BUT1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BUT1_PS                     (* (reg8 *) BUT1__PS)
/* Data Register */
#define BUT1_DR                     (* (reg8 *) BUT1__DR)
/* Port Number */
#define BUT1_PRT_NUM                (* (reg8 *) BUT1__PRT) 
/* Connect to Analog Globals */                                                  
#define BUT1_AG                     (* (reg8 *) BUT1__AG)                       
/* Analog MUX bux enable */
#define BUT1_AMUX                   (* (reg8 *) BUT1__AMUX) 
/* Bidirectional Enable */                                                        
#define BUT1_BIE                    (* (reg8 *) BUT1__BIE)
/* Bit-mask for Aliased Register Access */
#define BUT1_BIT_MASK               (* (reg8 *) BUT1__BIT_MASK)
/* Bypass Enable */
#define BUT1_BYP                    (* (reg8 *) BUT1__BYP)
/* Port wide control signals */                                                   
#define BUT1_CTL                    (* (reg8 *) BUT1__CTL)
/* Drive Modes */
#define BUT1_DM0                    (* (reg8 *) BUT1__DM0) 
#define BUT1_DM1                    (* (reg8 *) BUT1__DM1)
#define BUT1_DM2                    (* (reg8 *) BUT1__DM2) 
/* Input Buffer Disable Override */
#define BUT1_INP_DIS                (* (reg8 *) BUT1__INP_DIS)
/* LCD Common or Segment Drive */
#define BUT1_LCD_COM_SEG            (* (reg8 *) BUT1__LCD_COM_SEG)
/* Enable Segment LCD */
#define BUT1_LCD_EN                 (* (reg8 *) BUT1__LCD_EN)
/* Slew Rate Control */
#define BUT1_SLW                    (* (reg8 *) BUT1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BUT1_PRTDSI__CAPS_SEL       (* (reg8 *) BUT1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BUT1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BUT1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BUT1_PRTDSI__OE_SEL0        (* (reg8 *) BUT1__PRTDSI__OE_SEL0) 
#define BUT1_PRTDSI__OE_SEL1        (* (reg8 *) BUT1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BUT1_PRTDSI__OUT_SEL0       (* (reg8 *) BUT1__PRTDSI__OUT_SEL0) 
#define BUT1_PRTDSI__OUT_SEL1       (* (reg8 *) BUT1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BUT1_PRTDSI__SYNC_OUT       (* (reg8 *) BUT1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BUT1__SIO_CFG)
    #define BUT1_SIO_HYST_EN        (* (reg8 *) BUT1__SIO_HYST_EN)
    #define BUT1_SIO_REG_HIFREQ     (* (reg8 *) BUT1__SIO_REG_HIFREQ)
    #define BUT1_SIO_CFG            (* (reg8 *) BUT1__SIO_CFG)
    #define BUT1_SIO_DIFF           (* (reg8 *) BUT1__SIO_DIFF)
#endif /* (BUT1__SIO_CFG) */

/* Interrupt Registers */
#if defined(BUT1__INTSTAT)
    #define BUT1_INTSTAT            (* (reg8 *) BUT1__INTSTAT)
    #define BUT1_SNAP               (* (reg8 *) BUT1__SNAP)
    
	#define BUT1_0_INTTYPE_REG 		(* (reg8 *) BUT1__0__INTTYPE)
#endif /* (BUT1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BUT1_H */


/* [] END OF FILE */
