
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
