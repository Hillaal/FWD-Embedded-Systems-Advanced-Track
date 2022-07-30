/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  DIO driver
 *
 *      \details  The Driver Configure All DIO pins write/read/flip channels
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

static const uint32 GPIO_baseAddress[6] = {GPIO_PORT_A,GPIO_PORT_B,GPIO_PORT_C,GPIO_PORT_D,GPIO_PORT_E,GPIO_PORT_F};

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



/******************************************************************************
* \Syntax          : DIO_LevelType Dio_ReadChannel(DIO_ChannelType channelID)                                     
* \Description     : Read the value of specific channel (pin in port)                                                                                                         
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : DIO_ChannelType channelID                     
* \Parameters (out): None                                                      
* \Return value:   : DIO_LevelType
*******************************************************************************/

void GPIO_EnableClock(DIO_PortType portID){
    RCGCGPIO |= (1 << portID);
}



DIO_LevelType Dio_ReadChannel(DIO_ChannelType channelID){

    uint8 port_id = channelID / 8;
    uint8 pin_id = channelID % 8;

    return GPIO_REG( GPIO_baseAddress[port_id], GPIODATA + ( 1 << (2 + pin_id) ) );
}



/******************************************************************************
* \Syntax          : void Dio_WriteChannel(DIO_ChannelType channelID, DIO_LevelType level)                                   
* \Description     : write value in specific channel (pin in port)                                                                                                         
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : DIO_ChannelType channelID, DIO_LevelType level                  
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Dio_WriteChannel(DIO_ChannelType channelID, DIO_LevelType level){

    uint32 port_id = ((uint32) channelID) / 8;
    uint32 pin_id = ((uint32) channelID) % 8;

    //GPIO_REG( GPIO_baseAddress[port_id], GPIODATA + ( 1 << (2 + pin_id) ) ) =  (uint32)level << pin_id;
	
    GPIO_REG(GPIO_baseAddress[port_id], GPIODATA) =  1 << pin_id ;
}



/******************************************************************************
* \Syntax          : DIO_PortLevelType Dio_ReadPort(DIO_PortType portID)                                
* \Description     : Read the value of specific Port                                                                                                      
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : DIO_PortType portID                  
* \Parameters (out): None                                                      
* \Return value:   : DIO_PortLevelType  {0 - 255}
*******************************************************************************/

DIO_PortLevelType Dio_ReadPort(DIO_PortType portID){

    return GPIO_REG( GPIO_baseAddress[portID], GPIODATA + (255 <<2) );

}



/******************************************************************************
* \Syntax          : void Dio_WritePort(DIO_PortType portID, DIO_PortLevelType level )                                   
* \Description     : write value on specific port                                                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : DIO_PortType portID, DIO_PortLevelType level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Dio_WritePort(DIO_PortType portID, DIO_PortLevelType level){

    GPIO_REG( GPIO_baseAddress[portID], GPIODATA + (255 <<2) ) = level;

}



/******************************************************************************
* \Syntax          : DIO_LevelType Dio_FlipChannel(DIO_ChannelType channelID)                                   
* \Description     : toggle the value of specific channel (pin in port)                                                                                                         
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : DIO_ChannelType channelID                  
* \Parameters (out): None                                                      
* \Return value:   : DIO_LevelType
*******************************************************************************/

DIO_LevelType Dio_FlipChannel(DIO_ChannelType channelID){
    uint8 port_id = channelID / 8;
    uint8 pin_id = channelID % 8;
    uint8 current_level = GPIO_REG( GPIO_baseAddress[port_id], GPIODATA + ( 1 << (2 + pin_id) ) );
    
    GPIO_REG( GPIO_baseAddress[port_id], GPIODATA + ( 1 << (2 + pin_id) ) ) =  (1 ^ current_level) << pin_id;
	
		return ( (1 ^ current_level) << pin_id );
}







/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
