BIN	=main
OBJS	=serial.o i2c_master.o MPU9250.o ${BIN}.o 
#VPATH 	=headers:src

DEVICE		=atmega328p
CLOCK		=16000000UL
PORT		=/dev/ttyUSB*
BAUD		=57600
ICSP		=arduino
PROGRAMMER	=-c ${ICSP} -P ${PORT} -b ${BAUD}

FUSES			=-U lfuse:w:0x62:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m 
CFLAGS			=-Os -DUSART_BAUDRATE=${BAUD} -DF_CPU=${CLOCK} -mmcu=${DEVICE} -pedantic -Wall
CC			=avr-gcc ${CFLAGS}
OBJCOPY			=avr-objcopy

AVRDUDE			=avrdude ${PROGRAMMER} -p ${DEVICE}
.PHONY: install fuses clean


${BIN}.hex: ${BIN}.elf
	${OBJCOPY} -O ihex -R .eeprom $< $@

${BIN}.elf: ${OBJS}
	${CC} -o $@ $^

MPU9250.o: imu/MPU9250.c imu/MPU9250.h i2c/i2c_master.h 
	${CC} -c $^

i2c_master.o: i2c/i2c_master.c i2c/i2c_master.h
	${CC} -c $^

serial.o: uart/serial.c uart/serial.h
	${CC}  -c $^

install: ${BIN}.hex
	${AVRDUDE} -F -V -U flash:w:$<


fuses:
	${AVRDUDE} ${FUSES}

clean:
	rm -f ${BIN}.elf ${BIN}.hex ${OBJS}
