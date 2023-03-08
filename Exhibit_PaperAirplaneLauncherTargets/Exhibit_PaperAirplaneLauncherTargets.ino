#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(42, PIN, NEO_GRB + NEO_KHZ800);

bool detectorFiring = 0;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(5, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  // Power On Self Test
  rainbowCycle(10);
  colorWipe(strip.Color(0, 0, 0), 50);
  rainbowCycle(10);
  colorWipe(strip.Color(0, 0, 0), 50);
}

void loop() {
  // put your main code here, to run repeatedly: 
  detectorFiring = !digitalRead(5);  

  //Serial.println(detectorFiring); 
  //Serial.println(millis()); 
  
  if (detectorFiring == 1){    
    delay(10);
    detectorFiring = !digitalRead(5);  

    if (detectorFiring == 1){    
      rainbowCycle(5);
      colorWipe(strip.Color(0, 0, 0), 10);
      detectorFiring = 0;  
      delay(100);
    }
  }  
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
