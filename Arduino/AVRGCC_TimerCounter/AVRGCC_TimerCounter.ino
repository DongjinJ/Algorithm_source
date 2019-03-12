void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << DDB1);                               // PB1을 출력으로 선언
  
  TCCR1A &= ~(1 << WGM13);
  TCCR1A |= (1 << WGM12);     
  TCCR1A &= ~(1 << WGM11);
  TCCR1A &= ~(1 << WGM10);                    // CTC Mode (OCR1A를 사용)

  TCCR1A |= (1 << COM1A1);
  TCCR1A &= ~(1 << COM1A0);                   // OC1A를 Compare Match에서 clear

  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);                     // prescaler를 256으로 세팅

  OCR1A = 31249;                              // Timer/Counter1의 Top값을 31249로 설정

  TCNT1 = 0;                                  // Timer/Counter1 활성화
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
