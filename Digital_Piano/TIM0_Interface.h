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


/*Comment!: initialize the T_Switch*/
extern void TIM0_voidInit(void);
  
#endif  
