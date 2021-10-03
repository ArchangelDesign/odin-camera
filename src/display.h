/*
    ** Odin - Camera Controller **
    copyright (c) 2021 Raff Martinez-Marjanski.
    All rights reserved.
    Author: Raff Martinez-Marjanski <archangel.raffael@gmail.com>

    Handles LCD display however it is not used any more,
		it also wastes a lot of memory.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

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
