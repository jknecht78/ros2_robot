from smbus2 import SMBus, i2c_msg

bus = SMBus(1)  # indicates /dev/ic2-1
arduino_address = 0x08

received_string = ''

while True:
  read = i2c_msg.read(arduino_address, 32)  # create a read message
  bus.i2c_rdwr(read)  # perform I2C operation
  received_data = list(read)
  received_string += ''.join(chr(b) for b in received_data)
  if len(received_string) >= len(data_to_send):  // assuming you know the length of data
    break

print(received_string)
