#define buttonPin D1   
#define pinLed D2

unsigned long startTime;            // משתנה לשמירת זמן תחילת הלחיצה
unsigned long endTime;              // משתנה לשמירת זמן סיום הלחיצה
unsigned long totalTime;            //משתנה לשמירת הפרש הזמן מתחילת לחיצה לסיות לחיצה
unsigned long lastPresses[10];      // מערך לשמירת 10 הלחיצות האחרונות
int idx = 0;
bool arrayIsFull = false;       // משתנה לשמירת מצב הביצועים

void setup() {
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(pinLed,OUTPUT);
  Serial.begin(9600);
  wifiClient_Setup();
}

void loop() {
  BTN_Pressing();

}

void BTN_Pressing(){
  if(digitalRead(buttonPin)==LOW){
    startTime = millis();
    digitalWrite(pinLed,HIGH);
    Serial.println("is pressing");
  while(digitalRead(buttonPin)==LOW);
  delay(50);
  digitalWrite(pinLed,LOW);
  endTime = millis();
  totalTime = endTime - startTime;
  saveLastTeenPressed();
  Serial.print("Total time is: ");
  Serial.println(totalTime);
  }
}
