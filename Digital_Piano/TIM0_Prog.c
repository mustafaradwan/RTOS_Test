#include "Types.h"
#include "TIM0_Private.h"
#include "TIM0_Config.h"

static void (*TIM0_Ptr)(void);
/**************************************************************************/
/*****************************Functions ***********************************/
/**************************************************************************/
extern void SetTIM0INT(void (*pointer)(void))
{

		TIM0_Ptr = pointer;

}
ISR(__vector_11)
{
	(TIM0_Ptr)();
}
extern void TIM0_voidInit(void) {
	__asm__("SEI");
	   TCCR0|=(PRESCALAR<<CS00);
	   TIMSK|=(1<<TOIE0);

}

