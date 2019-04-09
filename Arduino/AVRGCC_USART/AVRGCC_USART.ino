#define F_clock 16000000UL          // UL은 Unsigned long type으로 저장해준다는 의미입니다
#define BAUD 9600                   // Baud Rate: 9600 bps
#define MYUBRR F_clock/(16*BAUD) - 1

void USART_Init(unsigned int ubrr) {
  UBRR0H = (unsigned char)(ubrr >> 8);                    // ubrr 상위 8-bit 입력
  UBRR0L = (unsigned char)ubrr;                           // ubrr 하위 8-bit 입력 (unsigned int를 unsigned char로 형변환 시 상위 8-bit 소실)

  UCSR0B = (1 << RXEN0) | (1 << TXEN0);                   // USART 송신 수신을 가능하게 설정
  UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);                // UCSZ값을 3(0b011)을 입력 = 문자 전송 크기가 8-bit
}
void USART_Transmit(char data) {
  while (!((UCSR0A) & (1 << UDRE0)))                      // 전송 buffer가 사용 가능일때까지 기다림
    ;
  UDR0 = data;                                            // 전송 buffer에 data를 입력
}
unsigned char USART_Receive() {
  while (!(UCSR0A & (1 << RXC0)))
    ;
  return UDR0;
}
void setup() {
  // put your setup code here, to run once:
  USART_Init(MYUBRR);
}

void loop() {
  // put your main code here, to run repeatedly:
  USART_Transmit(USART_Receive());
  delay(100);
}
