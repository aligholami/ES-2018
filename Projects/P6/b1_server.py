import serial
import re

# Get stream from serial port 1
ser1 = serial.Serial(
    port='COM11',
    baudrate=110,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
)

print("Connected to port: ", ser1.portstr)

ser2 = serial.Serial(
    port='COM10',
    baudrate=110,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
)

print("Connected to port: ", ser2.portstr)

start = 'X'
end = start

while True:

    command = ser1.readline(10)    

    command = str(command)

    command = re.search('%s(.*)%s' % (start, end), command).group(1)

    print("Recieved {} from {}".format(command, ser1.portstr))

    if (command == "temp"):
        print("Sent {} over {}".format(command, ser2.portstr))
        ser2.write("temp".encode())






