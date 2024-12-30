void setup()
{
  DDRD &= ~0b00000100; // configure pin 2 INPUT
  DDRB |= 0b00100000; // configure pin 13 OUTPUT
}
void loop()
{
unsigned char btn;

btn = PIND & 0b00000100;
if (btn != 0)
{
  delay(50);
  PORTB |= 0b00100000; // Turn ON LED
  
  while((PIND & 0b00000100) != 0);
  delay(50);
  PORTB &= ~0b00100000; // Turn OFF LED

}
}

