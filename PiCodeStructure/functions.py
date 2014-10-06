##This code is the function definition for the RasPi Code
import serial
import string
import picamera


def GetDataFromGrounatation():
    print('GetDataFromGrounatation')

def SaveData():
    print('SaveData')
    
def Beacon():
    print('Beacon')

def determinePosition():
    print('GPS')
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
            print ('DataList')

        print ('GPSData')
    ##    GPSTime = DataList[0]
    ##    GPSLatitude = DataList[2]
    ##    GPSLongitude = DataList[4]
    ##    GPSDate = DataList[8]

def determineAttitude():
    print('ADCS')
    def IMU():
        print('IMU')
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
                print ("yaw =", yaw)
                print ("pitch =", pitch)
                print ("roll =", roll)
                print ("\n")
            else:
                print ("Invalid line")

    def SunSensors():
        print('SunSensors')

def Control():
    print('Control Magnetorque')

def Camera():
    print('Camera')
    # Initialising the camera module
    import picamera
    camera = picamera.PiCamera()

    # This line boots a GUI to show you the camera input
    # only uncomment this line if you want to see the output
    # camera.start_preview()

    # Changing camera settings, don't uncomment things that
    # you don't intend on changing, GAWSH!
    camera.brightness = 90
    camera.sharpness = 10
    camera.ISO = 30

    # This takes a photo - Try to keep it appropriate
    fileName = raw_input( "So what shall I call the file: " )
    camera.capture( fileName )

def Gamma():
    print('Gamma')

def dataToUno():
    print('dataToUno')

def essentialFn():
    print ("essentialFn")
    determineAttitude()
    determinePosition()
    Beacon()

class safe_mode():
    def __init__(self):
        print('This is safe_mode')
        GetDataFromGrounatation()
        essentialFn()
        
class recovery_mode():
    def __init__(self):
        print('This is recovery_mode')
        essentialFn()
        Control()
        GetDataFromGrounatation()
        SaveData()
        
class normal_mode():
    def __init__(self):
        print('This is normal_mode')
        essentialFn()
        Control()
        GetDataFromGrounatation()
        SaveData()
                      
class payload_mode():
    def __init__(self):
        print('This is payload_mode')
        essentialFn()
        Control()
        Camera()
        Gamma()
        
class transmit_mode():
    def __init__(self):
        print('This is transmit_mode')
        essentialFn()
        Control()
        Camera()
        Gamma()
        dataToUno()
