/*
  An example code to use the GPS class
  Author: Anna Zovaro
  Date: 8th September, 2014
*/

#include <SoftwareSerial.h>
#include <stdlib.h>
#include <GPS.h>

#define  BUFF_LEN 230
#define  NELMS 4      // number of output GPS data elements
#define  GPS_TX  13   // Arduino receives on this pin
#define  GPS_RX  11   // Arduino transmits on this pin

// Arduino setup
GPS gps;        // declaring a GPS object
String * data;  // data in which to store GPS values
char buffer[BUFF_LEN];  // location in which to store raw data
SoftwareSerial gpsSerial = SoftwareSerial(GPS_TX, GPS_RX);

void setup() {
  Serial.begin(115200);  // begin serial communications over pins 0 & 1
  Serial.println("U-blox NEO 6M GPS Module Data Communication");
  gpsSerial.begin(9600);   // Setup GPS
}

void loop() 
{ 
  data = gps.getGPSData(buffer, gpsSerial);
  Serial.print("Time:      "); Serial.println(data[0]);  
  Serial.print("Date:      "); Serial.println(data[1]);
  Serial.print("Latitude:  "); Serial.println(data[2]);  
  Serial.print("Longitude: "); Serial.println(data[3]); 
  Serial.println();
}
