#include <string.h>
#include <util/crc16.h>
 

#define RADIOPIN 7
#define RECEIVEPIN 12   // pushbutton connected to digital pin 7


//int time1;
//int time2;
int startTrans=0;      //global
int checksum;    //doesn't have to be global
String receiverString; //doesn't have to be global
//int goodString;
String decoded;  //command variable global
int count;

 

char datastring[80];



void setup()
{
  pinMode(RECEIVERPIN, INPUT);  
  pinMode(RADIOPIN,OUTPUT);

    Serial.begin(9600);

}

void loop()
{
  
  
  sprintf(datastring,"ª¦²`bpª¦¨b<information><FCS>~");
  rtty_txstring (datastring);
  Serial.println();
  
  receiverString="1101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111101101000011011001111110110011111";
  //receiverBinary();
  decode();

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
  delay(1000);
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

   
   
