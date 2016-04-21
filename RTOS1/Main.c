/*
 * Main.c
 *
 *  Created on: Apr 20, 2016
 *      Author: mustafa
 */
#include "Types.h"
#include "Util.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "OS_Interface.h"
void Task1(void)
{
	static u8 LED1=0;
	LED1 = ~ LED1;
	ASSIGN_BIT(*DIO_u8PORTC,0,LED1);
}
void Task2(void)
{
	static u8 LED2=0;
	LED2 = ~ LED2;
	ASSIGN_BIT(*DIO_u8PORTC,1,LED2);
}
void Task3(void)
{
	static u8 LED3=0;
	LED3 = ~ LED3;
	ASSIGN_BIT(*DIO_u8PORTC,2,LED3);
}
int main(void)
{
	DIO_voidInit();
	Creat_Task(0,Task1);
	Creat_Task(1,Task2);
	Creat_Task(2,Task3);
	RTOS_Init();
	while(1)
	{

	}
	return 0;
}

