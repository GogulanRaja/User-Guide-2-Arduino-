#include<avr/io.h>

void setup()
{
  DDRB|=(1<<PD4); // PD4 is an output pin
}

void loop()
{
  PORTD|=(1<<PD4); // HIGH to PD4
}
