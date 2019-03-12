float sample_time;
float sim_time = 0.0;

uint32_t start_time, end_time;

uint32_t MicrosSampleTime;
uint16_t duty_value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);                   // 통신 속도 초기화
  sample_time = 0.02;                      // 0.02초의 sampling time
  MicrosSampleTime = (uint32_t)(sample_time * 1e6);             // micro second 단위로 변환

  DDRB |= (1 << DDB1);                      // 아두이노 9번(PB1/OC1A) 출력 선언

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

  start_time = micros();                      // 시작 시간 기록
  end_time = start_time + MicrosSampleTime;   // 종료 시간(시작 시간 + 샘플링 시간) 기록
}

void loop() {
  // put your main code here, to run repeatedly:
  sim_time += sample_time;
  duty_value = (uint16_t)(127.5 * sin(2 * sim_time) + 127.5);
  OCR1A = duty_value;
  Serial.println(duty_value);               // 시리얼 플로터에 현재 duty value를 전송

  while (!((end_time - micros()) & 0x80000000));      // 종료시간이 될때까지 기다림 (0x80000000은 음수가 될때를 의미함)
  end_time += MicrosSampleTime;                       // 다음 sampling time 종료 시간 update
}
