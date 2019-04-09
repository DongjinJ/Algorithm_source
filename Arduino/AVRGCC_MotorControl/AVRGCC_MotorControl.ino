uint16_t motor_power = 0;

void GPIO_Init() {
  DDRB |= (1 << DDB1);                      // 아두이노 9번(PB1/OC1A) 출력 선언
  DDRD |= (1 << DDD6) | (1 << DDD7);        // 아두이노 6번(PD6), 7번(PD7) 출력 선언
}
void PWM_Init() {
  TCCR1B &= ~(1 << WGM13);
  TCCR1B |= (1 << WGM12);
  TCCR1A &= ~(1 << WGM11);
  TCCR1A |= (1 << WGM10);                   // 8-bit Fast PWM mode

  TCCR1A |= (1 << COM1A1);
  TCCR1A &= ~(1 << COM1A0);                 // Clear OC1A on Compare Match

  TCCR1B &= ~(1 << CS12);
  TCCR1B |= (1 << CS11);
  TCCR1B |= (1 << CS10);                    // prescaler: clk/64

  TCNT1 = 0;
}
void forward() {
  PORTD |= (1 << PORTD6);
  PORTD &= (1 << PORTD7);
}
void backward() {
  PORTD |= (1 << PORTD7);
  PORTD &= (1 << PORTD6);
}
void setup() {
  // put your setup code here, to run once:
  GPIO_Init();
  PWM_Init();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    motor_power = Serial.parseInt();                  // Serial에서 받은 값을 int형으로 전달 (0 ~ 255)
    if (motor_power > 255)
      OCR1A = 255;
    else if (motor_power < 0)
      OCR1A = 0;
    else
      OCR1A = motor_power;
    Serial.print("Current power: ");
    Serial.println(motor_power);                     // 현재 OCR1A 값을 띄움
  }
  forward();                                          // 1초 동안 정방향 회전
  delay(1000);      
  backward();                                         // 1초 동안 역방향 회전
  delay(1000);
}
