/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT.h
 *       Module:  GPT
 *
 *  Description:  header file for GPT Driver    
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"
#include "Std_Types.h"
#include "GPT_Types.h"
#include "GPT_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define TIMER_REG(TIMER_BASE,REG_OFF)       *((volatile uint32*)(TIMER_BASE + REG_OFF))



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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

void GPT_Init(void);



/******************************************************************************
* \Syntax          : void GPT_DisableNotification(GPT_ChannelType channel)                                  
* \Description     : Disable interrupts of general purpose timers                                                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void GPT_DisableNotification(GPT_ChannelType channel);


/******************************************************************************
* \Syntax          : void GPT_EnableNotification(GPT_ChannelType channel)                                 
* \Description     : Enable interrupts of general purpose timers                                                                                                       
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void GPT_EnableNotification(GPT_ChannelType channel);



/******************************************************************************
* \Syntax          : void GPT_StartTimer(GPT_ChannelType channel, GPT_ValueType value)                                  
* \Description     : start timers with given value to count to                                                                                                      
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel,  GPT_ValueType value            
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void GPT_StartTimer(GPT_ChannelType channel, GPT_ValueType value);



/******************************************************************************
* \Syntax          :void GPT_StopTimer(GPT_ChannelType channel)                               
* \Description     : stop timer                                                                                                     
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel         
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void GPT_StopTimer(GPT_ChannelType channel);



/******************************************************************************
* \Syntax          : GPT_ValueType GPT_GetTimeElapsed(GPT_ChannelType channel)                                  
* \Description     : get time elapsed from starting timer                                                                                                       
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel                  
* \Parameters (out): None                                                      
* \Return value:   : GPT_ValueType
*******************************************************************************/

GPT_ValueType GPT_GetTimeElapsed(GPT_ChannelType channel);



/******************************************************************************
* \Syntax          : GPT_ValueType GPT_GetTimeRemaining(GPT_ChannelType channel)                                  
* \Description     : get time remaining tell timer overflow                                                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : GPT_ChannelType channel                  
* \Parameters (out): None                                                      
* \Return value:   : GPT_ValueType
*******************************************************************************/

GPT_ValueType GPT_GetTimeRemaining(GPT_ChannelType channel);



#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT.h
 *********************************************************************************************************************/
