volatile int count = 0;               // ISR내 값이 변경되는 변수이므로 volatile 선언 (pulse 수 측정)
volatile bool cw = true;              // ISR내 값이 변경되는 변수이므로 volatile 선언 (회전 방향 측정)

void Interrupt_Init();                // External interrupt 초기화 함수

void setup() {
  // put your setup code here, to run once:
  Interrupt_Init();                   // External interrupt 초기화
  DDRD &= ~(1 << DDD3);               // B상 입력 단자
  Serial.begin(115200);              // 통신 속도 115200으로 초기화
}

void loop() {
  // put your main code here, to run repeatedly:
  if(cw)
    Serial.println("시계방향 회전");    // 시계 방향 회전을 하고 있을 경우
  else
    Serial.println("반시계방향 회전");  // 반시계 뱡향 회전을 하고 있을 경우
   
  Serial.print("Count: ");
  Serial.println(count);                // 현재 측정된 pusle 값 출력
  delay(1000);
}
ISR(INT0_vect) {
  if(PIND & 0x08 == 0x08){
    cw = true;
    count++;
  }                                       // A상이 falling edge일 때, B상이 High인 경우 시계 방향 회전 중
  else{
    cw = false;
    count--;
  }                                       // A상이 falling edge일 때, B상이 Low인 경우 반시계 방향 회전 중
}
void Interrupt_Init() {
  EICRA |= (1 << ISC01);
  EICRA &= ~(1 << ISC00);               // falling edge 동작

  EIFR |= (1 << INTF0);                 // Clear INT0 Flag
  EIMSK |= (1 << INT0);                 // Enable INT0
  sei();                                // Global interrupt enable

  DDRD &= ~(1 << DDD2);                 // PD2(INT0)를 intput으로 세팅
}
