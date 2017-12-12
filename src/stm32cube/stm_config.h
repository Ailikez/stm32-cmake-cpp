#ifndef __STM_CONFIG__H
#define __STM_CONFIG__H

/*
    Interface for uC
    To be included in all other files that use uC.

    Wraps code generated by STM32Cube to later work independently of choosen
    pins/peripherals. It provides functions/variables with names corresponding
    to functionalities used in the application. When changing e.g. peripheral
    numbers, you can change only the corresponding .cpp file.
*/


/* Include proper HAL header */
#include "stm32f4xx_hal.h"
#include "main.h"

/* Example of ARM Math Library usage
    #ifndef __FPU_PRESENT
        #define __FPU_PRESENT 1
    #endif
    #define ARM_MATH_CM4
    #include "arm_math.h"
*/

// *** PERIPHERALS ************************************************************
// Here are declarations of the needed variables with meaningful names.
// If there is any need for a variable/constant with fixed name (e.g htim2
//  or DMA2_Stream2_IRQn), then create an alias here and use the alias later.
namespace stm {


/* EXAMPLE
    // delay timer for counting microsecond delays
    extern TIM_HandleTypeDef &delayTimer;
*/

} // namespace stm


#endif
