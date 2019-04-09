void TWI_Initialize() {
  TWBR = 0x0C;                // 400kHz SCL
};
void TWI_write(unsigned char slave, unsigned char data) {
  /* Start bit */
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);     // Start bit 클럭 생성
  while (!(TWCR & (1 << TWINT)));                       // Start bit 전송 동작이 끝났음을 기다림
  if ((TWSR & 0xF8) != 0x08) {
    return ;
  }               // Start bit가 정상적으로 전송되지 않았을 경우 exit()함수 호출

  /* Slave address + write bit(0)*/
  TWDR = slave << 1;                                    // 7-bit 주소를 하위 1-bit로 비워두고 8-bit로 만듬
  TWCR = (1 << TWINT) | (1 << TWEN);                    // 주소+Write 클럭 전송
  while ( !(TWCR & (1 << TWINT)) || (TWSR & 0xF8) != 0x18);   // 주소+Write가 전송이 끝나고 ACK를 받을 때까지 기다림

  /* Write data */
  TWDR = data;                                          // 전송할 data를 TWDR에 저장
  TWCR = (1 << TWINT) | (1 << TWEN);                    // data 전송 클럭 시작
  while ( !(TWCR & (1 << TWINT)) || (TWSR & 0xF8) != 0x28);   // data 전송이 끝나고 ACK를 받을 때까지 기다림

  /* Stop Bit */
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);     // Stop bit 클럭 생성

};

void TWI_read(unsigned char slave, unsigned char *data) {
  /* Start bit */
  TWCR = (1 << TWINT) | ( 1 << TWSTA) | (1 << TWEN);  // Start bit 클럭 생성
  while (!(TWCR & (1 << TWINT)));                     // Start bit 전송 동작이 끝났음을 기다림
  if ((TWSR & 0xF8) != 0x08) {
    return ;
  }           // Start bit가 정상적으로 전송되지 않았을 경우 exit()함수 호출


  /* Slave address + read bit(1) */
  TWDR = slave << 1 | 0x01;                           // 7-bit 주소를 왼쪽으로 1-bit shift하고 가장 하위 1-bit를 1로 set
  TWCR = (1 << TWINT) | (1 << TWEN);                  // 주소+Read 클럭 전송
  while ( !(TWCR & (1 << TWINT)) || (TWSR & 0xF8) != 0x40);   // 주소+Read 전송이 끝나고 ACK를 받을 때까지 기다림

  /* read data */
  TWCR = (1 << TWINT) | (1 << TWEN);                  // data를 읽어오는 클럭 전송
  while ( !(TWCR & (1 << TWINT)) || (TWSR & 0xF8) != 0x50);   // data 수신이 끝나고 ACK를 받을 때까지 기다림
  *data = TWDR;                                       // TWDR 버퍼에서 전송받은 data를 읽어옴

  /* Stop Bit */
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);   // Stop bit 클럭 생성

};

void setup() {
  // put your setup code here, to run once:
  TWI_Initialize();
}

void loop() {
  // put your main code here, to run repeatedly:

}
