#define SET_INT0_ANY_LOGICAL_CHANGE EICRA|=(1<<ISC00)
#define ENABLE_INT0 EIMSK|= (1<<INT0)

void setup()
{
  cli(); // כיבוי פסיקות גלובליות
  
  // הגדרת הפין של הכפתור כקלט
  DDRD &= ~(1<<DDD2); 
  
  // הגדרת הפין של ה-LED כפלט
  DDRB |= (1<<DDB5); 
  
  // הגדרת INT0 לפעול בכל שינוי לוגי
  SET_INT0_ANY_LOGICAL_CHANGE; 
  
  // הפעלת INT0
  ENABLE_INT0; 
  
  sei(); // הפעלת פסיקות גלובליות
}

// פונקציית שירות הפסיקה ל-INT0
ISR(INT0_vect)
{
  // החלפת מצב ה-LED
  PORTB ^= (1<<PORTB5);
}

void loop()
{
  
}