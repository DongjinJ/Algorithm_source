void ADC_Init() {
  ADCSRA |= ((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));    // 16,000,000/128 = 125,000Hz (Prescaler 설정)
  ADMUX |= (1 << REFS0);        // AVcc 사용 (5V)
  ADCSRA |= (1 << ADEN);        // ADC 활성화
}
uint16_t ADC_Read(unsigned char channel) {
  ADMUX &= ~(1 << ADLAR);                // 상위 4비트 초기화 (ADC 우측 정렬)
  ADMUX |= channel;             // 읽어올 채널 세팅

  ADCSRA |= (1 << ADSC);        // ADC 변환 시작
  while(ADCSRA&(1<<ADSC));      // 변환이 완료될 때까지 대기(변환 완료 시 ADSC가 0으로 초기화)

  return ADCW;                  // 변환된 데이터 반환
}
void setup() {
  // put your setup code here, to run once:
  ADC_Init();
}

void loop() {
  // put your main code here, to run repeatedly:

}
