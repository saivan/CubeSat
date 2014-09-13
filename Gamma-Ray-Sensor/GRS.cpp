/*
  GRS.cpp - library for obtaining data from the gamma ray sensor.
  Author: Anna Zovaro
  Date: 13th of September, 2014
*/
#include "Arduino.h"
#include "GRS.h"

// intialises an instace of a GRS object
// inputs: pin - analog pin on which to connect the GRS
GRS::GRS(int pin)
{
  _pin = pin;
  pinMode(pin, INPUT);
}

// returns the raw ADC result (an integer between 0 and 1023)
int GRS::getAnalogReadVal(void)
{  
  _analogReadVal = analogRead(_pin);
  return _analogReadVal;  
}

// returns the ADC result converted to a double
double GRS::getVoltage(void)
{  
  _analogReadVal = analogRead(_pin);
  _voltage = (double) _analogReadVal / 1023 * 5.0;  // converting to a voltage between 0 and 5V
  return _voltage;  
}
