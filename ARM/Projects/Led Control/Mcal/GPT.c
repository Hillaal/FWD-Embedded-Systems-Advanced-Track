/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT.c
 *        \brief  General Purpose Timer Driver
 *
 *      \details Driver configure all general purpose timers in the microcontroller
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPT.h"

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
typedef void(*FnPtr)(void);

static const uint32 TIMERS_baseAddress[12] = {TIMER0,TIMER1,TIMER2,TIMER3,TIMER4,TIMER5,\
                                                TIMER0_WIDE,TIMER1_WIDE,TIMER2_WIDE,TIMER3_WIDE,TIMER4_WIDE,TIMER5_WIDE};


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void GPT_Init()                                   
* \Description     : initialize configurations of GPIO pins                                                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/


void GPT_Init(void)
{
    uint8 timerID ;
    uint8 counter;

    for(counter=0; counter < NUM_OF_TIMERS; counter++)
    {

        timerID = ((uint8) GPT_ConfigParam[counter].GptChannelId) % 6 ;

        if (GPT_ConfigParam[counter].GptChannelId < 6){
            RCGCTIMER |= (1 << timerID);
        }

        else{
            RCGCWTIMER |= (1<<timerID);
        }

        TIMER_REG(TIMERS_baseAddress[GPT_ConfigParam[counter].GptChannelId],GPTMCTL) &= ~(1 << 0); //disable Timer A

        TIMER_REG(TIMERS_baseAddress[GPT_ConfigParam[counter].GptChannelId],GPTMCFG) = 0x00000000;  // NO concatenation

        TIMER_REG(TIMERS_baseAddress[GPT_ConfigParam[counter].GptChannelId],GPTMTAMR) &= ~(0x03);       // mode one shot or periodic
        TIMER_REG(TIMERS_baseAddress[GPT_ConfigParam[counter].GptChannelId],GPTMTAMR) |= GPT_ConfigParam[counter].GptChannelMode;

        

        TIMER_REG(TIMERS_baseAddress[GPT_ConfigParam[counter].GptChannelId],GPTMTAPR) =  GPT_ConfigParam[counter].GptChannelTickFrequency - 1 ;    //setting frequency

				TIMER_REG(TIMERS_baseAddress[GPT_ConfigParam[counter].GptChannelId],GPTMICR) |= (1<<0);
    }
}   




/******************************************************************************
* \Syntax          : void GPT_DisableNotification(GPT_ChannelType channel)                                  
* \Description     : Disable interrupts of general purpose timers                                                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/


void GPT_DisableNotification(GPT_ChannelType channel){
    TIMER_REG(TIMERS_baseAddress[channel],GPTMIMR) &= ~(0x00010F1F);     //Disable all interrupts    
}




/******************************************************************************
* \Syntax          : void GPT_EnableNotification(GPT_ChannelType channel)                                 
* \Description     : Enable interrupts of general purpose timers                                                                                                       
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/


void GPT_EnableNotification(GPT_ChannelType channel){

    TIMER_REG(TIMERS_baseAddress[channel],GPTMIMR) |= (1 << 0);     //Enable timeout interrupt for Timer A
}



/******************************************************************************
* \Syntax          : void GPT_StartTimer(GPT_ChannelType channel, GPT_ValueType value)                                  
* \Description     : start timers with given value to count to                                                                                                      
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel,  GPT_ValueType value            
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/


void GPT_StartTimer(GPT_ChannelType channel, GPT_ValueType value){
    TIMER_REG(TIMERS_baseAddress[channel],GPTMTAILR) = value;   //counting value
		TIMER_REG(TIMERS_baseAddress[channel],GPTMICR) |= (1<<0);   //clearFlag of timer A
    TIMER_REG(TIMERS_baseAddress[channel],GPTMCTL) |= (1 << 0); //Enable Timer A
}





/******************************************************************************
* \Syntax          :void GPT_StopTimer(GPT_ChannelType channel)                               
* \Description     : stop timer                                                                                                     
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel         
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/


void GPT_StopTimer(GPT_ChannelType channel){
    TIMER_REG(TIMERS_baseAddress[channel],GPTMCTL) &= ~(1UL << 0); //Disable Timer A
}







/******************************************************************************
* \Syntax          : GPT_ValueType GPT_GetTimeElapsed(GPT_ChannelType channel)                                  
* \Description     : get time elapsed from starting timer                                                                                                       
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel                  
* \Parameters (out): None                                                      
* \Return value:   : GPT_ValueType
*******************************************************************************/

GPT_ValueType GPT_GetTimeElapsed(GPT_ChannelType channel){
    return ( (TIMER_REG(TIMERS_baseAddress[channel],GPTMTAILR)) - (TIMER_REG(TIMERS_baseAddress[channel],GPTMTAV)) );   //return remaining counts
}



/******************************************************************************
* \Syntax          : GPT_ValueType GPT_GetTimeRemaining(GPT_ChannelType channel)                                  
* \Description     : get time remaining tell timer overflow                                                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel                  
* \Parameters (out): None                                                      
* \Return value:   : GPT_ValueType
*******************************************************************************/



GPT_ValueType GPT_GetTimeRemaining(GPT_ChannelType channel){
    return TIMER_REG(TIMERS_baseAddress[channel],GPTMTAV);   //return current count
}





TIMER0A_Handler(){

	TIMER_REG(TIMERS_baseAddress[0],GPTMICR) |= (1<<0);   //clearFlag of timer A
    GPT_ConfigParam[0].GptNotification();   //call the callback function

}


TIMER1A_Handler(){

	TIMER_REG(TIMERS_baseAddress[1],GPTMICR) |= (1<<0);   //clearFlag of timer A
    GPT_ConfigParam[0].GptNotification();       //call the callback function

}

WTIMER0A_Handler(){

	TIMER_REG(TIMERS_baseAddress[6],GPTMICR) |= (1<<0);   //clearFlag of timer A
    GPT_ConfigParam[0].GptNotification();            //call the callback function

}

WTIMER1A_Handler(){

	TIMER_REG(TIMERS_baseAddress[7],GPTMICR) |= (1<<0);   //clearFlag of timer A
    GPT_ConfigParam[0].GptNotification();       //call the callback function

}

/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/
