const int trigPin = 5;   
const int echoPin = 18;  
const int ledPin = 13;   

// משתנים לשמירת מצב הזמן והנורה
unsigned long previousMillis = 0; // מתי בפעם האחרונה עדכנו את הנורה
int ledState = LOW;               // המצב הנוכחי של הנורה
int blinkInterval = -1;           // מרווח ההבהוב (-1 אומר כבוי, 0 אומר דלוק קבוע)

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(ledPin, OUTPUT);  
  Serial.begin(115200); 
}

void loop() {
  // 1. שליחת גל הקול
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // 2. חישוב המרחק (הוספנו Timeout כדי שהפונקציה לא תיתקע לנצח אם אין הדהוד)
  long duration = pulseIn(echoPin, HIGH, 30000); 
  int distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // 3. עדכון ה"מצב" (קביעת קצב ההבהוב בלבד, בלי להדליק עדיין ובלי דיליי)
  if (distance >= 80 && distance <= 100) {
    blinkInterval = 250;
  } 
  else if (distance >= 50 && distance < 80) {
    blinkInterval = 125;
  } 
  else if (distance >= 20 && distance < 50) {
    blinkInterval = 62;
  } 
  else if (distance > 0 && distance < 20) {
    blinkInterval = 0; // דלוק רציף
  } 
  else {
    blinkInterval = -1; // כבוי
  }

  // 4. לוגיקת הביצוע (Non-Blocking)
  unsigned long currentMillis = millis(); // שואלים את המעבד "מה השעה?"

  if (blinkInterval == -1) {
    // מצב כבוי
    digitalWrite(ledPin, LOW);
  } 
  else if (blinkInterval == 0) {
    // מצב דלוק רציף
    digitalWrite(ledPin, HIGH);
  } 
  else {
    // מצב מהבהב: בודקים אם עבר מספיק זמן (למשל 250ms) מאז השינוי האחרון
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis; // שומרים את הזמן הנוכחי לפעם הבאה
      
      // הופכים את מצב הנורה (אם דלוק תכבה, אם כבוי תדליק)
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }
      digitalWrite(ledPin, ledState);
    }
  }
}
