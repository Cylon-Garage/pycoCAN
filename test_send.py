import serial

port = '/dev/ttyACM0'
baudrate = 115200

message = b'\x00\x01\x02\x03\x04\x05\x06\x08'


arduino = serial.Serial(port=port, baudrate=baudrate, timeout=.1)
arduino.write(message)
