import serial

connected = False
ser = serial.Serial("COM5", 9600)
while not connected:
    serin = ser.read()
    connected = True
