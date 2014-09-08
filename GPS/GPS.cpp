#include <SoftwareSerial.h>
#include <stdlib.h>

#define  DEBUG 1
#undef    DEBUG
#define  BUFF_LEN 230
#define  NELMS 4      // number of output GPS data elements
#define  GPS_TX  13   // Arduino receives on this pin
#define  GPS_RX  11   // Arduino transmits on this pin

//-----------------------------------------------------------------------------------/
//------------------------------GPS CLASS METHODS------------------------------------/
//-----------------------------------------------------------------------------------/
// fills the char array buffer of size BUFF_LEN with incoming data from the GPS.
// gpsSerial is the SoftwareSerial object used to gather data over UART and
// buffer is the array storing the data.
String GPS::fillDataBuffer(char * buffer, SoftwareSerial &gpsSerial, int bufferLength)
{
  for (int i = 0; i < bufferLength; i++)
  {
    while (!(gpsSerial.available()))   // wait for data to be available over the serial
      ;
     buffer[i] = gpsSerial.read();      // store data in the buffer as it comes in
  }
  String buffStr = String(buffer);

  #ifdef  DEBUG
    Serial.println("-----------------------------------------");
    Serial.println("Raw buffer:");
    Serial.println(buffStr);
    Serial.println("-----------------------------------------");
  #endif
  
  return buffStr;  // returning the buffer in the form of a string
}
//-----------------------------------------------------------------------------------/
// Returns a string of GPS data. See NMEA encoding specifications for details.
// DataName is concatenated with the GPS identifier "$GP" -
// e.g. to access Recommended Minimum Data, DataName = "RMC"
String GPS::getDataString(String buffString, String DataName)
{
 // Serial.println();
  int startIndex = buffString.indexOf("GP" + DataName);
  String temp = buffString.substring(startIndex); // chopping off '$'
  int endIndex = temp.indexOf('*');
  
  #ifdef  DEBUG
    Serial.println("-----------------------------------------");
    Serial.println("temp: ");
    Serial.println(temp);
    Serial.println("-----------------------------------------");
  #endif
  
  // error handling
  if (startIndex == -1 || endIndex == -1)  // if string not found...
  {
    Serial.println("Error: String not found"); 
    return "";
  }
  if (startIndex == endIndex)  // if only one instance of the string found...
  {
    Serial.println("Error: String only found once"); 
    return "";
  }
  
  #ifdef DEBUG
    Serial.println("-----------------------------------------");
    Serial.println("Substring: ");
    Serial.println(temp.substring(0, endIndex));
    Serial.println("-----------------------------------------");
  #endif
  
  return temp.substring(0, endIndex);
}
//-----------------------------------------------------------------------------------/
// Parses NMEA data and returns strings containing the desired parameter as
// specified by the enum value ctr corresponding to those in the relevant ENUM
String GPS::parseData(String data, int ctr){
    String temp = data.substring(data.indexOf(',') + 1);
    for (int i = 0; i < ctr; i++)
    {
       temp = temp.substring(temp.indexOf(',') + 1);
    }
      return temp.substring(0, temp.indexOf(','));
}
//-----------------------------------------------------------------------------------/
// returns a string of the form "031350.00" (UTC time)
String GPS::getTime(String RMCData)
{
   return parseData(RMCData, TIME); 
}
//-----------------------------------------------------------------------------------/
// returns a string of the form "031350.00" (UTC time)
String GPS::getDate(String RMCData)
{
   return parseData(RMCData, DATE); 
}
//-----------------------------------------------------------------------------------/
// returns a string of the form "33.53S"
String GPS::getLatitude(String RMCData)
{
  char floatbuf[20];  // buffer for intermediate char array
  
  String latStr = parseData(RMCData, LATITUDE);
  String lat_NS = parseData(RMCData, LAT_NORTH_SOUTH); 

  latStr.toCharArray(floatbuf, 20);// CONVERT TO CHAR ARRAY
  float latitude = atof(floatbuf);  // CONVERT TO FLOAT
  char * arr = dtostrf(latitude/100, 7, 2, floatbuf);
  //String newStr;
  latStr = String(arr);
  latStr += lat_NS;
  //return latStr.concat(latStr, lat_NS);
  return latStr;
}
//-----------------------------------------------------------------------------------/
// returns a string of the form "59.93E"
String GPS::getLongitude(String RMCData)
{
  char floatbuf[20];  // buffer for intermediate char array
  
  String lonStr = parseData(RMCData, LONGITUDE);
  String lon_EW = parseData(RMCData, LON_EAST_WEST);
  lonStr.toCharArray(floatbuf, 20);// CONVERT TO CHAR ARRAY
  float longitude = atof(floatbuf);  // CONVERT TO FLOAT
  char * arr = dtostrf(longitude/100, 7, 2, floatbuf);  // check the size...
  //String newStr;
  lonStr = String(arr);
//  return lonStr.concat(lonStr, lon_EW);
  lonStr += lon_EW;
  return lonStr;
}
//-----------------------------------------------------------------------------------/
String * GPS::getGPSData(char * buffer, SoftwareSerial &gpsSerial)
{
  // fill buffer
  buffStr = fillDataBuffer(buffer, gpsSerial, BUFF_LEN);
  String RMCData = getDataString(buffStr, "RMC");
  dataStr[0] = getTime(RMCData);
  dataStr[1] = getDate(RMCData);
  dataStr[2] = getLatitude(RMCData);
  dataStr[3] = getLongitude(RMCData);
  return dataStr;
}
//-----------------------------------------------------------------------------------/













