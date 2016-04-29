#ifndef _TIM0_PRIVATE_H_
#define _TIM0_PRIVATE_H_
  
  
/*******************************************************/  
/**************** Private Definitions ******************/  
/*******************************************************/  

#define TCCR0 (*((volatile u8*)(0x53)))
#define TIMSK (*((volatile u8*)(0x59)))
#define OCR0  (*((volatile u8*)(0x5C)))
#define TCNT0  (*((volatile u8*)(0x52)))
#define CS00 0
#define TOIE0 0
#define OCIE0 1
#define WGM00 6
#define WGM01 3
#define COM01 5
#define COM00 4
#define NOCLK_STOP 0
#define NO_PRESCALAR 1
#define F8 2
#define F64 3
#define F256 4
#define F1024 5
#define EXTCLK_FALLING 6
#define EXTCLK_RISING 7
#  define ISR(vector)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)); \
    void vector (void)

/*******************************************************/  
/*****************  Private Functions  *****************/  
/*******************************************************/  
  
/*Comment!: */  
  
#endif  
