#include <Wire.h>

#define address 0x04
int number;
char GPSString[255];
int i=0;

void setup()
{
  Wire.begin(address);                // join i2c bus with address #4
  Wire.onReceive(receiveData); // register event
  Serial.begin(9600);         // start serial for output
  Serial.println("hello!");
}
 
void loop() {
  delay(100);

}
 
void receiveData(int byteCount){
   while(Wire.available()) {
      number=Wire.read();
      GPSString[i]=(char)number;
      i++;
      if (number==0){                  //If number is null, then print string and reset counter to 0.
          Serial.println(GPSString);
          i=0;
      }
   }
}

