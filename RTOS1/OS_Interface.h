/*
 * OS_Interface.h
 *
 *  Created on: Apr 20, 2016
 *      Author: mustafa
 */

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

extern void RTOS_Init(void);
void Creat_Task(u8 Copy_u8TaskId,void(*ptr)(void),u8 Copy_u8TaskCounter,u8 Copy_u8TaskPeriodicity);


#endif /* OS_INTERFACE_H_ */
