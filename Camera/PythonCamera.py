
#import the camera module
import picamera
camera = picamera.PiCamera()

true = 1
false = 0

# Defining pixel heights and widths for the image
height = 100
width = 100


# Take a bitmap photo called image.bmp
camera.resolution=(width,height)
camera.start_preview()
camera.capture('image.bmp')
camera.stop_preview()

# Threshold cutoff parameters
averagePixelThreshold = 200						# The minimum threshold value to triger a true pixel
thresholdValue = (averagePixelThreshold**2)*3 	# The value to check against to trigger a true pixel
minimumTruePixels = 40							# The number of true pixels required for a hit
lightningDetected = false

image = open('image.bmp','r');
imageData = bytearray(image.read())

# Discard the first four bytes
for pixel in range(4):
	imageData.pop()

thresholdCount = 0 
for pixel in range(width*height):
	thresholdSum = 0;
	for color in range(3):
		thresholdSum += imageData.pop()**2
	if thresholdSum >= thresholdValue:
		thresholdCount+=1

lightningDetected = false
if thresholdCount > minimumTruePixels:
	lightningDetected = true

print thresholdCount
