/*
    ** Odin - Camera Controller **
    copyright (c) 2021 Raff Martinez-Marjanski.
    All rights reserved.
    Author: Raff Martinez-Marjanski <archangel.raffael@gmail.com>

    Responsible for operating on the display.
    Note that it requires a lot of RAM and it will lock up the chip
    if the initialization process failed. Keep your RAM usage below 840 bytes

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

#ifndef COLOR_DISPLAY_H
#define COLOR_DISPLAY_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "static.h"
#include "voltage_sensing.h"
#include "relay_switch.h"
#include "picture_snapper.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET_PIN);

void print_home_screen()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.setTextColor(SSD1306_WHITE);
  display.println(flash_get(f_oxblue_text));
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.println(flash_get(f_dashes));
}

void color_display_init() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();
  display.drawPixel(10, 10, SSD1306_WHITE);
  display.display();
}

void print_line8(char *text) {
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
  display.setCursor(2, 20);
  display.print(text);
  display.display();
}

void print_to_screen(int x, int y, char *text)
{
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.print(text);
}

void print_to_screen_big(int x, int y, char *text) {
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.print(text);
}

void clear_screen() {
  display.clearDisplay();
}

void refresh_screen() {
  display.display();
}

bool update_screen(void *) {
  clear_screen();
  print_home_screen();
  char buf[20];
  sprintf(buf, flash_get(f_s_light), get_light_percentage());
  print_to_screen(0, 25, buf);
  sprintf(buf, flash_get(f_s_uptime), get_picture_count());
  print_to_screen(67, 25, buf);
  sprintf(buf, flash_get(f_s_voltage), (unsigned int)resistor_voltage, (unsigned int)(resistor_voltage*100)%100);
  print_to_screen(0, 35, buf);
  if (is_relay_engaged()) {
    sprintf(buf, "ON");
  } else {
    sprintf(buf, "OFF");
  }
  print_to_screen_big(0, 45, buf);
  if (is_taking_picture()) {
    sprintf(buf, "PIC");
    print_to_screen(65, 45, buf);
  }
  refresh_screen();
  return true;
}

#endif
