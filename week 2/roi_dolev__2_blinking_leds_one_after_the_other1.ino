/* Task */
/*
Design a system with 2 LEDs as specified in the attached instructions.
Develop the necessary code for this task.
Simulate and run the system.
*/


void setup()
{
 DDRB|=0b00110000; 
}

void loop()
{
 PORTB|=0b00100000;
 delay(1000);
 PORTB&=0b11011111;
 delay(1000);
 PORTB|=0b00010000;
 delay(1000);
 PORTB&=0b11101111;
 delay(1000);
  
}