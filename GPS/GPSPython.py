import serial

#Setup UART Serial Port on the Pi.
GPSSerial = serial.Serial("/dev/ttyAMA0",baudrate=9600,timeout=1)

while 1:
    #Random string inputted for testing
    #GPSData = "hfuhewrferi,$GPRMC, ewfwe,ewfe,wefew,wefe,few,ewf,ewf,wef,$GPVTG"

    GPSData = GPSSerial.readline() #serial read the GPS
    #Find the index of the string where RMC data will begin and end 
    startIndex = GPSData.find("$GPRMC,")
    endIndex = GPSData.find("$GPVTG")

    if startIndex != -1:
        #Create substring from the start index to the end index
        RMCData = GPSData[startIndex+len("$GPRMC,"):endIndex]

        DataList = RMCData.split(",")
        print DataList

    print GPSData
##    GPSTime = DataList[0]
##    GPSLatitude = DataList[2]
##    GPSLongitude = DataList[4]
##    GPSDate = DataList[8]


                 
