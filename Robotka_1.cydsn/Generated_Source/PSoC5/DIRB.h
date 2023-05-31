/*******************************************************************************
* File Name: DIRB.h  
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

#if !defined(CY_PINS_DIRB_H) /* Pins DIRB_H */
#define CY_PINS_DIRB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIRB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DIRB__PORT == 15 && ((DIRB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DIRB_Write(uint8 value);
void    DIRB_SetDriveMode(uint8 mode);
uint8   DIRB_ReadDataReg(void);
uint8   DIRB_Read(void);
void    DIRB_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIRB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DIRB_SetDriveMode() function.
     *  @{
     */
        #define DIRB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DIRB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DIRB_DM_RES_UP          PIN_DM_RES_UP
        #define DIRB_DM_RES_DWN         PIN_DM_RES_DWN
        #define DIRB_DM_OD_LO           PIN_DM_OD_LO
        #define DIRB_DM_OD_HI           PIN_DM_OD_HI
        #define DIRB_DM_STRONG          PIN_DM_STRONG
        #define DIRB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DIRB_MASK               DIRB__MASK
#define DIRB_SHIFT              DIRB__SHIFT
#define DIRB_WIDTH              1u

/* Interrupt constants */
#if defined(DIRB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIRB_SetInterruptMode() function.
     *  @{
     */
        #define DIRB_INTR_NONE      (uint16)(0x0000u)
        #define DIRB_INTR_RISING    (uint16)(0x0001u)
        #define DIRB_INTR_FALLING   (uint16)(0x0002u)
        #define DIRB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DIRB_INTR_MASK      (0x01u) 
#endif /* (DIRB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIRB_PS                     (* (reg8 *) DIRB__PS)
/* Data Register */
#define DIRB_DR                     (* (reg8 *) DIRB__DR)
/* Port Number */
#define DIRB_PRT_NUM                (* (reg8 *) DIRB__PRT) 
/* Connect to Analog Globals */                                                  
#define DIRB_AG                     (* (reg8 *) DIRB__AG)                       
/* Analog MUX bux enable */
#define DIRB_AMUX                   (* (reg8 *) DIRB__AMUX) 
/* Bidirectional Enable */                                                        
#define DIRB_BIE                    (* (reg8 *) DIRB__BIE)
/* Bit-mask for Aliased Register Access */
#define DIRB_BIT_MASK               (* (reg8 *) DIRB__BIT_MASK)
/* Bypass Enable */
#define DIRB_BYP                    (* (reg8 *) DIRB__BYP)
/* Port wide control signals */                                                   
#define DIRB_CTL                    (* (reg8 *) DIRB__CTL)
/* Drive Modes */
#define DIRB_DM0                    (* (reg8 *) DIRB__DM0) 
#define DIRB_DM1                    (* (reg8 *) DIRB__DM1)
#define DIRB_DM2                    (* (reg8 *) DIRB__DM2) 
/* Input Buffer Disable Override */
#define DIRB_INP_DIS                (* (reg8 *) DIRB__INP_DIS)
/* LCD Common or Segment Drive */
#define DIRB_LCD_COM_SEG            (* (reg8 *) DIRB__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIRB_LCD_EN                 (* (reg8 *) DIRB__LCD_EN)
/* Slew Rate Control */
#define DIRB_SLW                    (* (reg8 *) DIRB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIRB_PRTDSI__CAPS_SEL       (* (reg8 *) DIRB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIRB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIRB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIRB_PRTDSI__OE_SEL0        (* (reg8 *) DIRB__PRTDSI__OE_SEL0) 
#define DIRB_PRTDSI__OE_SEL1        (* (reg8 *) DIRB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIRB_PRTDSI__OUT_SEL0       (* (reg8 *) DIRB__PRTDSI__OUT_SEL0) 
#define DIRB_PRTDSI__OUT_SEL1       (* (reg8 *) DIRB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIRB_PRTDSI__SYNC_OUT       (* (reg8 *) DIRB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DIRB__SIO_CFG)
    #define DIRB_SIO_HYST_EN        (* (reg8 *) DIRB__SIO_HYST_EN)
    #define DIRB_SIO_REG_HIFREQ     (* (reg8 *) DIRB__SIO_REG_HIFREQ)
    #define DIRB_SIO_CFG            (* (reg8 *) DIRB__SIO_CFG)
    #define DIRB_SIO_DIFF           (* (reg8 *) DIRB__SIO_DIFF)
#endif /* (DIRB__SIO_CFG) */

/* Interrupt Registers */
#if defined(DIRB__INTSTAT)
    #define DIRB_INTSTAT            (* (reg8 *) DIRB__INTSTAT)
    #define DIRB_SNAP               (* (reg8 *) DIRB__SNAP)
    
	#define DIRB_0_INTTYPE_REG 		(* (reg8 *) DIRB__0__INTTYPE)
#endif /* (DIRB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DIRB_H */


/* [] END OF FILE */
