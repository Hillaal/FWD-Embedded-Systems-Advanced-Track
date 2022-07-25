/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define DIO_PortLevelType   uint8

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/





typedef enum
{
    DIO_CHANNEL_A0,     //0
    DIO_CHANNEL_A1,
    DIO_CHANNEL_A2,
    DIO_CHANNEL_A3,
    DIO_CHANNEL_A4,
    DIO_CHANNEL_A5,
    DIO_CHANNEL_A6,
    DIO_CHANNEL_A7,

    DIO_CHANNEL_B0,     //8
    DIO_CHANNEL_B1,
    DIO_CHANNEL_B2,
    DIO_CHANNEL_B3,
    DIO_CHANNEL_B4,
    DIO_CHANNEL_B5,
    DIO_CHANNEL_B6,
    DIO_CHANNEL_B7,

    DIO_CHANNEL_C0,     //16
    DIO_CHANNEL_C1,
    DIO_CHANNEL_C2,
    DIO_CHANNEL_C3,
    DIO_CHANNEL_C4,
    DIO_CHANNEL_C5,
    DIO_CHANNEL_C6,
    DIO_CHANNEL_C7,

    DIO_CHANNEL_D0,     //24
    DIO_CHANNEL_D1,
    DIO_CHANNEL_D2,
    DIO_CHANNEL_D3,
    DIO_CHANNEL_D4,
    DIO_CHANNEL_D5,
    DIO_CHANNEL_D6,
    DIO_CHANNEL_D7,

    DIO_CHANNEL_E0,     //32
    DIO_CHANNEL_E1,
    DIO_CHANNEL_E2,
    DIO_CHANNEL_E3,
    DIO_CHANNEL_E4,
    DIO_CHANNEL_E5,

    DIO_CHANNEL_F0 = 40,     //38
    DIO_CHANNEL_F1,
    DIO_CHANNEL_F2,
    DIO_CHANNEL_F3,
    DIO_CHANNEL_F4

}DIO_ChannelType;



typedef enum
{
   DIO_PORTA,
   DIO_PORTB,
   DIO_PORTC,
   DIO_PORTD,
   DIO_PORTE,
   DIO_PORTF

}DIO_PortType;


typedef enum
{
    DIO_LOW = 0,
    DIO_HIGH = 1

}DIO_LevelType;



 
#endif  /* DIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO_Types.h
 *********************************************************************************************************************/
