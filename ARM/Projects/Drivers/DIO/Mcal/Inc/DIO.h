/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  DIO
 *
 *  Description:  header file for DIO Driver    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"
#include "Std_Types.h"
#include "DIO_Types.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define GPIO_REG(GPIO_BASE,REG_OFF)       *((volatile uint32*)(GPIO_BASE + REG_OFF))



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
void GPIO_EnableClock(DIO_PortType portID);

/******************************************************************************
* \Syntax          : DIO_LevelType Dio_ReadChannel(DIO_ChannelType channelID)                                     
* \Description     : Read the value of specific channel (pin in port)                                                                                                         
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : DIO_ChannelType channelID                     
* \Parameters (out): None                                                      
* \Return value:   : DIO_LevelType
*******************************************************************************/

DIO_LevelType Dio_ReadChannel(DIO_ChannelType channelID);



/******************************************************************************
* \Syntax          : void Dio_WriteChannel(DIO_ChannelType channelID, DIO_LevelType level)                                   
* \Description     : write value in specific channel (pin in port)                                                                                                         
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : DIO_ChannelType channelID, DIO_LevelType level                  
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Dio_WriteChannel(DIO_ChannelType channelID, DIO_LevelType level);



/******************************************************************************
* \Syntax          : DIO_PortLevelType Dio_ReadPort(DIO_PortType portID)                                
* \Description     : Read the value of specific Port                                                                                                      
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : DIO_PortType portID                  
* \Parameters (out): None                                                      
* \Return value:   : DIO_PortLevelType  {0 - 255}
*******************************************************************************/

DIO_PortLevelType Dio_ReadPort(DIO_PortType portID);



/******************************************************************************
* \Syntax          : void Dio_WritePort(DIO_PortType portID, DIO_PortLevelType level )                                   
* \Description     : write value on specific port                                                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : DIO_PortType portID, DIO_PortLevelType level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Dio_WritePort(DIO_PortType portID, DIO_PortLevelType level );



/******************************************************************************
* \Syntax          : DIO_LevelType Dio_FlipChannel(DIO_ChannelType channelID)                                   
* \Description     : toggle the value of specific channel (pin in port)                                                                                                         
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : DIO_ChannelType channelID                  
* \Parameters (out): None                                                      
* \Return value:   : DIO_LevelType
*******************************************************************************/

DIO_LevelType Dio_FlipChannel(DIO_ChannelType channelID);







#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/
