int inPin = 2;   // pushbutton connected to digital pin 7
int outPin = 7;   // pushbutton connected to digital pin 7
int time1;
int time2;






#define RADIOPIN 9
 
#include <string.h>
#include <util/crc16.h>
 
char datastring[80];
String receiverString;




void setup()
{
  pinMode(inPin, INPUT);      // sets the digital pin 7 as input
  pinMode(RADIOPIN,OUTPUT);

    Serial.begin(9600);

}

void loop()
{
  
receiverString="";
  
  //
  // receiver loop
  //
  // ">>>>" used to sync timing between satellite and ground station.
  //
  
  
  //>>>>>>time1=micros();
  int i;
  int val;

//  for(i=0;i<80;i++){
//  
//  
//    
//  delayMicroseconds(10000); // For 50 Baud uncomment this and the line below. 
//  delayMicroseconds(10142); // For some reason you can't do 20150 it just doesn't work.
//  val = digitalRead(inPin);    // read the input pin
//  
//  receiverString[i]=val;
//  
//  Serial.print(val);         // print as an ASCII-encoded decimal
//  
//  }
//  

      sprintf(datastring,"~a~"); // Puts the text in the datastring
      rtty_txstring (datastring);
      rtty_txstring (datastring);
      rtty_txstring (datastring);

    Serial.println(datastring);

  
for(i=0;i<90;i++){

if(((int)receiverString[i]-48)==0 && ((int)receiverString[i+8]-48)==1 && ((int)receiverString[i+9]-48)==1){


  int oct=0;
  int j;
 for(j=0;j<7;j++){
    
    oct+=(((int)receiverString[i+j]-48)*lround(pow(2,(6-j))));
     Serial.println(((int)receiverString[i+j]-48));

  }
    // Serial.println(oct);

 char l=oct;
    Serial.println("l");
    Serial.println(" ");
    i+=9;

 }
  }
    Serial.println(receiverString);
 
  delay(3000);
  //>>>>>time2=micros();
  //>>>>>>Serial.println(time2-time1);
  
  
  
  
  
  
  
  
  
  
  
  
  
  //
  //  Transmission loop
  //
  
  
//    sprintf(datastring,"aaaaaaaa"); // Puts the text in the datastring
//    rtty_txstring (datastring);
//    delay(1000);
//    
    
    
    
    
    

}




void rtty_txstring (char * string)
{

  /* Simple function to sent a char at a time to 
   	** rtty_txbyte function. 
   	** NB Each char is one byte (8 Bits)
   	*/
 	//noInterrupts(); // We need accurate timing!

  char c;
 
  c = *string++;
 
  while ( c != '\0')
  {

    rtty_txbyte (c);

    c = *string++;
  }


	//interrupts();



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
 
  for (i=0;i<7;i++) // Change this here 7 or 8 for ASCII-7 / ASCII-8
  {
    if (c & 1) rtty_txbit(1); 
 
    else rtty_txbit(0);	
 
    c = c >> 1;
 
  }
 
  rtty_txbit (1); // Stop bit
  rtty_txbit (1); // Stop bit
  
  
  
}
 
void rtty_txbit (int bit)
{
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
  //                  delayMicroseconds(3370); // 300 baud
  delayMicroseconds(10000); // For 50 Baud uncomment this and the line below. 
  delayMicroseconds(10150); // For some reason you can't do 20150 it just doesn't work.
   //Serial.print(String(bit,DEC));


}
