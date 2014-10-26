//slave uno

#include <Wire.h>
#include <string.h>
#include <util/crc16.h>

#define RADIOPIN 7
#define RECEIVEPIN 12

String sunsensors;
String decoded;
String dataToPi = String ;

int startTrans=0;      //global
int checksum;    //doesn't have to be global
String receiverString; //doesn't have to be global
String decoded;  //command variable global
//int count;

 

char datastring[80];

void setup()
{
  //work as slave sender
  Wire.begin(2);                // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event
  
  //work as slave reader
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);
  
  pinMode(RECEIVERPIN, INPUT);  
  pinMode(RADIOPIN,OUTPUT);
}

void loop()
{
  sunsensors = sunsensors();
  GammaRay = GammaRay();
  
  sprintf(datastring,"~ª¦²`bpª¦¨b<information><FCS>~");
  rtty_txstring (datastring);
  Serial.println();
  
  receiverString="1101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111";
  //receiverBinary();
  decode();
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
// slave sender

void requestEvent()
{
  Wire.write(sunsensors); // respond with message of 6 bytes
                          // as expected by master
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
// slave reader

void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
}

String sunsensors() 
{
  double theta0 = 60 * PI / 180;
  double V0 = 4.99;
  double C = 2 * V0 * sin(theta0);
  
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  int sensorValue4 = analogRead(A3);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  double voltage1 = sensorValue1 * (5.0 / 1023.0);
  double voltage2 = sensorValue2 * (5.0 / 1023.0);
  double voltage3 = sensorValue3 * (5.0 / 1023.0);
  double voltage4 = sensorValue4 * (5.0 / 1023.0);
  double angle1 = asin((voltage1 - voltage2) / C) * 180 / PI;
  double angle2 = asin((voltage3 - voltage4) / C) * 180 / PI;
  
  // Sun location is with respect to face 1.
  double n1 = 1;
  int yaw = (tan(angle1) / tan(angle2)) * 180 / PI;    //n2
  int pitch = tan(angle1) * 180 / PI;    //t
  
  String yaw = String(yaw, DEC);
  String pitch = String(pitch, DEC);
  String sunsensors = String(yaw +","+ pitch);
  // print out the value you read:
  //Serial.print("sensor1 = " );
  //Serial.println(voltage1);
  //Serial.print("sensor2 = " );
  //Serial.println(voltage2);
  //Serial.print("sensor3 = " );
  //Serial.println(voltage3);
  //Serial.print("sensor4 = " );
  //Serial.println(voltage4);
  
  //Serial.println("angle1 = ");
  ///Serial.println(angle1);
  //Serial.println("angle2 = ");
  //Serial.println(angle2);
  
  Serial.print("yaw = ");
  Serial.println(yaw);
  Serial.print("pitch = ");
  Serial.println(pitch);
  Serial.print("sunsensors = ")
  Serial.println(sunsensors);
  
  return sunsensors
}

double GammaRay() {
  // put your main code here, to run repeatedly:
  int rawVal = analogRead(A5);
  double val = raw * (5.0 / 1023);
  
  Serial.print("val = ");
  Serial.println(Val);
  
  return val;
}

void receiverBinary(){


  receiverString="";

  for(int i=0;i<800;i++){ 
    //time2=micros();
    //Serial.println(time2-time1);
    // time1=micros();
    delayMicroseconds(3370);
    //delayMicroseconds(10000); // For 50 Baud uncomment this and the line below. 
    //delayMicroseconds(10142); // For some reason you can't do 20150 it just doesn't work.  
    val = digitalRead(RECEIVERPIN);    // read the input pin
    receiverString[i]=val;
    
  }

}

void decode(){
    for(int i=0;i<receiverString.length();i++){

if(((int)receiverString[i]-48)==0 && ((int)receiverString[i+9]-48)==1 && ((int)receiverString[i+10]-48)==1){
  int oct=0;
  int j;
 for(j=0;j<8;j++){
    
    oct+=(((int)receiverString[i+j+1]-48)*lround(pow(2,(j))));
    // Serial.println(((int)receiverString[i+j]-48));

  }

 char l=oct;
 if(l=='~'){
  if(startTrans==0){ 
     startTrans=1;
     decoded="";
     count=0;
     checksum=0;
    }else{
      
     if(checksum==97){Serial.println(decoded);}
     startTrans=0;
     
     
    }
 }else{
   
   
   if(startTrans==1){
     
     count++;
     checksum+=oct;
     decoded+=l;
  
}
 }
 
 i+=10;

 }
  }

  }
      
void rtty_txstring (char * string)
{
 

  noInterrupts();

  char c;
 
  c = *string++;
 
  while ( c != '\0')
  {
    rtty_txbyte (c);
    c = *string++;
  }

  interrupts();
}
 
 
void rtty_txbyte (char c)
{
  /* Simple function to sent each bit of a char to 
   	** rtty_txbit function. 
   	** NB The bits are sent Least Significant Bit first
   	**
   	** All chars should be preceded with a 0 and 
   	** proceded with a 1. 0 = Start bit; 1 = Stop bit
   	**
   	*/
 
  int i;
 
  rtty_txbit (0); // Start bit
 
  // Send bits for for char LSB first	
 
  for (i=0;i<8;i++) // Change this here 7 or 8 for ASCII-7 / ASCII-8
  {
    if (c & 1) rtty_txbit(1); 
 
    else rtty_txbit(0);	
 
    c = c >> 1;
 
  }
 
  rtty_txbit (1); // Stop bit
  rtty_txbit (1); // Stop bit
 // Serial.println();

}
 
void rtty_txbit (int bit)
{
  //time2=micros();
    //Serial.println(time2-time1);
  // time1=micros();
   //20384

  if (bit)
  {
    // high
    digitalWrite(RADIOPIN, HIGH);
  }
  else
  {
    // low
    digitalWrite(RADIOPIN, LOW);
 
  }

  delayMicroseconds(3370); // 300 baud
  //delayMicroseconds(10000); // For 50 Baud uncomment this and the line below. 
 // delayMicroseconds(10150); // For some reason you can't do 20150 it just doesn't work.
 //receiver+=digitalRead(2); // Puts the text in the datastring

}
