/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define PORT_PortLevelType   uint8

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/





typedef enum
{
    PORT_CHANNEL_A0,     //0
    PORT_CHANNEL_A1,
    PORT_CHANNEL_A2,
    PORT_CHANNEL_A3,
    PORT_CHANNEL_A4,
    PORT_CHANNEL_A5,
    PORT_CHANNEL_A6,
    PORT_CHANNEL_A7,

    PORT_CHANNEL_B0,     //8
    PORT_CHANNEL_B1,
    PORT_CHANNEL_B2,
    PORT_CHANNEL_B3,
    PORT_CHANNEL_B4,
    PORT_CHANNEL_B5,
    PORT_CHANNEL_B6,
    PORT_CHANNEL_B7,

    PORT_CHANNEL_C0,     //16
    PORT_CHANNEL_C1,
    PORT_CHANNEL_C2,
    PORT_CHANNEL_C3,
    PORT_CHANNEL_C4,
    PORT_CHANNEL_C5,
    PORT_CHANNEL_C6,
    PORT_CHANNEL_C7,

    PORT_CHANNEL_D0,     //24
    PORT_CHANNEL_D1,
    PORT_CHANNEL_D2,
    PORT_CHANNEL_D3,
    PORT_CHANNEL_D4,
    PORT_CHANNEL_D5,
    PORT_CHANNEL_D6,
    PORT_CHANNEL_D7,

    PORT_CHANNEL_E0,     //32
    PORT_CHANNEL_E1,
    PORT_CHANNEL_E2,
    PORT_CHANNEL_E3,
    PORT_CHANNEL_E4,
    PORT_CHANNEL_E5,

    PORT_CHANNEL_F0 = 40,     //38
    PORT_CHANNEL_F1,
    PORT_CHANNEL_F2,
    PORT_CHANNEL_F3,
    PORT_CHANNEL_F4

}PORT_ChannelType;



typedef enum
{
 
}PORT_PinDirectionType;



typedef enum
{
 
}PORT_PinModeType;


typedef enum
{
 
}PORT_PinInternalAttachType;



typedef enum
{
 
}PORT_PinOutputCurrentType;


 
#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT_Types.h
 *********************************************************************************************************************/
