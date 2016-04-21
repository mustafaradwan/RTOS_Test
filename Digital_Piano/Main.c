
/*
 * Main.c
 *
 *  Created on: Feb 13, 2016
 *      Author: mustafa
 */

#include "Types.h"
#include "DIO_interface.h"
#include "TIM0_Interface.h"
#include "KeyPad4by4_Interface.h"
#define FALSE 0
#define TRUE 1
#define LED1 8



u16 Counter;
u8 Value;
u8 Flag;
void Time0(void)
{
	// the timer will over flow after 0.065536 sec
	// call a function in the main.
u8 static Count;

Count++;
	if(Count==Counter && Flag == TRUE)// after 2/3 sec.
	{
Value = ! Value;
DIO_u8WritePinVal(LED1,Value);
Count =0;
			}
	else
	{
		DIO_u8WritePinVal(LED1,DIO_u8LOW);

	}

}

int main(void) {
	DIO_voidInit();
	SetTIM0INT(Time0);
	TIM0_voidInit();
	KeyPad4by4_voidInit();





///////////////////////////////////////////
	while (1) {
		if(KeyPad4by4_u16ReadSWNum())
		{
			Flag = TRUE;
		Counter=KeyPad4by4_u16ReadSWNum();
		}
		else
		{
			Flag = FALSE;
		}
	}
	return 0;
}
