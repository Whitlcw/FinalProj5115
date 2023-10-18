import smbus
import time

bus = smbus.SMBus(1)  # 1 indicates /dev/i2c-1 on Raspberry Pi 4

arduino_address = 0x08  # Arduino's I2C address

string_to_send = "Hello, Arduino!"
byte_array = [ord(char) for char in string_to_send]

bus.write_i2c_block_data(arduino_address, 0, byte_array)

time.sleep(1)  # Give time for the Arduino to process the data

bus.close()
