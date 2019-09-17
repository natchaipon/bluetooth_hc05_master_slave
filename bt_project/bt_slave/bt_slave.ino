#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial mySerial(10, 11); 
Servo myServo;
int state = 20;

void setup() {
  myServo.attach(9);
  Serial.begin(9600); 
  mySerial.begin(38400);
}

void loop() {
  
 if(mySerial.available() > 0){ 
    state = mySerial.read(); 
    Serial.println(state);
 }

 myServo.write(state);
 delay(10);

}
