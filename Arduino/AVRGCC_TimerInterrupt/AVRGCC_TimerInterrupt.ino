void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << DDB0);                               // PB0을 출력으로 선언
  
  TCCR1A &= ~(1 << WGM13);
  TCCR1A |= (1 << WGM12);     
  TCCR1A &= ~(1 << WGM11);
  TCCR1A &= ~(1 << WGM10);                    // CTC Mode (OCR1A를 사용)

  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B |= (1 << CS10);                     // prescaler를 1024으로 세팅

  OCR1A = 15624;                              // Timer/Counter1의 Top값을 15624로 설정

  TCNT1 = 0;                                  // Timer/Counter1 활성화

  TIMSK1 |= (1 << OCIE1A);                     // OC1A에 대한 Interrupt enable
  TIFR1 |= (1 << OCF1A);                      // Clear OCF1A

  sei();                                      // 또는 SREG |= (1 << I);
}

ISR(TIMER1_COMPA_vect){                       // 1초마다 실행되는 ISR
  if((PORTB & 0x01) == 0x01)                  // PB0가 High 상태일때
    PORTB &= ~(1 << PORTB0);
   else                                       // PB0가 Low 상태일때
    PORTB |= (1 << PORTB0); 
}                           
void loop() {
  // put your main code here, to run repeatedly:

}
