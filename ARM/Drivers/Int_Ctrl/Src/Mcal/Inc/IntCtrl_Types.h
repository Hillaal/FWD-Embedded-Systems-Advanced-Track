/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
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
    INT_CTRL_PWM0_Fault = 9,
    INT_CTRL_PWM0_Generator_0 = 10,
    INT_CTRL_PWM0_Generator_1 = 11,
    INT_CTRL_PWM0_Generator_2 = 12,
    INT_CTRL_QEI0 = 13,
    INT_CTRL_ADC0_Sequence_0 = 14,
    INT_CTRL_ADC0_Sequence_1 = 15,
    INT_CTRL_ADC0_Sequence_2 = 16,
    INT_CTRL_ADC0_Sequence_3 = 17,
    INT_CTRL_Watchdog_Timers_0_and_1 = 18,
    INT_CTRL_16_32_Bit_Timer_0A = 19,
    INT_CTRL_16_32_Bit_TTimer_0B = 20,
    INT_CTRL_16_32_Bit_TTimer_1A = 21,
    INT_CTRL_16_32_Bit_TTimer_1B = 22,
    INT_CTRL_16_32_Bit_TTimer_2A = 23,
    INT_CTRL_16_32_Bit_TTimer_2B = 24,
    INT_CTRL_Analog_Comparator_0 = 25,
    INT_CTRL_Analog_Comparator_1 = 26,
    INT_CTRL_System_Control = 28,
    INT_CTRL_Flash_Memory_Control_and_EEPROM_Control = 0,
    INT_CTRL_GPIO_Port_F = 0,
    INT_CTRL_UART2 = 0,
    INT_CTRL_SSI1 = 0,
    INT_CTRL_16_32_Bit_TTimer_3A = 0,
    INT_CTRL_16_32_Bit_TTimer_3B = 0,
    INT_CTRL_I2C1 = 0,
    INT_CTRL_QEI1 = 0,
    INT_CTRL_CAN0 = 0,
    INT_CTRL_CAN1 = 0,
    INT_CTRL_Hibernation_Module = 0,
    INT_CTRL_USB = 0,
    INT_CTRL_PWM_Generator_3 = 0,
    INT_CTRL_uDMA_Software = 0,
    INT_CTRL_uDMA_error = 0,
    INT_CTRL_ADC1_Sequence_0 = 0,
    INT_CTRL_ADC1_Sequence_1 = 0,
    INT_CTRL_ADC1_Sequence_2 = 0,
    INT_CTRL_ADC1_Sequence_3 = 0,
    INT_CTRL_SSI2 = 0,
    INT_CTRL_SSI3 = 0,
    INT_CTRL_UART3 = 0,
    INT_CTRL_UART4 = 0,
    INT_CTRL_UART5 = 0,
    INT_CTRL_UART6 = 0,
    INT_CTRL_UART7 = 0,
    INT_CTRL_I2C2 = 0,
    INT_CTRL_I2C3 = 0,
    INT_CTRL_16_32_Bit_TTimer_4A = 0,
    INT_CTRL_16_32_Bit_TTimer_4B = 0,
    INT_CTRL_16_32_Bit_Timer_5A = 0,
    INT_CTRL_16_32_Bit_Timer_5B = 0,
    INT_CTRL_32_64_Bit_Timer_0A = 0,
    INT_CTRL_32_64_Bit_Timer_0B = 0,
    INT_CTRL_32_64_Bit_Timer_1A = 0,
    INT_CTRL_32_64_Bit_Timer_1B = 0,
    INT_CTRL_32_64_Bit_Timer_2A = 0,
    INT_CTRL_32_64_Bit_Timer_2B = 0,
    INT_CTRL_32_64_Bit_Timer_3A = 0,
    INT_CTRL_32_64_Bit_Timer_3B = 0,
    INT_CTRL_32_64_Bit_Timer_4A = 0,
    INT_CTRL_32_64_Bit_Timer_4B = 0,
    INT_CTRL_32_64_Bit_Timer_5A = 0,
    INT_CTRL_32_64_Bit_Timer_5B = 0,
    INT_CTRL_System_Exception = 0,
    INT_CTRL_PWM1_Generator_0 = 0,
    INT_CTRL_PWM1_Generator_1 = 0,
    INT_CTRL_PWM1_Generator_2 = 0,
    INT_CTRL_PWM1_Generator_3 = 0,
    INT_CTRL_PWM1_FAULT

}IntCtrl_InterruptType;

 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
