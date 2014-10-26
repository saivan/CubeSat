//This program uses Arduino as a slave to send a string via I2C to the RPi

#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;
String piString="";
char string[]="hello,e,gesgjesesgseg,e,sg,es,g"; //initialise string to send

void setup() {
    Serial.begin(9600);         // start serial for output
    // initialize i2c as slave
    Wire.begin(SLAVE_ADDRESS);

    // define callbacks for i2c communication

    
    Serial.println("Ready!");
}

void loop() {
  
   Wire.onReceive(receiveData);
    Serial.println(piString);
    //Wire.onRequest(sendData);
  
    delay(2000);
}

// callback for received data
void receiveData(int byteCount){
    piString="";
    while(Wire.available()) {
        piString += Wire.read();
    }        
}

// callback for sending data
void sendData(){
    
    Wire.write(string[i]);
    Serial.print("Data Sent ");
    Serial.println(string[i]);
    i++;
  }
