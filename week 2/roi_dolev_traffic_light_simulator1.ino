/*
  Simluate Light Traffic:
  1. Red Color for 10 seconds.
  2. Yellow Color for 2 seconds.
  3. Green Color for 5 seconds.
  (then yellow, and back to red..)
*/

void setup()
{
 DDRB|=0B00011100;
}

void loop()
{
 PORTB|=0b00000100;
 delay(10000);
 PORTB&=0b11111011;
  
 PORTB|=0b00001000;
 delay(2000);
 PORTB&=0b11110111;
  
 PORTB|=0b00010000;
 delay(5000);
 PORTB&=0b11101111;
  
 PORTB|=0b00001000;
 delay(2000);
 PORTB&=0b11110111;
  
}