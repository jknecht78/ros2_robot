from smbus2 import SMBus, i2c_msg

# I2C bus
bus = SMBus(1)

# I2C slave address
address = 0x10

# Create a write message to send a request
write = i2c_msg.write(address, [])

# Create a read message to receive the data
read = i2c_msg.read(address, 1024)

# Send the request and receive the data
bus.i2c_rdwr(write, read)

# Convert the received data to a string
data = ''.join(chr(b) for b in read)

# Print the received data
print(data)
