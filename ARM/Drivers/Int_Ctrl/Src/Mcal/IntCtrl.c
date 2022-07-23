/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{   uint8 counter = 0;
    uint8 priority;

    for (counter = 0; counter < NUM_OF_INTERRUPTS ; counter ++){

        #if(PRIORITY_COMBINATION == XXX)
            priority = (0x07) & IntCtrl_ConfigParam[counter].interruptPriority
;
        #elif(PRIORITY_COMBINATION == XXY);
            priority = (0x07) & ( (IntCtrl_ConfigParam[counter].interruptPriority << 1U) | (IntCtrl_ConfigParam[counter].interruptSubPriority << 0U) )

        #elif(PRIORITY_COMBINATION == XYY)
            priority = (0x07) & ( (IntCtrl_ConfigParam[counter].interruptPriority << 2U) | (IntCtrl_ConfigParam[counter].interruptSubPriority << 0U) )
        #else
            priority = (0x07) & IntCtrl_ConfigParam[counter].interruptSubPriority;
        #endif

        /*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/

        APINT = 0xFA050000 | ((0X07 & PRIORITY_COMBINATION) << 8);
        
        /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  


        NVIC->PRI[IntCtrl_ConfigParam[counter].interruptName / 4U] |= priority << ( (8*(IntCtrl_ConfigParam[counter].interruptName % 4U)) + 5 );

        /*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */

        NVIC->EN[IntCtrl_ConfigParam[counter].interruptName / 32U] |= (0x01 << ( IntCtrl_ConfigParam[counter].interruptName % 32U ));
        
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
