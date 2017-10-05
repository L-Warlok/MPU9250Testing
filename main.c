
#include "main.h"


int main(void) {
  i2c_init();

  uart0_init(UART_BAUD_SELECT(57600,F_CPU));

  initMPU9250();
  DDRB |= (1<<5);
  PORTB |= (1<<5);

  float *gyroBias, *accelBias, *bias;
  //calibrateMPU9250(gyroBias, accelBias);
  //MPU9250SelfTest(bias);

  char info[50] = {"Acceleration data:\tx\ty\tz\n\r\t\t\t"};


  char temp[10];

  int16_t accelData[3] = {0,0,0};
  
   
  while(1) {

    itoa(i2c_start(0x68 | 0x00), temp, 10);
    uart0_puts(temp);
    uart0_putc('\t');
    _delay_ms(1000);


    /*readAccelData(accelData);


    uart0_puts(info);

    itoa(accelData[0], temp, 10);
    uart0_puts(temp);
    uart0_putc('\t');

    itoa(accelData[1], temp, 10);
    uart0_puts(temp);
    uart0_putc('\t');

    itoa(accelData[2], temp, 10);
    uart0_puts(temp);
    uart0_putc('\n');
    uart0_putc('\r');
    _delay_ms(1000);
    */


  };
}




