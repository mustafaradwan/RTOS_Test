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
u8 Task_Counter[TASK_NUMBER] = {TASK1_COUNTER,TASK2_COUNTER,TASK3_COUNTER};
u8 Task_Periodicity[TASK_NUMBER] = {TASK1_PERIODICITY,TASK2_PERIODICITY,TASK3_PERIODICITY};

void Creat_Task(u8 Copy_u8TaskId,void(*ptr)(void))
{
	Task[Copy_u8TaskId].ptr = ptr;
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
	// Initialization of Tasks
	for(int i=0;i<TASK_NUMBER;i++)
	{
		Task[i].Counter= Task_Counter[i];
		Task[i].Periodicity = Task_Periodicity[i];
	}

	// enable the timer and call the scheduler
		SetTIM0Comp(RTOS_ISR);
		SetTickTime_ms(TICK_TIME_MS);
		TIM0_voidInit();
	//Calling the Scheduler
		Scheduler();
}
