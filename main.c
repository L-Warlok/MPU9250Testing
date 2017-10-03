
#include "example.h"


int main(void) {
  serial0_init();

  initMPU9250();

  float *gyroBias, *accelBias, *bias;
  calibrateMPU9250(gyroBias, accelBias);
  //MPU9250SelfTest(bias);

  char info[28] = {"Acceleration data: x, y, z\n"};


  uint8_t temp[10];

  int16_t accelData[3] = {0,0,0};
  

  while(1) {

    readGyroData(accelData);

    serial0_print_string(info);

    itoa(accelData[0], temp, 10);
    serial0_print_string(temp);
    serial0_write_byte('\t');

    itoa(accelData[1], temp, 10);
    serial0_print_string(temp);
    serial0_write_byte('\t');

    itoa(accelData[2], temp, 10);
    serial0_print_string(temp);
    serial0_write_byte('\n');
    _delay_ms(1000);


  };
}




