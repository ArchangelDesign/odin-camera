/*
    ** Odin - Camera Controller **
    copyright (c) 2021 OxBlue part of Hexagon.
    All rights reserved.
    Author: Raff Martinez-Marjanski <rmartinez@oxblue.com>

    This file is included in every other file of this project.

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

#ifndef OX_STATIC_H
#define OX_STATIC_H

#include <Arduino.h>
#include <arduino-timer.h>

#define CLK 2
#define DT 4
#define SW 3


#define BAT_SENSE 0
#define VOUT_SENSE 1
#define BAT_MIN_VOLTAGE 4.8
#define BAT_MAX_VOLTAGE 5.5
#define RESET_COUNTER_PIN 7
#define COMM_PIN_BUSY 10
#define COMM_PIN_READY 9
#define COMM_PIN_DONE 8
#define RELAY_PIN 11
#define BUZZER_PIN 12
#define OLED_RESET_PIN 4
#define RESISTOR_PIN 0
#define VOUT_PIN 1
#define MAX_OPEN_DURATION 1
#define PICTURE_PERIOD 10
#define READING_AT_10_VOLTS 460.0
#define SENSE_RESISTOR 3.3
#define FLASH_OUTPUT_BUFFER_SIZE 30
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C
#define ROM_ADDR_PIC_A_REG 0
#define ROM_ADDR_PIC_B_REG 1

const char f_oxblue_text[] PROGMEM = "* OxBLUE *";
const char f_dashes[] PROGMEM = "--------------------";
const char f_s_light[] PROGMEM = "LIGHT: %d%%";
const char f_s_uptime[] PROGMEM = "C: %d";
const char f_s_voltage[] PROGMEM = "V: %d.%02dV";

Timer<10, millis> timer;

// raff's crap
extern bool update_screen(void *);
extern bool sense_voltages(void *);
extern bool control_relay(void *);
extern bool picture_taken(void *);
extern char* flash_get(const char* str);
extern int get_light_percentage();
extern bool is_enough_light();
extern bool sense_voltages(void *);
extern bool comm_read_pins(void *);
extern bool comm_is_busy();
extern bool comm_is_ready();
extern bool comm_is_done();
extern uint16_t get_picture_count();

// Arduino crap
extern unsigned long millis();


#endif
