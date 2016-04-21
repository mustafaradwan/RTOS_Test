#ifndef _TIM0_CONFIG_H_
#define _TIM0_CONFIG_H_

/*******************************************************/
/**************** Public Definitions *******************/
/*******************************************************/


/*Comment!:  OSCILLATOR CLOCK FREQUENCY SELECT:
1- NOCLK_STOP
2- NO_PRESCALAR
3- F8
4- F64
5- F256
6- F1024
7- EXTCLK_FALLING
8- EXTCLK_RISING
  */
#define PRESCALAR F1024
#define PRESCALAR_VALUE 1024
#define SYSTEM_CLOCK 4
#define COMPARE_REG 50

#endif 
