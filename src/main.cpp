#include <Arduino.h>
#include <ESP8266WiFi.h>

const uint LED = LED_BUILTIN;

// Le code de la fonction est mis en RAM au lieu d'être en Flash
// important car une interruption peut-être utilisée n'importe quand
// la fonction est invoquée sans accès à la mémoire Flash
void ICACHE_RAM_ATTR toogleLED(void)
{
  // TODO : la routine d'interruption doit faire clignoter la LED
  digitalWrite(LED,!digitalRead(LED));
}



void setup()
{
  pinMode(LED, OUTPUT);
  
  timer1_attachInterrupt(toogleLED);
  // horloge à 80 MHz
  // diviseur par 16 => la fréquence est de 5 Mz (période de 0.2 µs)
  timer1_enable(TIM_DIV16,TIM_EDGE,TIM_LOOP);
  // comptage de 1 000 000 µs / 0.2 µs pour 1 seconde (soit la fréquence dans ce cas)
  timer1_write(5000000);
}

void loop() {
  // put your main code here, to run repeatedly:
}