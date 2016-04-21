#include "Types.h"
#include "DIO_interface.h"
#include "KeyPad4by4_Interface.h"
#include "KeyPad4by4_Config.h"
#include "KeyPad4by4_Private.h"
#include "Util.h"
#define FALSE 0
#define TRUE 1
static u8 const KeyPad_R[4]={KEYPAD_R0,KEYPAD_R1,KEYPAD_R2,KEYPAD_R3};
static u8 const KeyPad_C[4]={KEYPAD_C0,KEYPAD_C1,KEYPAD_C2,KEYPAD_C3};


u16 KeyPad4by4_u16ReadSWNum(void)
{
	u8  Local_u8Flag =FALSE;
	u8 Local_u8RLoop;
	u8 Local_u8CLoop;
	u8 Local_u8Value=DIO_u8LOW;
	u16 static Local_u16SWNum;
for(Local_u8RLoop=0;Local_u8RLoop<4 && Local_u8Flag==FALSE;Local_u8RLoop++)
{


		DIO_u8WritePinVal(KeyPad_R[Local_u8RLoop],DIO_u8LOW);
	 for(Local_u8CLoop=0;Local_u8CLoop<4  && Local_u8Flag==FALSE;Local_u8CLoop++)
	 {

		 DIO_u8ReadPinVal(KeyPad_C[Local_u8CLoop],&Local_u8Value);
		 if(Local_u8Value == DIO_u8LOW)
		 {

			 Local_u16SWNum = (Local_u8CLoop+Local_u8RLoop*4);
			 if(Local_u16SWNum == 0)
			 {
				 Local_u16SWNum = 16;
			 }
		    Local_u8Flag = TRUE;
		 }
		 else
		 {
			 Local_u8Flag = FALSE;
			 Local_u16SWNum = 0;
		 }


	 }
	 DIO_u8WritePinVal(KeyPad_R[Local_u8RLoop],DIO_u8HIGH);

}

return Local_u16SWNum;
}

extern void KeyPad4by4_voidInit(void)
{
	u8 Local_u8Loop;
	for(Local_u8Loop=0;Local_u8Loop<4;Local_u8Loop++)
	{
	DIO_u8WritePinDir(KeyPad_C[Local_u8Loop],DIO_u8INPUT);
	 DIO_u8WritePinVal(KeyPad_C[Local_u8Loop],DIO_u8HIGH);
	}
	for(Local_u8Loop=0;Local_u8Loop<4;Local_u8Loop++)
	{
	DIO_u8WritePinDir(KeyPad_R[Local_u8Loop],DIO_u8OUTPUT);
	 DIO_u8WritePinVal(KeyPad_R[Local_u8Loop],DIO_u8HIGH);

	}
	}
