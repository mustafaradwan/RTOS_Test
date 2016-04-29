#ifndef _TIM0_INTERFACE_H_
#define _TIM0_INTERFACE_H_
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  



/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  /*Comment!: SET The function the T_Switch*/
 extern void SetTIM0INT(void (*pointer)(void));
 extern void SetTIM0Comp(void (*pointer)(void));
 extern void SetReg(u8 copy_LocalValue);
 extern void SetTickTime_us(f32 copy_LocalValue);



/*Comment!: initialize the T_Switch*/
extern void TIM0_voidInit(void);
  
#endif  
