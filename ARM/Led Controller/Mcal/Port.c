/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  Port Driver
 *
 *      \details  The Driver Configure All port pins in the microcontroller
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port.h"

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

static const uint32 GPIO_baseAddress[6] = {GPIO_PORT_A,GPIO_PORT_B,GPIO_PORT_C,GPIO_PORT_D,GPIO_PORT_E,GPIO_PORT_F};


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Port_Init(const Port_ConfigType* configPtr)                                   
* \Description     : initialize configurations of GPIO pins                                                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : const Port_ConfigType* configPtr                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/



void Port_Init(void){
    uint8 counter;
    uint32 port_id;
    uint32 pin_id;

    for(counter = 0; counter < NUM_OF_CHANNELS ; counter++){

        port_id = ( (uint32)(PORT_ConfigParam[counter].channelID) / 8);
        pin_id = ( (uint32)(PORT_ConfigParam[counter].channelID) % 8);



        /* enable clock */
        RCGCGPIO |= ( 1U << port_id); 
				while(!(RCGCGPIO & ( 1U << port_id))){}
        /*unlock the commit*/
        
        GPIO_REG(GPIO_baseAddress[port_id],GPIOLOCK) = LOCK;
        GPIO_REG(GPIO_baseAddress[port_id],GPIOCR) |= (1<< pin_id); 


        /*setting mode*/
        switch(PORT_ConfigParam[counter].mode){
            case PORT_PIN_MODE_DIO:{
                GPIO_REG(GPIO_baseAddress[port_id],GPIODEN) &= ~(1U << pin_id); //clear Pin before inserting value
                GPIO_REG(GPIO_baseAddress[port_id],GPIODEN) |= (1<< pin_id);  //inserting value
                break;
            }
        }


        /* setting Direction */

        GPIO_REG(GPIO_baseAddress[port_id],GPIODIR) &= ~(1U << pin_id); //clear Pin direction before inserting 
        GPIO_REG(GPIO_baseAddress[port_id],GPIODIR) |= ( (uint32) PORT_ConfigParam[counter].direction << pin_id);    //writing the direction



       

        /*setting internal attach*/
        switch (PORT_ConfigParam[counter].internalAttach)
        {
        case PORT_INTERNAL_ATTACH_PULLUP:
            GPIO_REG(GPIO_baseAddress[port_id],GPIOPUR) |= (1<< pin_id);  //inserting value
            break;
        case PORT_INTERNAL_ATTACH_PULLDOWN:
            GPIO_REG(GPIO_baseAddress[port_id],GPIOPDR) |= (1<< pin_id);  //inserting value
            break;
        case PORT_INTERNAL_ATTACH_OPENDRAIN:
            GPIO_REG(GPIO_baseAddress[port_id],GPIOODR) |= (1<< pin_id);  //inserting value
            break;
        case PORT_INTERNAL_ATTACH_PUSHPULL:
            break;            
        }



         /*setting current*/
        switch (PORT_ConfigParam[counter].outputCurrent)
        {
        case PORT_PIN_OUTPUT_CURRENT_2MA:
            GPIO_REG(GPIO_baseAddress[port_id],GPIODR2R) |= (1<< pin_id);  //inserting value
            break;

        case PORT_PIN_OUTPUT_CURRENT_4MA:
            GPIO_REG(GPIO_baseAddress[port_id],GPIODR4R) |= (1<< pin_id);  //inserting value
            break;

        case PORT_PIN_OUTPUT_CURRENT_8MA:
            GPIO_REG(GPIO_baseAddress[port_id],GPIODR8R) |= (1<< pin_id);  //inserting value
            break;
        }
        

    }
    

}







/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
