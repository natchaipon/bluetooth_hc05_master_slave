#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); 


int state = 0;
int potValue = 0;
void setup() {

  mySerial.begin(38400); 
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) { 
    state = Serial.read(); 
  }

  potValue = analogRead(A0);
  Serial.println(potValue);
  int potValueMapped = map(potValue, 0, 1023, 0, 160);
  mySerial.write(potValueMapped); 
  delay(10);
}
