void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);       // 아두이노 1번핀을 OUTPUT으로 선언
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(1, HIGH);    // 1번 핀에 출력 HIGH
  delay(1000);              // 1초의 지연시간
  digitalWrite(1, LOW);     // 1번 핀에 출력 LOW
  delay(1000);              // 1초의 지연시간
}
