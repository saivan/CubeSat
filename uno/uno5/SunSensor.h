/*
  SunSensor - a library for reading raw analog inputs from sun sensors through a 4-bit analog multiplexer
  Author: Anna Zovaro
  Date: 14th September 2014
*/

#ifndef SunSensor_c
#define SunSensor_c

#include "Arduino.h"

class SunSensor
{
  public:
    SunSensor(int * pinout, int nSensors);  // Initialises an instance of a SunSensor object.
                                            // pinout - integer array of pin assignments of the form [S1, S2, S3, S4, EN, AnalogIn]
                                            // nSensors - number of sensors (<16)
    void getSSData(int * data);   // Stores raw integer output of the AD conversion taken from each sun sensor in the array data.
    
  private:
    int _nSensors;
    int S1;
    int S2;
    int S3;
    int S4;
    int enable;
    int analogPin;
};

#endif
