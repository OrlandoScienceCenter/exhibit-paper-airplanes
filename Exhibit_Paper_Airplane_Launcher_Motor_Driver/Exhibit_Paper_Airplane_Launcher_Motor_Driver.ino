#define PIN_RELAY 5
#define PIN_TEST_BUTTON 4
#define PIN_EXTERNAL_BUTTON 2

unsigned long curMillis = 0;
unsigned long lastMillis = 0;

long timer = 6000;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);  
  pinMode(PIN_RELAY, OUTPUT);  

  pinMode(PIN_TEST_BUTTON, INPUT_PULLUP);  
  pinMode(PIN_EXTERNAL_BUTTON, INPUT_PULLUP);  

  Serial.begin(115200);
}

void loop()
{
  curMillis = millis();

  if (!digitalRead(PIN_EXTERNAL_BUTTON) ||
      !digitalRead(PIN_TEST_BUTTON))
  {
    lastMillis = curMillis;  
  }
  
  if (timer + lastMillis > curMillis)
  {
    digitalWrite(LED_BUILTIN, HIGH);  
    digitalWrite(PIN_RELAY, HIGH);
  } 
  else 
  {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(PIN_RELAY, LOW);
  }

  Serial.println(); Serial.println(); Serial.println();
  Serial.println(timer + lastMillis);
  Serial.println(curMillis); 
  Serial.println(digitalRead(PIN_EXTERNAL_BUTTON));

  delay(100);
}

void turnOnRelay()
{
  digitalWrite(LED_BUILTIN, HIGH);

}