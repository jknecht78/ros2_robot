from smbus2 import SMBus, i2c_msg

bus = SMBus(1)  # indicates /dev/ic2-1
arduino_address = 0x08

received_string = ''

while True:
  read = i2c_msg.read(arduino_address, 32)  # create a read message
  bus.i2c_rdwr(read)  # perform I2C operation
  received_data = list(read)
  received_string += ''.join(chr(b) for b in received_data)
  if '#' in received_string:  // stop reading when the delimiter is found
    break

received_string = received_string.rstrip('#')  // remove the delimiter from the string

print(received_string)
