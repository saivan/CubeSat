#Serial Read for IMU - Simple code which reads serial string from IMU, then splits it into each axis, and then prints the separated variables
#Working connected to computer via USB FTDI cable

import serial
import string

# Input your COM port and baud rate
ser = serial.Serial(port='COM10',baudrate=57600, timeout=1)

#While loop to constantly read from serial
while 1:
    line = ser.readline()
    angles = line.split(",")    # Split string into Yaw, Pitch, Roll (comma-separated)
    if len(angles) > 2:         # Check if String length is larger than 2 (doesnt seem to work if i dont do this)
        yaw = angles[0]     #Access each axis in the list 'angles'
        pitch = angles[1]
        roll = angles[2]
        print "yaw =", yaw
        print "pitch =", pitch
        print "roll =", roll
        print "\n"
    else:
        print "Invalid line"
