import serial
#import smbus
import time
import subprocess
import string

#bus = smbus.SMBus(1)

addr = 0x04

#Setup UART Serial Port on the Pi.
#GPSSerial = serial.Serial("/dev/ttyAMA0",baudrate=9600,timeout=1)

# Setup Serial for IMU via USB COM port
#IMUSerial = serial.Serial(port='COM10',baudrate=57600, timeout=1)

#Setup Serial for Pi to Uno
#PiUnoSerial = serial.Serial("/dev/ttyACM0",9600)

def getGPS():
    
    #Random string inputted for testing
    GPSData = "hfuhewrferi,$GPRMC,123519,ewfe,wefew,wefe,few,ewf,ewf,wef,$GPVTG"

    #GPSData = GPSSerial.readline() #serial read the GPS
    #Find the index of the string where RMC data will begin and end 
    startIndex = GPSData.find("$GPRMC,")
    endIndex = GPSData.find("$GPVTG")

    if startIndex != -1:
        #Create substring from the start index to the end index
        RMCData = GPSData[startIndex+len("$GPRMC,"):endIndex]

        GPSData = RMCData.split(",")

    return GPSData   

    ##    GPSTime = DataList[0]
    ##    GPSLatitude = DataList[2]
    ##    GPSLongitude = DataList[4]
    ##    GPSDate = DataList[8]

def getGPSTimeSec():
    tempStr = GPSData[0]
    timeSeconds = tempStr[-2:]
    return timeSeconds

def getIMU():
    line = IMUSerial.readline()
    IMUAngles = line.split(",")    # Split string into Yaw, Pitch, Roll (comma-separated)
##    if len(IMUAngles) > 2:         # Check if String length is larger than 2 (doesnt seem to work if i dont do this)
##        yaw = IMUAngles[0]     #Access each axis in the list 'angles'
##        pitch = IMUAngles[1]
##        roll = IMUAngles[2]
##        print "yaw =", yaw
##        print "pitch =", pitch
##        print "roll =", roll
##        print "\n"
    return IMUAngles

def receiveFromUno():
    ## Receives byte by byte from Arduino, then appends this to string list
    PiUnoSerial.read(15)

def sendToUno(string):
    PiUnoSerial.write(string)

def IMUCombineSun(IMUAngles, sunSensorData):
    attitude[0] = (IMUAngles[0] + sunSensorData[0])/2
    attitude[1] = (IMUAngles[1] + sunSensorData[1])/2
    attitude[2] = IMUAngles[2]
    return attitude

def applyControl():
    print Applying Control

while 1:
##    changeMode();
    
    gpsString=getGPS()
    timeSeconds = getGPSTimeSec()
    
##    
    
    receivedData = receiveFromUno()
    modeCommand = int(receivedData[:1])
    sunSensorData = receivedData[1:]
    print modeCommand
    
    IMUAngles = getIMU()
    
##    attitude = IMUCombineSun(IMUAngles, sunSensorData)
##    applyControl()
##
    if (timeSeconds == 0 or timeSeconds == 30):
        sendToUno(gpsString)
    
