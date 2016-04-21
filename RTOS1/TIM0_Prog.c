#include "Types.h"
#include "TIM0_Private.h"
#include "TIM0_Config.h"

static void (*TIM0_Ptr)(void);
static void (*Comp_Ptr)(void);
u32 LOOP_COUNT;
/**************************************************************************/
/*****************************Functions ***********************************/
/**************************************************************************/
extern void SetTIM0INT(void (*pointer)(void))
{

		TIM0_Ptr = pointer;

}
extern void SetTIM0Comp(void (*pointer)(void))
{

	Comp_Ptr = pointer;

}
extern void SetTickTime_ms(u16 copy_LocalValue)
{
	LOOP_COUNT=(u32)copy_LocalValue*SYSTEM_CLOCK*1000;
	LOOP_COUNT=LOOP_COUNT/PRESCALAR_VALUE;
	LOOP_COUNT=LOOP_COUNT/COMPARE_REG;
}
ISR(__vector_10)
{
	u32 static Counter=0;
	Counter++;
	if(Counter==LOOP_COUNT)
	{
		Counter =0;
	(Comp_Ptr)();
	}
}
ISR(__vector_11)
{
	(TIM0_Ptr)();
}
extern void SetReg(u8 copy_LocalValue)
{
	OCR0 = copy_LocalValue;
}
extern void TIM0_voidInit(void) {

	__asm__("SEI");

	   TCCR0|=(PRESCALAR<<CS00)|(1<<WGM01)|(1<<COM00);
	   TIMSK|=(1<<OCIE0);
	   OCR0 = COMPARE_REG ;


}

