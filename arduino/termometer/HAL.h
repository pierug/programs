#ifndef HAL_H_
#define HAL_H_

#define WART_PRESCALER_TIM1  (1<<CS11)|(1<<CS10) //prescaler 64
#define WART_OCR1 0x1F  //wartosc wpisywana do rejestru OCR aby otrzymac czas podany powyzej
#define WART_PRESCALER_TIM0  (1<<CS01)|(1<<CS00) //prescaler 64
#define WART_1MS_OCR0 0xF9  //1ms
#define WART_01MS_OCR0 0x1F  //0.1ms

class Timers{
public:
  Timers();
  ~Timers();
  void init();
};
 

#endif /* HAL_H_ */


