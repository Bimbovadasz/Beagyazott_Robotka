/*******************************************************************************
* File Name: LEFT_MOT_PWM_PM.c
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

#include "LEFT_MOT_PWM.h"

static LEFT_MOT_PWM_backupStruct LEFT_MOT_PWM_backup;


/*******************************************************************************
* Function Name: LEFT_MOT_PWM_SaveConfig
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
*  LEFT_MOT_PWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void LEFT_MOT_PWM_SaveConfig(void) 
{

    #if(!LEFT_MOT_PWM_UsingFixedFunction)
        #if(!LEFT_MOT_PWM_PWMModeIsCenterAligned)
            LEFT_MOT_PWM_backup.PWMPeriod = LEFT_MOT_PWM_ReadPeriod();
        #endif /* (!LEFT_MOT_PWM_PWMModeIsCenterAligned) */
        LEFT_MOT_PWM_backup.PWMUdb = LEFT_MOT_PWM_ReadCounter();
        #if (LEFT_MOT_PWM_UseStatus)
            LEFT_MOT_PWM_backup.InterruptMaskValue = LEFT_MOT_PWM_STATUS_MASK;
        #endif /* (LEFT_MOT_PWM_UseStatus) */

        #if(LEFT_MOT_PWM_DeadBandMode == LEFT_MOT_PWM__B_PWM__DBM_256_CLOCKS || \
            LEFT_MOT_PWM_DeadBandMode == LEFT_MOT_PWM__B_PWM__DBM_2_4_CLOCKS)
            LEFT_MOT_PWM_backup.PWMdeadBandValue = LEFT_MOT_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(LEFT_MOT_PWM_KillModeMinTime)
             LEFT_MOT_PWM_backup.PWMKillCounterPeriod = LEFT_MOT_PWM_ReadKillTime();
        #endif /* (LEFT_MOT_PWM_KillModeMinTime) */

        #if(LEFT_MOT_PWM_UseControl)
            LEFT_MOT_PWM_backup.PWMControlRegister = LEFT_MOT_PWM_ReadControlRegister();
        #endif /* (LEFT_MOT_PWM_UseControl) */
    #endif  /* (!LEFT_MOT_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: LEFT_MOT_PWM_RestoreConfig
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
*  LEFT_MOT_PWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void LEFT_MOT_PWM_RestoreConfig(void) 
{
        #if(!LEFT_MOT_PWM_UsingFixedFunction)
            #if(!LEFT_MOT_PWM_PWMModeIsCenterAligned)
                LEFT_MOT_PWM_WritePeriod(LEFT_MOT_PWM_backup.PWMPeriod);
            #endif /* (!LEFT_MOT_PWM_PWMModeIsCenterAligned) */

            LEFT_MOT_PWM_WriteCounter(LEFT_MOT_PWM_backup.PWMUdb);

            #if (LEFT_MOT_PWM_UseStatus)
                LEFT_MOT_PWM_STATUS_MASK = LEFT_MOT_PWM_backup.InterruptMaskValue;
            #endif /* (LEFT_MOT_PWM_UseStatus) */

            #if(LEFT_MOT_PWM_DeadBandMode == LEFT_MOT_PWM__B_PWM__DBM_256_CLOCKS || \
                LEFT_MOT_PWM_DeadBandMode == LEFT_MOT_PWM__B_PWM__DBM_2_4_CLOCKS)
                LEFT_MOT_PWM_WriteDeadTime(LEFT_MOT_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(LEFT_MOT_PWM_KillModeMinTime)
                LEFT_MOT_PWM_WriteKillTime(LEFT_MOT_PWM_backup.PWMKillCounterPeriod);
            #endif /* (LEFT_MOT_PWM_KillModeMinTime) */

            #if(LEFT_MOT_PWM_UseControl)
                LEFT_MOT_PWM_WriteControlRegister(LEFT_MOT_PWM_backup.PWMControlRegister);
            #endif /* (LEFT_MOT_PWM_UseControl) */
        #endif  /* (!LEFT_MOT_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: LEFT_MOT_PWM_Sleep
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
*  LEFT_MOT_PWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void LEFT_MOT_PWM_Sleep(void) 
{
    #if(LEFT_MOT_PWM_UseControl)
        if(LEFT_MOT_PWM_CTRL_ENABLE == (LEFT_MOT_PWM_CONTROL & LEFT_MOT_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            LEFT_MOT_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            LEFT_MOT_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (LEFT_MOT_PWM_UseControl) */

    /* Stop component */
    LEFT_MOT_PWM_Stop();

    /* Save registers configuration */
    LEFT_MOT_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: LEFT_MOT_PWM_Wakeup
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
*  LEFT_MOT_PWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void LEFT_MOT_PWM_Wakeup(void) 
{
     /* Restore registers values */
    LEFT_MOT_PWM_RestoreConfig();

    if(LEFT_MOT_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        LEFT_MOT_PWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
