#define SET_INT1_RISING_EDGE EICRA|=((1<<ISC11)|(1<<ISC10))
#define ENABLE_INT1 EIMSK|= (1<<INT1)

void setup()
{
  cli(); // כיבוי פסיקות גלובליות
  
  // הגדרת הפין של הכפתור כקלט
  DDRD &= ~(1<<DDD3); 
  
  // הגדרת הפין של ה-LED כפלט
  DDRB |= (1<<DDB4); 
  
  // הגדרת INT1 לפעול בכל שינוי לוגי
  SET_INT1_RISING_EDGE; 
  
  // הפעלת INT1
  ENABLE_INT1; 
  
  sei(); // הפעלת פסיקות גלובליות
}

// פונקציית שירות הפסיקה ל-INT1
ISR(INT1_vect)
{
  // החלפת מצב ה-LED
  PORTB ^= (1<<PORTB4);
}

void loop()
{
  // הלולאה הראשית נשארת ריקה, כי הפסיקה מטפלת בהכל
}