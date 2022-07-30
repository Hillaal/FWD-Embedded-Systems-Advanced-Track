/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  contain Types related to the Interrupt control driver     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define XXX     (0x00)
#define XXY     (0x05)
#define XYY     (0x06)
#define YYY     (0x07)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/





typedef enum
{
   INT_CTRL_GPIO_PORT_A = 0,
    INT_CTRL_GPIO_PORT_B = 1,
    INT_CTRL_GPIO_PORT_C = 2,
    INT_CTRL_GPIO_PORT_D = 3,
    INT_CTRL_GPIO_PORT_E = 4,
    INT_CTRL_UART0 = 5,
    INT_CTRL_UART1 = 6,
    INT_CTRL_SSI0 = 7,
    INT_CTRL_I2C0 = 8,
    INT_CTRL_PWM0_FAULT = 9,
    INT_CTRL_PWM0_GENERATOR_0 = 10,
    INT_CTRL_PWM0_GENERATOR_1 = 11,
    INT_CTRL_PWM0_GENERATOR_2 = 12,
    INT_CTRL_QEI0 = 13,
    INT_CTRL_ADC0_SEQUENCE_0 = 14,
    INT_CTRL_ADC0_SEQUENCE_1 = 15,
    INT_CTRL_ADC0_SEQUENCE_2 = 16,
    INT_CTRL_ADC0_SEQUENCE_3 = 17,
    INT_CTRL_WATCHDOG_TIMERS_0_AND_1 = 18,
    INT_CTRL_16_32_BIT_TIMER_0A = 19,
    INT_CTRL_16_32_BIT_TIMER_0B = 20,
    INT_CTRL_16_32_BIT_TIMER_1A = 21,
    INT_CTRL_16_32_BIT_TIMER_1B = 22,
    INT_CTRL_16_32_BIT_TIMER_2A = 23,
    INT_CTRL_16_32_BIT_TIMER_2B = 24,
    INT_CTRL_ANALOG_COMPARATOR_0 = 25,
    INT_CTRL_ANALOG_COMPARATOR_1 = 26,
    INT_CTRL_SYSTEM_CONTROL = 28,
    INT_CTRL_FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL = 29,
    INT_CTRL_GPIO_PORT_F = 30,
    INT_CTRL_UART2 = 33,
    INT_CTRL_SSI1 = 34,
    INT_CTRL_16_32_BIT_TIMER_3A = 35,
    INT_CTRL_16_32_BIT_TIMER_3B = 36,
    INT_CTRL_I2C1 = 37,
    INT_CTRL_QEI1 = 38,
    INT_CTRL_CAN0 = 39,
    INT_CTRL_CAN1 = 40,
    INT_CTRL_HIBERNATION_MODULE = 43,
    INT_CTRL_USB = 44,
    INT_CTRL_PWM_GENERATOR_3 = 45,
    INT_CTRL_UDMA_SOFTWARE = 46,
    INT_CTRL_UDMA_ERROR = 47,
    INT_CTRL_ADC1_SEQUENCE_0 = 48,
    INT_CTRL_ADC1_SEQUENCE_1 = 49,
    INT_CTRL_ADC1_SEQUENCE_2 = 50,
    INT_CTRL_ADC1_SEQUENCE_3 = 51,
    INT_CTRL_SSI2 = 57,
    INT_CTRL_SSI3 = 58,
    INT_CTRL_UART3 = 59,
    INT_CTRL_UART4 = 60,
    INT_CTRL_UART5 = 61,
    INT_CTRL_UART6 = 62,
    INT_CTRL_UART7 = 63,
    INT_CTRL_I2C2 = 68,
    INT_CTRL_I2C3 = 69,
    INT_CTRL_16_32_BIT_TIMER_4A = 70,
    INT_CTRL_16_32_BIT_TIMER_4B = 71,
    INT_CTRL_16_32_BIT_TIMER_5A = 92,
    INT_CTRL_16_32_BIT_TIMER_5B = 93,
    INT_CTRL_32_64_BIT_TIMER_0A = 94,
    INT_CTRL_32_64_BIT_TIMER_0B = 95,
    INT_CTRL_32_64_BIT_TIMER_1A = 96,
    INT_CTRL_32_64_BIT_TIMER_1B = 97,
    INT_CTRL_32_64_BIT_TIMER_2A = 98,
    INT_CTRL_32_64_BIT_TIMER_2B = 99,
    INT_CTRL_32_64_BIT_TIMER_3A = 110,
    INT_CTRL_32_64_BIT_TIMER_3B = 101,
    INT_CTRL_32_64_BIT_TIMER_4A = 102,
    INT_CTRL_32_64_BIT_TIMER_4B = 103,
    INT_CTRL_32_64_BIT_TIMER_5A = 104,
    INT_CTRL_32_64_BIT_TIMER_5B = 105,
    INT_CTRL_SYSTEM_EXCEPTION = 106,
    INT_CTRL_PWM1_GENERATOR_0 = 134,
    INT_CTRL_PWM1_GENERATOR_1 = 135,
    INT_CTRL_PWM1_GENERATOR_2 = 136,
    INT_CTRL_PWM1_GENERATOR_3 = 137,
    INT_CTRL_PWM1_FAULT = 138

}IntCtrl_InterruptType;

 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
