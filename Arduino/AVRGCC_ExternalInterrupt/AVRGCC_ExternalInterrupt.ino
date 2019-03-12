volatile int i = 0;
uint8_t led_pattern[] = {0x01, 0x02, 0x04, 0x08};

void setup() {
  // put your setup code here, to run once:
  EICRA |= (1 << ISC01);
  EICRA &= ~(1 << ISC00);               // falling edge 동작

  EIFR |= (1 << INTF0);                 // Clear INT0 Flag
  EIMSK |= (1 << INT0);                 // Enable INT0
  sei();                                // Global interrupt enable

  DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB3);      // PB0~PB3을 output으로 세팅
  DDRD &= ~(1 << DDD2);                 // PD2(INT0)를 intput으로 세팅

}

ISR(INT0_vect) {
  i++;                                  // 다음 패턴으로 이동
  i %= 4;                               // 배열의 범위 내에서 이동 0 ~ 3
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB = led_pattern[i];               // 패턴 출력
}
