#include <SoftwareSerial.h>
#define BT_RX 7
#define BT_TX 8

const int sensorDOPin = 2;     
const int ledPin = 13;      


int SensorState = 0;        
SoftwareSerial HM10(BT_RX,BT_TX);

void setup() {
  
  pinMode(ledPin, OUTPUT);
 
  pinMode(sensorDOPin, INPUT);
  Serial.begin(9600);
  HM10.begin(9600);
}

void loop() {
 
  SensorState = digitalRead(sensorDOPin);

  
    if (SensorState == LOW) {
    
    digitalWrite(ledPin, LOW);
  }
  else {
    
    digitalWrite(ledPin, HIGH);
  }
  
  if (HM10.available()) {
    Serial.write(HM10.read());
  }
  if (Serial.available()) {
    HM10.write(Serial.read());
  }

}
