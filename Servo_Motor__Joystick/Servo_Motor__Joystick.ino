#include <Servo.h>
const int X_axe = A0; // analog pin connected to Y output

Servo myservo;  

int Val;    

void setup() {
  myservo.attach(8); 
}

void loop() {
  Val = analogRead(X_axe);            
  Val = map(Val, 0, 1023, 0, 180);     
  myservo.write(Val);                  
  delay(15);                           
}
