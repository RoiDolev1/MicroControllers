
void setup()
{
  DDRD &=~0b00000100; // configure pin 2 INPUT
  DDRB |=0b00100000; // configure pin 13 OUTPUT
}


void loop()
{
  unsigned char result;
  result = PIND & 0b00000100;
  if (result == 0) // When the button is released 
    PORTB &= ~0b00100000; // Turn OFF LED
  else
    PORTB |= 0b00100000; // Turn ON LED
}