/*
  SunSensor - a library for reading raw analog inputs from sun sensors through a 4-bit analog multiplexer
  Author: Anna Zovaro
  Date: 14th September 201
*/

#include "Arduino.h"

/*
  setupSS() - configures the Arduino to obtain input from the sun sensors via an analog 4-bit multiplexer.
  inputs: pinout - integer array of pin assignments of the form [S1, S2, S3, S4, EN, AnalogIn]
*/
void setupSS(int * pinout)
{
  for (int i = 0; i < 4; i++)
  {
    pinMode(pinout[i], OUTPUT);  // setting S1:S4 and E as output
  }
}


/*
    muxSelector() - an easy way to convert a number into the correct combination
    of 1's and 0's for the multiplexer select inputs.
    output: arr - binary array
*/
int * muxSelect(int num)
{
    int arr[4];
    arr[0] = bitRead(num, 0);
    arr[1] = bitRead(num, 1);
    arr[2] = bitRead(num, 2);
    arr[3] = bitRead(num, 3);
    return arr;
}

/*
  getSSData() - Stores raw integer output of the AD conversion taken from each sun sensor in the array data.
  inputs: pinout - integer array of pin assignments of the form [S1, S2, S3, S4, EN, AnalogIn]
          nSensors - number of sensors
          data - integer array of size nSensors to store data in
 */ 
void getSSData(int * pinout, int nSensors, int * data)
{
   int S1 = pinout[0];          // select pins
   int S2 = pinout[1];
   int S3 = pinout[2];
   int S4 = pinout[3];          
   int enable = pinout[4];      // enable pin
   int analogPin = pinout[5];   // input pin
   
   digitalWrite(enable, LOW);   // clearing enable pin to enable the MUX
   
   for (int i = 0; i < nSensors; i++)  // looping through each multiplexer input
   {
     int * selectArr = muxSelect(i);   // configuring S1:S4 to select the right input
     digitalWrite(S1, selectArr[0]);
     digitalWrite(S2, selectArr[1]);
     digitalWrite(S3, selectArr[2]);
     digitalWrite(S4, selectArr[3]);
     data[i] = analogRead(analogPin);  // reading data from the sun sensor
   }
   
   digitalWrite(enable, HIGH);   // setting enable pin to enable the MUX

   return;
}
