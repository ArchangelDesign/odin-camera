/*
    ** Odin - Camera Controller **
    copyright (c) 2021 OxBlue part of Hexagon.
    All rights reserved.
    Author: Raff Martinez-Marjanski <rmartinez@oxblue.com>

    Controls the state of the camera. Actual turning on/off
    is located in relay_switch.h


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

#ifndef PICTURE_SNAPPER_H
#define PICTURE_SNAPPER_H

#include "static.h"
#include "rom.h"

unsigned long last_pic_time = 0;
bool first_run = true;
bool picture_snapper_active = false;

bool should_take_picture() {
  if (first_run) {
    first_run = false;
    last_pic_time = millis();
  }
  if (!is_enough_light()) {
    return false;
  }
  unsigned long diff = millis() - last_pic_time;
  diff = diff / 1000;
  diff /= 60;

  return diff >= PICTURE_PERIOD;
}

bool taking_picture() {
  picture_snapper_active = true;
  return false;
}

bool picture_taken(void *) {
  last_pic_time = millis();
  picture_snapper_active = false;
  uint8_t reg1 = rom_read(ROM_ADDR_PIC_A_REG);
  if (reg1 == 255) {
    rom_store(ROM_ADDR_PIC_B_REG, rom_read(ROM_ADDR_PIC_B_REG) + 1);
  }

  rom_store(ROM_ADDR_PIC_A_REG, rom_read(ROM_ADDR_PIC_A_REG) + 1);
  return false;
}

bool is_taking_picture() {
  return picture_snapper_active;
}

uint16_t get_picture_count() {
  uint8_t reg1 = rom_read(ROM_ADDR_PIC_A_REG);
  uint8_t reg2 = rom_read(ROM_ADDR_PIC_B_REG);
  uint16_t res = reg1 + (256 * reg2);
  return res;
}

#endif
