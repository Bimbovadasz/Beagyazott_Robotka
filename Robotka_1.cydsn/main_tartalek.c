/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

//create states
typedef enum{
    idle_state,
    sense_line,
    set_speed,
    go_straight,
    turn_left,
    turn_right,
}states;

//create events
typedef enum{
    no_line,
    line_on_right,
    line_on_left,
}events;

//define eventhandler functions
states IdleState(void){
    return idle_state;
}

states SenseLine(void){
    return sense_line;
}

states SetSpeed(void){
    return set_speed;
}

states GoStraight(void){
    return go_straight;
}

states TurnLeft(void){
    return turn_left;
}

states TurnRight(void){
    return turn_right;
}

void setSpeeds(int16 left, int16 right){
   int8 killControl = 0;
    if(left<0){
        LEFT_MOT_PWM_WriteCompare(-1*left);
        LEFT_MOT_DIR_Write(1);
    }else{
        LEFT_MOT_PWM_WriteCompare(left);
        LEFT_MOT_DIR_Write(0);
    }
    if(right<0){
        RIGHT_MOT_PWM_WriteCompare(-1*right);
        RIGHT_MOT_DIR_Write(1);
    }else{
        RIGHT_MOT_PWM_WriteCompare(right);
        RIGHT_MOT_DIR_Write(0);
    }
    if(left==0){
        killControl=1;
    }
    if(right==0){
        killControl=killControl+2;
    }
    Reg_PWM_Write(killControl);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    states defineState = idle_state;
    LEFT_MOT_PWM_Start();
    RIGHT_MOT_PWM_Start();
    setSpeeds(0,0);
    for(;;){
        //allapotok
        switch(defineState){
            case go_straight:
                setSpeeds(100,100);
                break;
            case turn_left:
                setSpeeds(100,-50);
                break;
            case turn_right:
                setSpeeds(-50,100);
                break;
            default:
                setSpeeds(0,0);
                break;
        }
        //kiertekeles
        CyDelay(100);
        if((IR_L_Read() == 0 && IR_R_Read() == 0) || (IR_L_Read() ==1 && IR_R_Read() == 1)){
            defineState = go_straight;
        }
        if(IR_R_Read() == 1){
            defineState = turn_right;
        }
        if(IR_L_Read() == 1){
            defineState = turn_left;
        }
    }
}

/* [] END OF FILE */
