#include "Types.h"
#include "TIM0_Config.h"
#include "TIM0_Private.h"

static void (*TIM0_Ptr)(void);
static void (*Comp_Ptr)(void);
u32 Number_OverFlows;
f32 Time_OverFlows;
u8 TCNT0_Value;
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
extern void SetTickTime_us(f32 copy_LocalValue)
{
	f32 Timer_Tick;
Timer_Tick = 8/SYSTEM_FREQ;
	Time_OverFlows = 255 * Timer_Tick; // 255*8/SYSTEM_FREQ
	Number_OverFlows=(copy_LocalValue/Time_OverFlows);
	TCNT0_Value =255-(((copy_LocalValue) -(Number_OverFlows*Time_OverFlows))/Timer_Tick);
	Number_OverFlows += 1;
}
ISR(__vector_10)
{

	(Comp_Ptr)();

}
ISR(__vector_11)
{
	u32 static Counter=0;
	Counter++;
	if(Counter==Number_OverFlows)
	{
		Counter =0;
		   TCNT0 = TCNT0_Value ;
	(TIM0_Ptr)();
	}
}
extern void SetReg(u8 copy_LocalValue)
{
	OCR0 = copy_LocalValue;
}
extern void TIM0_voidInit(void) {

	__asm__("SEI");

	   TCCR0|=(2<<CS00);
	   TIMSK|=(1<<TOIE0);
	   TCNT0 = TCNT0_Value ;


}

