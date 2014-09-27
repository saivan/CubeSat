## This program uses Arduino as a slave to receive string from Arduino.
## Code can easily be improved to include transmission of string to Arduino,
## using the writeByte() function

import smbus
import time
import string
import subprocess
import serial
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

string=[]

# This is the address we setup in the Arduino Program
address = 0x04

def writeByte(value):
    bus.write_byte(address, value)
    # bus.write_byte_data(address, 0, value)
    return -1

def readByte():
    number = bus.read_byte(address)
    # number = bus.read_byte_data(address, 1)
    return number

while True:
    ## Receives byte by byte from Arduino, then appends this to string list
    
    byte=1
    try:
        while byte != 0:
            byte=readByte()
            string.append(chr(byte))
            #time.sleep(0.00001)
        new=''.join(string)     #elements in string concatenated
            
        print new
        string = [] #Reinitialise string
        writeByte(0) #send 0 back to signify string has been sent
        time.sleep(1)
    except IOError:
        print "error"
        subprocess.call(['i2cdetect','-y','1'])
