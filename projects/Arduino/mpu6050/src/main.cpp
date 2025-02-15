#include <Arduino.h>
#include "../inc/mpu6050.h"

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (equal_2() == 2){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}

