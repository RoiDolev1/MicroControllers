// State Machine Implemntation

// Changing the LEDs status based on the number of times the Button S1 is pressed.
// Adding "S2" for resetting the state (to initial state).

// NOTE: Currently, this doesn't support working with simultaneous 2 buttons pressing

// You can continue by updating the previous program

// State Machine Implemntation

// Changing the LEDs status based on the number of times the Button S1 is pressed.


// State Machine Implemntation

// Changing the LEDs status based on the number of times the Button S1 is pressed.

// Initializing a global variable state with "initial state 0"
unsigned int state = 0;

void setup()
{
  // Define pins 3,2 as INPUT
  DDRD &= ~0b00001000;
   DDRD &= ~0b00000100;
  // Define pins 11,12,13 as OUTPUTs
  DDRB |= 0b00111000;
}

void loop()
{
  unsigned char btn1, btn2;
  // Extract information about pin 3
  // to find if button is pressed/released
  btn1 = PIND & 0b00001000;
  btn2 = PIND & 0b00000100;
  if (btn2 != 0) // Reset button is pressed
  {
    state = 0; // Reset state to 0
    PORTB &= ~0b00111000; // Turn OFF all LEDs
  }

  if (btn1 != 0) // button is pressed
  {
    delay(50); // basic debouncing after pressing
    // Wait while button is pressed
    // Read the value over and over again..
    while((PIND & 0b00001000) != 0);
    delay(50); // basic debouncing after releasing
    
    state++; // Increment state by 1
    if (state == 8)
      state = 0; // Return to the initial state
    switch(state){
     case 0:
      PORTB &= ~0b00111000; // Turn OFF 3 LEDS
      if(btn2=!0)
        state=0;
      break;
     case 1:
      PORTB &= ~0b00110000; // Turn OFF LED1, LED2
      PORTB |= 0b00001000; // Turn ON LED3
      break;
     case 2:
      PORTB &= ~0b00101000; // Turn OFF LED1, LED3
      PORTB |= 0b00010000; // Turn ON LED2
      break;
     case 3:
      PORTB &= ~0b00100000; // Turn OFF LED1
      PORTB |= 0b00011000; // Turn ON LED2, LED3
      break;
     case 4:
      PORTB &= ~0b00011000; // Turn OFF LED2, LED3
      PORTB |= 0b00100000; // Turn ON LED1
      break;
     case 5:
      PORTB &= ~0b00010000; // Turn OFF LED2
      PORTB |= 0b00101000; // Turn ON LED1, LED3
      break;
     case 6:
      PORTB &= ~0b00001000; // Turn OFF LED3
      PORTB |= 0b00110000; // Turn ON LED1, LED2
      break;
     case 7:
      PORTB |= 0b00111000; // Turn ON LED1, LED2, LED3
      break;
    }
    
    
  }
  
}