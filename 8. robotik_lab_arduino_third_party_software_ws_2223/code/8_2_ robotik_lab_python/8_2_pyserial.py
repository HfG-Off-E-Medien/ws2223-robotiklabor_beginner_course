import serial
import time

arduino = serial.Serial('/dev/cu.usbmodem11201', 9600)   # create serial object named arduino

while True:                                             # create loop
        command = str(input ("Servo position: "))       # query servo position
        arduino.write(command.encode())                  # write position to serial port
        reachedPos = str(arduino.readline())            # read serial port for arduino echo
        time.sleep(0.5)
        print(reachedPos)  