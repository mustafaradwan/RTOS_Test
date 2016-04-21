#ifndef _KeyPad4by4_INTERFACE_H_
#define _KeyPad4by4_INTERFACE_H_
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  
/*Comment!: Switch State*/
#define ACTIVEHIGH 1
#define ACTIVELOW 0



/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  
  
/*Comment!: check the switch state high or low*/
extern u16 KeyPad4by4_u16ReadSWNum(void);
 
/*Comment!: initialize the T_Switch*/
extern void KeyPad4by4_voidInit(void);
  
#endif  
