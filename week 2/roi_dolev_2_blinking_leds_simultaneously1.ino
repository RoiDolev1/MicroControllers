/* Task */
/* 
Design a system with 2 LEDs as specified in the attached instructions.
Develop the necessary code for this task.
Simulate and run the system.
*/

void setup()
{
 DDRB|=0b00000011; 
}

void loop()
{
 PORTB|=0b00000001;
 PORTB|=0b00010010;
 delay(10000);
 PORTB&=0b11111110;
 PORTB&=0b11111101;
 delay(10000);
}