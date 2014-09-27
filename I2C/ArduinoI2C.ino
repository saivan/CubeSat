//This program uses Arduino as a slave to send a string via I2C to the RPi

#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;
int i=0;
char string[]="hello,e,gesgjesesgseg,e,sg,es,g"; //initialise string to send

void setup() {
    Serial.begin(9600);         // start serial for output
    // initialize i2c as slave
    Wire.begin(SLAVE_ADDRESS);

    // define callbacks for i2c communication
    Wire.onReceive(receiveData);
    
    Wire.onRequest(sendData);
    
    Serial.println("Ready!");
}

void loop() {
    delay(100);
}

// callback for received data
void receiveData(int byteCount){

    while(Wire.available()) {
        i = Wire.read();
    }
        
}

// callback for sending data
void sendData(){
    
    Wire.write(string[i]);
    Serial.print("Data Sent ");
    Serial.println(string[i]);
    i++;
  }
