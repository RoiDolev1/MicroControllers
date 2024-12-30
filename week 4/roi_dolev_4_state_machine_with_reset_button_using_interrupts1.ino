#define SET_INT0_RISING_EDGE EICRA|=((1<<ISC00)|(1<<ISC01))
#define SET_INT1_RISING_EDGE EICRA|=((1<<ISC11)|(1<<ISC10))
#define TURN_ON_1 PORTB |= 0b00100000
#define TURN_ON_2 PORTB |= 0b00010000
#define TURN_ON_3 PORTB |= 0b00001000
#define TURN_OFF_1 PORTB &= ~0b00100000
#define TURN_OFF_2 PORTB &= ~0b00010000
#define TURN_OFF_3 PORTB &= ~0b00001000
#define ENABLE_INT1 EIMSK|= (1<<INT1)
#define ENABLE_INT0 EIMSK|= (1<<INT0)

unsigned int state = 0;

void setup()
{
  cli(); // כיבוי פסיקות גלובליות
  // הגדרת הפין של הכפתור כקלט
  DDRD &= ~((1<<DDD2)|(1<<DDD3)); 
  
  // הגדרת הפין של ה-LED כפלט
  DDRB |= (1<<DDB5)|(1<<DDB4)|(1<<DDB3); 
  SET_INT0_RISING_EDGE;
  SET_INT1_RISING_EDGE;
  
  // הפעלת INT0\1
  ENABLE_INT0;
  ENABLE_INT1;
  TURN_ON_1;
  TURN_ON_2;
  TURN_ON_3;
  TURN_OFF_1;
  TURN_OFF_2;
  TURN_OFF_3;
  
  
  sei(); // הפעלת פסיקות גלובליות


  
}
void loop()
{
  
  
}
ISR(INT0_vect)
{
 TURN_OFF_1;
 TURN_OFF_2;
 TURN_OFF_3;
 state=0;
}
ISR(INT1_vect)
{
    state++;
  if (state == 8)
      state = 0; // Return to the initial state
    switch(state){
     case 0:
      TURN_OFF_1;
      TURN_OFF_2;
      TURN_OFF_3;
      break;
     case 1:
      TURN_OFF_1;
      TURN_OFF_2; // Turn OFF LED1, LED2
      TURN_ON_3; // Turn ON LED3
      break;
     case 2:
      TURN_OFF_1;
      TURN_OFF_3; // Turn OFF LED1, LED3
      TURN_ON_2; // Turn ON LED2
      break;
     case 3:
      TURN_OFF_1; // Turn OFF LED1
      TURN_ON_2;
      TURN_ON_3;// Turn ON LED2, LED3
      break;
     case 4:
      TURN_OFF_2;
      TURN_OFF_3;// Turn OFF LED2, LED3
      TURN_ON_1; // Turn ON LED1
      break;
     case 5:
      TURN_OFF_2; // Turn OFF LED2
      TURN_ON_1; 
      TURN_ON_3; // Turn ON LED1, LED3
      break;
     case 6:
      TURN_OFF_3; // Turn OFF LED3
      TURN_ON_1;
      TURN_ON_2;// Turn ON LED1, LED2
      break;
     case 7:
      TURN_ON_1;
      TURN_ON_2;
      TURN_ON_3;// Turn ON LED1, LED2, LED3
      break;
    }
  
}