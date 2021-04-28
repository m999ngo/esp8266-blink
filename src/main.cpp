#include <Arduino.h>

const int LED = LED_BUILTIN;

void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED,HIGH);
  Serial.println("HIGH");
  delay(1000);
  digitalWrite(LED,LOW);
  Serial.println("LOW");
  delay(1000);
}