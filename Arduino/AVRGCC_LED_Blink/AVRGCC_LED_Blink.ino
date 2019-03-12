void setup() {
  // put your setup code here, to run once:
  DDRD |= 0b00000010;         // 아두이노 1번핀(PD1)을 OUTPUT으로 선언
  
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTD |= 0x02;        // 아두이노 1번핀(PD1)에 출력 HIGH
  delay(1000);          // 1초의 지연시간
  PORTD &= ~0x02;       // 아두이노 1번핀(PD1)에 출력 LOW
  delay(1000);          // 1초의 지연시간
}
