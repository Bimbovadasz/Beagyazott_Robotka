/*******************************************************************************
* File Name: RIGHT_MOT_PWM.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RIGHT_MOT_PWM_ALIASES_H) /* Pins RIGHT_MOT_PWM_ALIASES_H */
#define CY_PINS_RIGHT_MOT_PWM_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define RIGHT_MOT_PWM_0			(RIGHT_MOT_PWM__0__PC)
#define RIGHT_MOT_PWM_0_INTR	((uint16)((uint16)0x0001u << RIGHT_MOT_PWM__0__SHIFT))

#define RIGHT_MOT_PWM_INTR_ALL	 ((uint16)(RIGHT_MOT_PWM_0_INTR))

#endif /* End Pins RIGHT_MOT_PWM_ALIASES_H */


/* [] END OF FILE */
