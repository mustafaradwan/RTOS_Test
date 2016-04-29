/*
 * OS.c

 *
 *  Created on: Apr 20, 2016
 *      Author: mustafa
 */
#include "Types.h"
#include "Util.h"
#include "TIM0_Interface.h"
#include "OS_Config.h"
struct TCB
{
	void (*ptr)(void);
	u8 Counter;
	u8 Periodicity;
} Task[TASK_NUMBER];// Creating the Tasks

void Creat_Task(u8 Copy_u8TaskId,void(*ptr)(void),u8 Copy_u8TaskCounter,u8 Copy_u8TaskPeriodicity)
{
	Task[Copy_u8TaskId].ptr = ptr;
	Task[Copy_u8TaskId].Counter= Copy_u8TaskCounter;
	Task[Copy_u8TaskId].Periodicity = Copy_u8TaskPeriodicity;

}

void Scheduler(void)
{
for(int i=0;i<TASK_NUMBER;i++)
{
if(Task[i].Counter == 1)
{
Task[i].ptr();
}
}
}
void RTOS_ISR(void)
{

	__asm__("CLI");
	for(int i=0;i<TASK_NUMBER;i++)
	{
		Task[i].Counter--;
	if(Task[i].Counter == 0)
	{
	Task[i].Counter = Task[i].Periodicity;
	}
	}
	__asm__("SEI");
	Scheduler();
	}

void RTOS_Init(void)
{


	// enable the timer and call the scheduler
		SetTIM0INT(RTOS_ISR);
		SetTickTime_us((f32)TICK_TIME_US);
		TIM0_voidInit();
	//Calling the Scheduler
		Scheduler();
}
