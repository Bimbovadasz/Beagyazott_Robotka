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
    go_straight,
    turn_left,
    turn_right,
}state;

//create events
typedef enum{
    no_line,
    line_on_right,
    line_on_left,
}event;

void SetSpeed(int16 left, int16 right){
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
        killControl = 1;
    }
    if(right==0){
        killControl = killControl+2;
    }
    Reg_PWM_Write(killControl);
}

event SetEvent(int16 left_IR, int16 right_IR){
    /*if((left_IR == 0 && right_IR == 0) || (left_IR == 1 && right_IR == 1)){
        return no_line;
    }*/
    if(right_IR == 1){
        return line_on_right;
    }
    if(left_IR == 1){
        return line_on_left;
    }else{
        return no_line;
    }
}
    
state SetState(event event){
    if(event == no_line){
        return go_straight;
    }
    if(event == line_on_right){
        return turn_right;
    }
    if(event == line_on_left){
        return turn_left;
    }
    else{
        return idle_state;
    }
}

uint32_t lastTime=0;
uint8_t isMyTimer(){
    uint32_t now = CySysTickGetValue();
    if(now-lastTime > 100){
        return 1;
    }
    return 0;
}

uint8_t isMyTimer2(){
    uint32_t now = CySysTickGetValue();
    if(now-lastTime > 5000){
        return 1;
    }
    return 0;
}

int main(void){
    CyGlobalIntEnable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    event cur_event = no_line;
    state cur_state = idle_state;
    int speed = 0;
    LEFT_MOT_PWM_Start();
    RIGHT_MOT_PWM_Start();
    ADC_SAR_1_Start();
    LCD_Char_1_Start();
    CySysTickStart();
    for(;;){
        if(isMyTimer2()){
        ADC_SAR_1_StartConvert();
        speed = ((ADC_SAR_1_GetResult16()/4095)*100);
        ADC_SAR_1_StopConvert();
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_PrintString("Speed: ");
        LCD_Char_1_PrintNumber(speed);
        CyDelay(200);
        }
        if(isMyTimer()){
            cur_event = SetEvent(IR_L_Read(), IR_R_Read());     
            cur_state = SetState(cur_event);
            switch(cur_state){
                case go_straight:
                    SetSpeed(speed,speed);
                    break;
                case turn_left:
                    SetSpeed(speed,-(speed/2));
                    break;
                case turn_right:
                    SetSpeed(-(speed/2),speed);
                    break;
                case idle_state:
                    SetSpeed(0,0);
                    break;
                default:
                    SetSpeed(0,0);
                    break;
            }
        }  
    }
}

/* [] END OF FILE */
