/*******************************************************************************
* File Name: RIGHT_MOT_CMTRL.h  
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

#if !defined(CY_PINS_RIGHT_MOT_CMTRL_H) /* Pins RIGHT_MOT_CMTRL_H */
#define CY_PINS_RIGHT_MOT_CMTRL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RIGHT_MOT_CMTRL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RIGHT_MOT_CMTRL__PORT == 15 && ((RIGHT_MOT_CMTRL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RIGHT_MOT_CMTRL_Write(uint8 value);
void    RIGHT_MOT_CMTRL_SetDriveMode(uint8 mode);
uint8   RIGHT_MOT_CMTRL_ReadDataReg(void);
uint8   RIGHT_MOT_CMTRL_Read(void);
void    RIGHT_MOT_CMTRL_SetInterruptMode(uint16 position, uint16 mode);
uint8   RIGHT_MOT_CMTRL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RIGHT_MOT_CMTRL_SetDriveMode() function.
     *  @{
     */
        #define RIGHT_MOT_CMTRL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RIGHT_MOT_CMTRL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RIGHT_MOT_CMTRL_DM_RES_UP          PIN_DM_RES_UP
        #define RIGHT_MOT_CMTRL_DM_RES_DWN         PIN_DM_RES_DWN
        #define RIGHT_MOT_CMTRL_DM_OD_LO           PIN_DM_OD_LO
        #define RIGHT_MOT_CMTRL_DM_OD_HI           PIN_DM_OD_HI
        #define RIGHT_MOT_CMTRL_DM_STRONG          PIN_DM_STRONG
        #define RIGHT_MOT_CMTRL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RIGHT_MOT_CMTRL_MASK               RIGHT_MOT_CMTRL__MASK
#define RIGHT_MOT_CMTRL_SHIFT              RIGHT_MOT_CMTRL__SHIFT
#define RIGHT_MOT_CMTRL_WIDTH              1u

/* Interrupt constants */
#if defined(RIGHT_MOT_CMTRL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RIGHT_MOT_CMTRL_SetInterruptMode() function.
     *  @{
     */
        #define RIGHT_MOT_CMTRL_INTR_NONE      (uint16)(0x0000u)
        #define RIGHT_MOT_CMTRL_INTR_RISING    (uint16)(0x0001u)
        #define RIGHT_MOT_CMTRL_INTR_FALLING   (uint16)(0x0002u)
        #define RIGHT_MOT_CMTRL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RIGHT_MOT_CMTRL_INTR_MASK      (0x01u) 
#endif /* (RIGHT_MOT_CMTRL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RIGHT_MOT_CMTRL_PS                     (* (reg8 *) RIGHT_MOT_CMTRL__PS)
/* Data Register */
#define RIGHT_MOT_CMTRL_DR                     (* (reg8 *) RIGHT_MOT_CMTRL__DR)
/* Port Number */
#define RIGHT_MOT_CMTRL_PRT_NUM                (* (reg8 *) RIGHT_MOT_CMTRL__PRT) 
/* Connect to Analog Globals */                                                  
#define RIGHT_MOT_CMTRL_AG                     (* (reg8 *) RIGHT_MOT_CMTRL__AG)                       
/* Analog MUX bux enable */
#define RIGHT_MOT_CMTRL_AMUX                   (* (reg8 *) RIGHT_MOT_CMTRL__AMUX) 
/* Bidirectional Enable */                                                        
#define RIGHT_MOT_CMTRL_BIE                    (* (reg8 *) RIGHT_MOT_CMTRL__BIE)
/* Bit-mask for Aliased Register Access */
#define RIGHT_MOT_CMTRL_BIT_MASK               (* (reg8 *) RIGHT_MOT_CMTRL__BIT_MASK)
/* Bypass Enable */
#define RIGHT_MOT_CMTRL_BYP                    (* (reg8 *) RIGHT_MOT_CMTRL__BYP)
/* Port wide control signals */                                                   
#define RIGHT_MOT_CMTRL_CTL                    (* (reg8 *) RIGHT_MOT_CMTRL__CTL)
/* Drive Modes */
#define RIGHT_MOT_CMTRL_DM0                    (* (reg8 *) RIGHT_MOT_CMTRL__DM0) 
#define RIGHT_MOT_CMTRL_DM1                    (* (reg8 *) RIGHT_MOT_CMTRL__DM1)
#define RIGHT_MOT_CMTRL_DM2                    (* (reg8 *) RIGHT_MOT_CMTRL__DM2) 
/* Input Buffer Disable Override */
#define RIGHT_MOT_CMTRL_INP_DIS                (* (reg8 *) RIGHT_MOT_CMTRL__INP_DIS)
/* LCD Common or Segment Drive */
#define RIGHT_MOT_CMTRL_LCD_COM_SEG            (* (reg8 *) RIGHT_MOT_CMTRL__LCD_COM_SEG)
/* Enable Segment LCD */
#define RIGHT_MOT_CMTRL_LCD_EN                 (* (reg8 *) RIGHT_MOT_CMTRL__LCD_EN)
/* Slew Rate Control */
#define RIGHT_MOT_CMTRL_SLW                    (* (reg8 *) RIGHT_MOT_CMTRL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RIGHT_MOT_CMTRL_PRTDSI__CAPS_SEL       (* (reg8 *) RIGHT_MOT_CMTRL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RIGHT_MOT_CMTRL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RIGHT_MOT_CMTRL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RIGHT_MOT_CMTRL_PRTDSI__OE_SEL0        (* (reg8 *) RIGHT_MOT_CMTRL__PRTDSI__OE_SEL0) 
#define RIGHT_MOT_CMTRL_PRTDSI__OE_SEL1        (* (reg8 *) RIGHT_MOT_CMTRL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RIGHT_MOT_CMTRL_PRTDSI__OUT_SEL0       (* (reg8 *) RIGHT_MOT_CMTRL__PRTDSI__OUT_SEL0) 
#define RIGHT_MOT_CMTRL_PRTDSI__OUT_SEL1       (* (reg8 *) RIGHT_MOT_CMTRL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RIGHT_MOT_CMTRL_PRTDSI__SYNC_OUT       (* (reg8 *) RIGHT_MOT_CMTRL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RIGHT_MOT_CMTRL__SIO_CFG)
    #define RIGHT_MOT_CMTRL_SIO_HYST_EN        (* (reg8 *) RIGHT_MOT_CMTRL__SIO_HYST_EN)
    #define RIGHT_MOT_CMTRL_SIO_REG_HIFREQ     (* (reg8 *) RIGHT_MOT_CMTRL__SIO_REG_HIFREQ)
    #define RIGHT_MOT_CMTRL_SIO_CFG            (* (reg8 *) RIGHT_MOT_CMTRL__SIO_CFG)
    #define RIGHT_MOT_CMTRL_SIO_DIFF           (* (reg8 *) RIGHT_MOT_CMTRL__SIO_DIFF)
#endif /* (RIGHT_MOT_CMTRL__SIO_CFG) */

/* Interrupt Registers */
#if defined(RIGHT_MOT_CMTRL__INTSTAT)
    #define RIGHT_MOT_CMTRL_INTSTAT            (* (reg8 *) RIGHT_MOT_CMTRL__INTSTAT)
    #define RIGHT_MOT_CMTRL_SNAP               (* (reg8 *) RIGHT_MOT_CMTRL__SNAP)
    
	#define RIGHT_MOT_CMTRL_0_INTTYPE_REG 		(* (reg8 *) RIGHT_MOT_CMTRL__0__INTTYPE)
#endif /* (RIGHT_MOT_CMTRL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RIGHT_MOT_CMTRL_H */


/* [] END OF FILE */
