#include <FastLED.h>

const int LED_PIN = 8;
const int MAX_LEDS = pow(2, 6);
int num_leds = 0;

const int DIP1 = 2;
const int DIP2 = 3;
const int DIP3 = 4;
const int DIP4 = 5;
const int DIP5 = 6;
const int DIP6 = 7;

CRGB leds[MAX_LEDS];

int rainbowR[7] = {255, 255, 255,   0,   0,  75, 148};
int rainbowG[7] = {0,   127, 255, 255,   0,   0,   0};
int rainbowB[7] = {0,     0,   0,   0, 255, 130, 211};
int rainbowI = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("\nSerial begin...");
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, MAX_LEDS);
  
  pinMode(DIP1, INPUT_PULLUP);
  pinMode(DIP2, INPUT_PULLUP);
  pinMode(DIP3, INPUT_PULLUP);
  pinMode(DIP4, INPUT_PULLUP);
  pinMode(DIP5, INPUT_PULLUP);
  pinMode(DIP6, INPUT_PULLUP);

  Serial.println("Is DIP1?");
  if (digitalRead(DIP1) == LOW) {
    Serial.println("Adding DIP1...");
    num_leds += 1;
  }
  Serial.println("Is DIP2?");
  if (digitalRead(DIP2) == LOW) {
    Serial.println("Adding DIP2...");
    num_leds += 2;
  }
  Serial.println("Is DIP3?");
  if (digitalRead(DIP3) == LOW) {
    Serial.println("Adding DIP3...");
    num_leds += 4;
  }
  Serial.println("Is DIP4?");
  if (digitalRead(DIP4) == LOW) {
    Serial.println("Adding DIP4...");
    num_leds += 8;
  }
  Serial.println("Is DIP5?");
  if (digitalRead(DIP5) == LOW) {
    Serial.println("Adding DIP5...");
    num_leds += 16;
  }
  Serial.println("Is DIP6?");
  if (digitalRead(DIP6) == LOW) {
    Serial.println("Adding DIP6...");
    num_leds += 32;
  }

  Serial.println("num_leds: " + String(num_leds));

}

void loop() {
/* TEMPLATE
  leds[i] = CRGB(R, G, B);
  FastLED.show();
  delay(500);
*/

  //*
  for (int i = 0; i < num_leds; ++i) {
    leds[i] = CRGB(rainbowR[rainbowI], rainbowG[rainbowI], rainbowB[rainbowI]);
    FastLED.show();
    delay(45);

    rainbowI = (rainbowI + 1) % 7;
  }
  //*/
}