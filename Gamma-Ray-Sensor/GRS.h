/*
  GRS.h - a library for obtaining data from the gamma ray sensor.
  Author: Anna Zovaro
  Date: 13th of September, 2014
*/
#ifndef GRS_h
#define GRS_h

#include "Arduino.h"

class GRS
{
  public:
    GRS(int pin);  // class constructor
    double getVoltage(void);     // returns the voltage on the pin (0 - 5 V)
    int getAnalogReadVal(void);  // returns the raw result of the AD conversion
  private:
    int _pin;        //
    int _analogReadVal;  // AD conversion result (integer between 0 and 1023)
    double _voltage;     // AD conversion result converted to a voltage
};

#endif
