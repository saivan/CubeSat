import serial
#import smbus
import time
import subprocess
import string
import math

#bus = smbus.SMBus(1)

addr = 0x04

## WOD data variables
battV1 = 5
battI1 = 0.5
threeVI1 = 0.5
fiveVI1 = 0.8
tComm1 = 25
tempEPS1 = 35
tempBatt1 = 40

battV = max(0,min(255,int((20*battV1)-60)))
battI = max(0,min(255,int(127*battI1+127)))
threeVI = max(0,min(255,int(40*threeVI1)))
fiveVI = max(0,min(255,int(40*fiveVI1)))             
tComm = max(0,min(255,int(4*tComm1+60)))
tempEPS = max(0,min(255,int((4*tempEPS1+60))))
tempBatt = max(0,min(255,int((4*tempBatt1+60))))

#Setup UART Serial Port on the Pi.
#GPSSerial = serial.Serial("/dev/ttyAMA0",baudrate=9600,timeout=1)

# Setup Serial for IMU via USB COM port
#IMUSerial = serial.Serial(port='COM10',baudrate=57600, timeout=1)

#Setup Serial for Pi to Uno
#PiUnoSerial = serial.Serial("/dev/ttyACM0",9600)

modeCommand = 1


def pad(value):
    if value<10:
        string = "00"+str(value)
    elif value>=10 and value <100:
        string ="0" +str(value)
    elif value>=100:
        string = str(value)
    return string

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
    if len(IMUAngles) > 2:         # Check if String length is larger than 2 (doesnt seem to work if i dont do this)
        yaw = IMUAngles[0]     #Access each axis in the list 'angles'
        pitch = IMUAngles[1]
        roll = IMUAngles[2]
        print "yaw =", yaw
        print "pitch =", pitch
        print "roll =", roll
        print "\n"
    return IMUAngles

def receiveFromUno():
    ## Receives byte by byte from Arduino, then appends this to string list
    data = PiUnoSerial.readline()
    return data

def sendToUno(string):
    PiUnoSerial.write(string)

def IMUCombineSun(IMUAngles, sunSensorData):
    attitude[0] = (IMUAngles[0] + sunSensorData[0])/2
    attitude[1] = (IMUAngles[1] + sunSensorData[1])/2
    attitude[2] = IMUAngles[2]
    return attitude

def applyControl():
    print 'Applying Control'

while 1:
    if modeCommand == 1:
        print "Payload Mode"
        GPSData=getGPS()
        timeSeconds = getGPSTimeSec()           
    ##
        time.sleep(2)
        #receivedData = receiveFromUno()
        #modeCommand = receivedData[:1]
        #sunSensorData = receivedData[1:]
        #print modeCommand
        #print receivedData
        #IMUAngles = getIMU()
        
    ##    attitude = IMUCombineSun(IMUAngles, sunSensorData
    ##    applyControl()
    ##
        #if (timeSeconds == 0 or timeSeconds == 30):
        #sendToUno(GPSData)
        print GPSData
        
        wodData1 = pad(modeCommand)
        wodData2 = pad(battV)
        wodData3 = pad(battI)
        wodData4 = pad(threeVI)
        wodData5 = pad(fiveVI)
        wodData6 = pad(tComm)
        wodData7 = pad(tempEPS)
        wodData8 = pad(tempBatt)
        wodDataFull = wodData1 + wodData2 + wodData3 + wodData4 + wodData5 + wodData6 + wodData7 + wodData8
        print wodDataFull
    if modeCommand == 2:
        print "Safe Mode"
        GPSData=getGPS()
        timeSeconds = getGPSTimeSec()
        
        receivedData = receiveFromUno()
        if (timeSeconds == 0 or timeSeconds == 30):
            sendToUno(GPSData) 

    if modeCommand == 3:
       print "Normal Mode"
       
    if modeCommand == 4:
        print "Transmit Mode"
