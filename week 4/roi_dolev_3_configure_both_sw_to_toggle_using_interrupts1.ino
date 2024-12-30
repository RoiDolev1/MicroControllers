#define SET_INT0_RISING_EDGE EICRA|=((1<<ISC00)|(1<<ISC01))
#define SET_INT1_ANY_LOGICAL_CHANGE EICRA|=(1<<ISC10)
#define ENABLE_INT1 EIMSK|= (1<<INT1)
#define ENABLE_INT0 EIMSK|= (1<<INT0)

void setup()
{
  cli(); // כיבוי פסיקות גלובליות
  
  // הגדרת הפין של הכפתור כקלט
  DDRD &= ~((1<<DDD2)|(1<<DDD3)); 
  
  // הגדרת הפין של ה-LED כפלט
  DDRB |= (1<<DDB5)|(1<<DDB4); 
  
  // הגדרת INT0\1 לפעול בכל שינוי לוגי
  SET_INT1_ANY_LOGICAL_CHANGE; 
  SET_INT0_RISING_EDGE;
  
  // הפעלת INT0\1
  ENABLE_INT0;
  ENABLE_INT1; 

  
  sei(); // הפעלת פסיקות גלובליות
}

// פונקציית שירות הפסיקה ל-INT0
ISR(INT0_vect)
{
  // החלפת מצב ה-LED
  PORTB ^= (1<<PORTB4);
}
ISR(INT1_vect)
{
  // החלפת מצב ה-LED
  PORTB ^= (1<<PORTB5);
}

void loop()
{
  
}