// Define a program that should:

// 1. TURN GREEN ON when Button S1 is PRESSED.
// 	  (TURN OFF when S1 released).

// 2. TURN RED LED ON when Button S2 is PRESSED.
// 	  (TURN OFF when S2 released).


void setup()
{
  // Define pins 2,3 as INPUTs
  DDRD &= ~0b00001100;
  // Define pins 12,13 as OUTPUTs
  DDRB |= 0b00110000;
}

void loop()
{
  unsigned char btn1, btn2;
  // Extract information about pin 3
  // to find if button is pressed/released
  btn1 = PIND & 0b00000100;
  if (btn1 == 0) // When the button is released
  {
    PORTB&=0b00010000; // Turn OFF GREEN LED
  	delay(50); // basic debouncing
  }
  else // When the button is pressed
  {
    PORTB|=0b00010000; // Turn ON GREEN LED
    delay(50); // basic debouncing
  }
  
  // Extract information about pin 3
  // to find if button is pressed/released
  btn2 = PIND & 0b00001000;
  if (btn2 == 0) // When the button is released
  {
    PORTB&=0b00100000; // Turn OFF RED LED
  	delay(50); // basic debouncing
  }
  else // When the button is pressed
  {
    PORTB|=0b00100000; // Turn ON RED LED
    delay(50); // basic debouncing
  }
}