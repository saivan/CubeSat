
import serial
import RPi.GPIO as GPIO

# Setup the serial connection
IMU = serial.Serial('/dev/ttyUSB0',57600)
# Setup the GPIO PWM pins
GPIOPin = 12
GPIO.setmode( GPIO.BOARD )
GPIO.setup( GPIOPin, GPIO.OUT )
actuator = GPIO.PWM( GPIOPin, 1000 )					# Set up a 10KHz signal on the PWM output

# Define the parts of the IMU Data
orient = roll,pitch,yaw = 0, 1, 2
buffSize = 60
rawYaw = range(buffSize)
currentYaw = range(buffSize)						# The actual value of the yaw from the high pass filter

i = 0									# i is the buffer index
runningTotal = 0
error = 0
errDer = 0

# Actuation signal parameters
a = 100.0/360.0
b = 0.05

# Let the user input a target
targetYaw = float(raw_input("Input a target direction: "))


# Define a function to increment and decrement the index
def ind( current, jump ):
	current = current+jump
	if current < 0:
		current += buffSize
	elif current >= buffSize:
		current -= buffSize
	return current


# Give the IMU some time to wake up
for count in range(50): 						# Throw away 50 readings
	currentReading = IMU.readline()

# Start the actuator with a 50% duty cycle
actuator.start(0.5)

while 1:
	# Get and clean a reading
	currentReading = IMU.readline()
	currentReading = currentReading.strip("RPY#\r\n")		# Strip away the characters we don't need
	orientationString = (currentReading.split(','))			# Split up the roll pitch and yaw of the reading
	
	try:
		# Calculate the low frequency drift
		runningTotal += 0.1132						# Calibration to remove some of the drift error

		rawYaw[i] = (float( orientationString[roll] ) + 180 - runningTotal)	# Since we are using only the yaw, we convert it to a float and store it : range [0,360]	
		if rawYaw[i] < 0:
			rawYaw[i] += 360
		elif rawYaw[i] > 360:
			rawYaw[i] -= 360	
		i = ind( i, 1 )							# Increment the buffer pointer#
	
		# Calculate the error term and the derivative of the error term
		errDer = -error							# Subtract off the old error for the derivative dn/dt = n[i] - n[i-1] where n is error
		error = (rawYaw[i] - targetYaw)				# Calculate the new error
		errDer += error							# add the new error to finish calculating the error derivative 
		actSignal = a*error + b*errDer  + 50					# calculate the actuation signal with a PD Controller
	
# diagnostics	print "error: " + str(error) + "actSignal: " + str(actSignal)  

		# Send the actuation signal to the motor driver as a PWM duty cycle (to control current)
		### Note that sending 0.5 will keep the satelite in its current position, whereas we have:
		### - A duty cycle of 0.0 will turn the satelite clockwise with maximum torque (and)
		### - A duty cycle of 1.0 will turn the satellite anticlockwise at the maximum torque
		if( actSignal > 100.0 ):
			actSignal = 100.0
		elif( actSignal < 0.0 ):
			actSignal = 0.0
		actuator.ChangeDutyCycle( actSignal )

	except:
		print "drop value"
