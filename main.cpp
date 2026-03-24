const int trigPin = 5;   
const int echoPin = 18;  
const int ledPin = 13;   

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(ledPin, OUTPUT);  
  
  // פתיחת ערוץ תקשורת למחשב
  Serial.begin(115200); 
}

void loop() {
  // 1. שליחת גל הקול
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // 2. חישוב המרחק
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  // הדפסת המרחק למסך (כדי שיהיה לך קל לדבג)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // 3. לוגיקת ההבהובים לפי טווחים
  if (distance >= 80 && distance <= 100) {
    // הבהוב 2 פעמים בשנייה
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  } 
  else if (distance >= 50 && distance < 80) {
    // הבהוב 4 פעמים בשנייה
    digitalWrite(ledPin, HIGH);
    delay(125);
    digitalWrite(ledPin, LOW);
    delay(125);
  } 
  else if (distance >= 20 && distance < 50) {
    // הבהוב 8 פעמים בשנייה
    digitalWrite(ledPin, HIGH);
    delay(62);
    digitalWrite(ledPin, LOW);
    delay(62);
  } 
  else if (distance > 0 && distance < 20) {
    // מתחת ל-20 ס"מ - אור רציף (סכנה / קרוב מאוד)
    digitalWrite(ledPin, HIGH);
    delay(50); // השהייה קטנה רק כדי לא להציף את החיישן
  } 
  else {
    // כל השאר (מעל 100 ס"מ, או קריאה שגויה של 0) - כבוי לגמרי
    digitalWrite(ledPin, LOW);
    delay(50); // השהייה קטנה
  }
}
