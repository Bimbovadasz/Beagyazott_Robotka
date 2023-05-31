/*******************************************************************************
* File Name: KILL.h  
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

#if !defined(CY_PINS_KILL_H) /* Pins KILL_H */
#define CY_PINS_KILL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KILL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 KILL__PORT == 15 && ((KILL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    KILL_Write(uint8 value);
void    KILL_SetDriveMode(uint8 mode);
uint8   KILL_ReadDataReg(void);
uint8   KILL_Read(void);
void    KILL_SetInterruptMode(uint16 position, uint16 mode);
uint8   KILL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the KILL_SetDriveMode() function.
     *  @{
     */
        #define KILL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define KILL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define KILL_DM_RES_UP          PIN_DM_RES_UP
        #define KILL_DM_RES_DWN         PIN_DM_RES_DWN
        #define KILL_DM_OD_LO           PIN_DM_OD_LO
        #define KILL_DM_OD_HI           PIN_DM_OD_HI
        #define KILL_DM_STRONG          PIN_DM_STRONG
        #define KILL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define KILL_MASK               KILL__MASK
#define KILL_SHIFT              KILL__SHIFT
#define KILL_WIDTH              1u

/* Interrupt constants */
#if defined(KILL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in KILL_SetInterruptMode() function.
     *  @{
     */
        #define KILL_INTR_NONE      (uint16)(0x0000u)
        #define KILL_INTR_RISING    (uint16)(0x0001u)
        #define KILL_INTR_FALLING   (uint16)(0x0002u)
        #define KILL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define KILL_INTR_MASK      (0x01u) 
#endif /* (KILL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KILL_PS                     (* (reg8 *) KILL__PS)
/* Data Register */
#define KILL_DR                     (* (reg8 *) KILL__DR)
/* Port Number */
#define KILL_PRT_NUM                (* (reg8 *) KILL__PRT) 
/* Connect to Analog Globals */                                                  
#define KILL_AG                     (* (reg8 *) KILL__AG)                       
/* Analog MUX bux enable */
#define KILL_AMUX                   (* (reg8 *) KILL__AMUX) 
/* Bidirectional Enable */                                                        
#define KILL_BIE                    (* (reg8 *) KILL__BIE)
/* Bit-mask for Aliased Register Access */
#define KILL_BIT_MASK               (* (reg8 *) KILL__BIT_MASK)
/* Bypass Enable */
#define KILL_BYP                    (* (reg8 *) KILL__BYP)
/* Port wide control signals */                                                   
#define KILL_CTL                    (* (reg8 *) KILL__CTL)
/* Drive Modes */
#define KILL_DM0                    (* (reg8 *) KILL__DM0) 
#define KILL_DM1                    (* (reg8 *) KILL__DM1)
#define KILL_DM2                    (* (reg8 *) KILL__DM2) 
/* Input Buffer Disable Override */
#define KILL_INP_DIS                (* (reg8 *) KILL__INP_DIS)
/* LCD Common or Segment Drive */
#define KILL_LCD_COM_SEG            (* (reg8 *) KILL__LCD_COM_SEG)
/* Enable Segment LCD */
#define KILL_LCD_EN                 (* (reg8 *) KILL__LCD_EN)
/* Slew Rate Control */
#define KILL_SLW                    (* (reg8 *) KILL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KILL_PRTDSI__CAPS_SEL       (* (reg8 *) KILL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KILL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KILL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KILL_PRTDSI__OE_SEL0        (* (reg8 *) KILL__PRTDSI__OE_SEL0) 
#define KILL_PRTDSI__OE_SEL1        (* (reg8 *) KILL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KILL_PRTDSI__OUT_SEL0       (* (reg8 *) KILL__PRTDSI__OUT_SEL0) 
#define KILL_PRTDSI__OUT_SEL1       (* (reg8 *) KILL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KILL_PRTDSI__SYNC_OUT       (* (reg8 *) KILL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(KILL__SIO_CFG)
    #define KILL_SIO_HYST_EN        (* (reg8 *) KILL__SIO_HYST_EN)
    #define KILL_SIO_REG_HIFREQ     (* (reg8 *) KILL__SIO_REG_HIFREQ)
    #define KILL_SIO_CFG            (* (reg8 *) KILL__SIO_CFG)
    #define KILL_SIO_DIFF           (* (reg8 *) KILL__SIO_DIFF)
#endif /* (KILL__SIO_CFG) */

/* Interrupt Registers */
#if defined(KILL__INTSTAT)
    #define KILL_INTSTAT            (* (reg8 *) KILL__INTSTAT)
    #define KILL_SNAP               (* (reg8 *) KILL__SNAP)
    
	#define KILL_0_INTTYPE_REG 		(* (reg8 *) KILL__0__INTTYPE)
#endif /* (KILL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_KILL_H */


/* [] END OF FILE */
