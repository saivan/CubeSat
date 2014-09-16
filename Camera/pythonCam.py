
# Initialising the camera module
import picamera
camera = picamera.PiCamera()

# This line boots a GUI to show you the camera input
# only uncomment this line if you want to see the output
# camera.start_preview()

# This takes a photo - Try to keep it appropriate
camera.capture('helloWorld.jpg')
