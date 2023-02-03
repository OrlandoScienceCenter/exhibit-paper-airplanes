void setup() {
  // put your setup code here, to run once:
  pinMode(6, INPUT_PULLUP);
  pinMode(12, OUTPUT);  
  Serial.begin(115200);
}

unsigned long curMillis = 0;
unsigned long lastMillis = 0;
long timer = 6000;


void loop() {
  // put your main code here, to run repeatedly:
  curMillis = millis();
  if (!digitalRead(6)){
    lastMillis = curMillis;  
    // Serial.println("Pressing!");
  }
  
  if (timer + lastMillis > curMillis){
    digitalWrite(12, HIGH);  
  } else {
    digitalWrite(12, LOW);
  }

  Serial.println(); Serial.println(); Serial.println();
  Serial.println(timer + lastMillis);
  Serial.println(curMillis); 
  Serial.println(digitalRead(12));
  delay(100);
}

