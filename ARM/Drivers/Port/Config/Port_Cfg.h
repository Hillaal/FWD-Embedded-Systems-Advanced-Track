/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Port.h"
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NUM_OF_CHANNELS ((uint8) 5 )


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
    PORT_ChannelType channelID;
    PORT_PinDirectionType direction;
    PORT_PinModeType mode;
    PORT_PinInternalAttachType internalAttach;
    PORT_PinOutputCurrentType outputCurrent;


}Port_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
extern const Port_ConfigType PORT_ConfigParam[NUM_OF_CHANNELS];
 
#endif  /* PORT_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT_Cfg.h
 *********************************************************************************************************************/
