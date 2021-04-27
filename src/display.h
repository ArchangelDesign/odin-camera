#ifndef DISPLAY_H
#define DISPLAY_H

#define LCD_RS 5
#define LCD_E 6
#define LCD_D4 7
#define LCD_D5 8
#define LCD_D6 9
#define LCD_D7 10

#include <LiquidCrystal.h>

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void printLine4(String text)
{
	lcd.setCursor(0, 3);
	lcd.print("         ");
	lcd.setCursor(0, 3);
	lcd.print(text);
}

void printLine3(String text)
{
	lcd.setCursor(0, 2);
	lcd.print("            ");
	lcd.setCursor(0, 2);
	lcd.print(text);
}

void printLine1(String text)
{
	lcd.setCursor(0, 0);
	lcd.print("            ");
	lcd.setCursor(0, 0);
	lcd.print(text);
}


void printLine2(String text)
{
	lcd.setCursor(0, 1);
	lcd.print("            ");
	lcd.setCursor(0, 1);
	lcd.print(text);
}

void printVoltage(float voltage, float amperage)
{
	printLine4("BAT: " + String(voltage) + " V " + String(amperage) + " A");
}

#endif
