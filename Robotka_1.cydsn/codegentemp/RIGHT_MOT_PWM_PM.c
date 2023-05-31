/*******************************************************************************
* File Name: RIGHT_MOT_PWM_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "RIGHT_MOT_PWM.h"

static RIGHT_MOT_PWM_backupStruct RIGHT_MOT_PWM_backup;


/*******************************************************************************
* Function Name: RIGHT_MOT_PWM_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  RIGHT_MOT_PWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void RIGHT_MOT_PWM_SaveConfig(void) 
{

    #if(!RIGHT_MOT_PWM_UsingFixedFunction)
        #if(!RIGHT_MOT_PWM_PWMModeIsCenterAligned)
            RIGHT_MOT_PWM_backup.PWMPeriod = RIGHT_MOT_PWM_ReadPeriod();
        #endif /* (!RIGHT_MOT_PWM_PWMModeIsCenterAligned) */
        RIGHT_MOT_PWM_backup.PWMUdb = RIGHT_MOT_PWM_ReadCounter();
        #if (RIGHT_MOT_PWM_UseStatus)
            RIGHT_MOT_PWM_backup.InterruptMaskValue = RIGHT_MOT_PWM_STATUS_MASK;
        #endif /* (RIGHT_MOT_PWM_UseStatus) */

        #if(RIGHT_MOT_PWM_DeadBandMode == RIGHT_MOT_PWM__B_PWM__DBM_256_CLOCKS || \
            RIGHT_MOT_PWM_DeadBandMode == RIGHT_MOT_PWM__B_PWM__DBM_2_4_CLOCKS)
            RIGHT_MOT_PWM_backup.PWMdeadBandValue = RIGHT_MOT_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(RIGHT_MOT_PWM_KillModeMinTime)
             RIGHT_MOT_PWM_backup.PWMKillCounterPeriod = RIGHT_MOT_PWM_ReadKillTime();
        #endif /* (RIGHT_MOT_PWM_KillModeMinTime) */

        #if(RIGHT_MOT_PWM_UseControl)
            RIGHT_MOT_PWM_backup.PWMControlRegister = RIGHT_MOT_PWM_ReadControlRegister();
        #endif /* (RIGHT_MOT_PWM_UseControl) */
    #endif  /* (!RIGHT_MOT_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: RIGHT_MOT_PWM_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  RIGHT_MOT_PWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void RIGHT_MOT_PWM_RestoreConfig(void) 
{
        #if(!RIGHT_MOT_PWM_UsingFixedFunction)
            #if(!RIGHT_MOT_PWM_PWMModeIsCenterAligned)
                RIGHT_MOT_PWM_WritePeriod(RIGHT_MOT_PWM_backup.PWMPeriod);
            #endif /* (!RIGHT_MOT_PWM_PWMModeIsCenterAligned) */

            RIGHT_MOT_PWM_WriteCounter(RIGHT_MOT_PWM_backup.PWMUdb);

            #if (RIGHT_MOT_PWM_UseStatus)
                RIGHT_MOT_PWM_STATUS_MASK = RIGHT_MOT_PWM_backup.InterruptMaskValue;
            #endif /* (RIGHT_MOT_PWM_UseStatus) */

            #if(RIGHT_MOT_PWM_DeadBandMode == RIGHT_MOT_PWM__B_PWM__DBM_256_CLOCKS || \
                RIGHT_MOT_PWM_DeadBandMode == RIGHT_MOT_PWM__B_PWM__DBM_2_4_CLOCKS)
                RIGHT_MOT_PWM_WriteDeadTime(RIGHT_MOT_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(RIGHT_MOT_PWM_KillModeMinTime)
                RIGHT_MOT_PWM_WriteKillTime(RIGHT_MOT_PWM_backup.PWMKillCounterPeriod);
            #endif /* (RIGHT_MOT_PWM_KillModeMinTime) */

            #if(RIGHT_MOT_PWM_UseControl)
                RIGHT_MOT_PWM_WriteControlRegister(RIGHT_MOT_PWM_backup.PWMControlRegister);
            #endif /* (RIGHT_MOT_PWM_UseControl) */
        #endif  /* (!RIGHT_MOT_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: RIGHT_MOT_PWM_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  RIGHT_MOT_PWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void RIGHT_MOT_PWM_Sleep(void) 
{
    #if(RIGHT_MOT_PWM_UseControl)
        if(RIGHT_MOT_PWM_CTRL_ENABLE == (RIGHT_MOT_PWM_CONTROL & RIGHT_MOT_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            RIGHT_MOT_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            RIGHT_MOT_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (RIGHT_MOT_PWM_UseControl) */

    /* Stop component */
    RIGHT_MOT_PWM_Stop();

    /* Save registers configuration */
    RIGHT_MOT_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: RIGHT_MOT_PWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  RIGHT_MOT_PWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void RIGHT_MOT_PWM_Wakeup(void) 
{
     /* Restore registers values */
    RIGHT_MOT_PWM_RestoreConfig();

    if(RIGHT_MOT_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        RIGHT_MOT_PWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
