#include "Arduino.h"
#include "HAL.h"
#include <avr/io.h>



Timers::Timers(){
    
}

Timers::~Timers(){
  
}

void Timers::init(){
  TCCR0A |= (1<<WGM01); //tryb pracy CTC
  TCCR0B |= WART_PRESCALER_TIM0; //ustawianie prescalera
  OCR0A = WART_1MS_OCR0;
  TIMSK0 |= (1<<OCIE0A);
}



