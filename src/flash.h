#ifndef FLASH_H
#define FLASH_H

#include <Arduino.h>
#include "static.h"

char outputString[FLASH_OUTPUT_BUFFER_SIZE];

char* flash_get(const char* str)
{
  strcpy_P(outputString, (char*)str);
  return outputString;
}

#endif
