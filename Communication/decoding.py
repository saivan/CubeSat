
# import bitarray

image = open("image.bmp",'r')
imageData = bytearray(image.read())

sendBytes = range(50)
for i in range(50):
	currentByte = imageData.pop()
	# handling the conversions
	if currentByte<94:
		currentByte=currentByte+32
	else:
		currentByte=currentByte+67
	sendBytes[i] = currentByte/2

print sendBytes
