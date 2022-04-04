#include <Stepper.h> // include stepper motor library

#define stepper 32// define number of steps per revolution

#define 1  11// define stepper motor control pins
#define 2  10
#define 3   9
#define 4   8


Stepper steps(stepper, 4,3,2,1);// initialize stepper library

int Joy = A0;// joystick  output = A0

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  int JoyVal = analogRead(Joy);// read analog value from the joystick
  Serial.print(JoyVal);

  if (  (JoyVal > 235) && (JoyVal < 550) )
  {
    digitalWrite(INP1, LOW);
    digitalWrite(INP2, LOW);
    digitalWrite(INP3, LOW);
    digitalWrite(INP4, LOW);

  }

  else
  {
    
    while (JoyVal >=550)
    {
      int speed_ = map(JoyVal, 550, 1023, 5, 500);
      steps.setSpeed(speed_);
      steps.step(1);
      JoyVal = analogRead(Joy);
    }

   
    while (JoyVal <= 235)
    {
      int speed_ = map(JoyVal, 235, 0, 5, 500);
      steps.setSpeed(speed_);
      steps.step(-1);
      JoyVal = analogRead(Joy);
    }

  }

}
