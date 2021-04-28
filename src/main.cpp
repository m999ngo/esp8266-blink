#include <Arduino.h>

const int LED = LED_BUILTIN;
const unsigned long DELAY = 1000;

void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  static unsigned long now = millis();

  if(millis()-now > DELAY){
    now = millis();
    digitalWrite(LED,!digitalRead(LED));
    Serial.printf("STATE : %d\n",digitalRead(LED));
    }
}