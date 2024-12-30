// Define a program that should use a button to switch between LEDs.

// 1. TURN GREEN LED ON & TURN RED LED OFF
//    when button is PRESSED.

// 2. TURN GREEN LED OFF & TURN RED LED ON
//    when button is RELEASED.

void setup()
{
  // Define pin 3 as INPUT
  DDRD &= ~0b00001000;
  // Define pin 12 as OUTPUT
  DDRB |= 0b00010000;
  // Define pin 13 as OUTPUT
  DDRB |= 0b00100000;
}

void loop()
{
  unsigned char result;
  result=PIND&0b00001000;
  if(result!=0)
  {
    PORTB|=0b00100000;
    PORTB&=0b00010000;
    delay(50);
  }
  	else
    {
    PORTB|=0b00010000;
    PORTB&=0b00100000;
      delay(50);
    }
}
    