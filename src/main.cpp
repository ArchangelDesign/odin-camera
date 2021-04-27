/*
    ** Odin - Camera Controller **
    copyright (c) 2021 OxBlue part of Hexagon.
    All rights reserved.
    Author: Raff Martinez-Marjanski <rmartinez@oxblue.com>

    Designed to be used with Arduino Nano with 2KB of RAM
    Note that the memory cannot get above 800 bytes otherwise
    the color display will not be initialized in which case
    the chip will lock up.


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

#include <Arduino.h>

#include "static.h"
#include "flash.h"
#include "color_display.h"
#include "buzzer.h"
#include "light_sensor.h"
#include "voltage_sensing.h"
#include "relay_switch.h"
#include "picture_snapper.h"
#include "raspberry_comm.h"

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(COMM_PIN_BUSY, INPUT);
  pinMode(COMM_PIN_READY, INPUT);
  pinMode(COMM_PIN_DONE, INPUT);
  pinMode(RESET_COUNTER_PIN, INPUT);
  analogReference(DEFAULT);
  Serial.begin(9600);
  delay(100);
  buzzer_beep(3);
  timer.every(1000, update_screen);
  timer.every(500, sense_voltages);
  timer.every(1000, control_relay);
  timer.every(1000, comm_read_pins);
  delay(100);
  color_display_init();
  print_home_screen();
  buzzer_beep(2);
  if (digitalRead(RESET_COUNTER_PIN) == HIGH) {
    buzzer_beep(7);
    rom_store(ROM_ADDR_PIC_A_REG, 0);
    rom_store(ROM_ADDR_PIC_B_REG, 0);
  }
}

void loop() {
  timer.tick();
}
