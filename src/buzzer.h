#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>
#include "static.h"

void buzzer_1_beep()
{
  digitalWrite(BUZZER_PIN, HIGH);
  delay(50);
  digitalWrite(BUZZER_PIN, LOW);
  delay(50);
}

void buzzer_beep(int times)
{
  for (int i = 0; i < times; i++)
    buzzer_1_beep();
}



#endif
