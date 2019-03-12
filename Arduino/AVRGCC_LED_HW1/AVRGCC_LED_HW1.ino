void setup() {
  // put your setup code here, to run once:
  DDRD |= 0xF0;         // 아두이노 4, 5, 6, 7번핀 output 선언
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0;i < 4;i++){
    PORTD = (0x10 << i);
    delay(1000);
  }
  
}
