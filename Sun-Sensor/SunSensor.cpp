/*
  SunSensor - a library for reading raw analog inputs from sun sensors through a 4-bit analog multiplexer
  Author: Anna Zovaro
  Date: 14th September 201
*/

#include "Arduino.h"
#include "SunSensor.h"

/* 
    Initialises an instance of a SunSensor object
    inputs:  pinout - integer array of pin assignments of the form [S1, S2, S3, S4, EN, AnalogIn]
            nSensors - number of sensors (<16)
*/
SunSensor::SunSensor(int * pinout, int nSensors)
{
  _nSensors = nSensors;
  
  S1 = pinout[0];          // select pins
  S2 = pinout[1];
  S3 = pinout[2];
  S4 = pinout[3];          
  enable = pinout[4];      // enable pin
  analogPin = pinout[5];   // input pin 
  
  for (int i = 0; i < 5; i++)
  {
    pinMode(pinout[i], OUTPUT);  // setting S1:S4 and E as output
  }

}

/*
  getSSData() - Stores raw integer output of the AD conversion taken from each sun sensor in the array data.
  inputs: data - integer array of size nSensors to store data in
 */ 
void SunSensor::getSSData(int * data)
{
   digitalWrite(enable, LOW);   // clearing enable pin to enable the MUX
   
   for (int i = 0; i < _nSensors; i++)  // looping through each multiplexer input
   {
     digitalWrite(S1, bitRead(i, 0));  // configuring the selec pins
     digitalWrite(S2, bitRead(i, 1));
     digitalWrite(S3, bitRead(i, 2));
     digitalWrite(S4, bitRead(i, 3));
     data[i] = analogRead(analogPin);  // reading data from the sun sensor
   }
   
   digitalWrite(enable, HIGH);   // setting enable pin to enable the MUX
   return;
}

