/*
    ** Odin - Camera Controller **
    copyright (c) 2021 OxBlue part of Hexagon.
    All rights reserved.
    Author: Raff Martinez-Marjanski <rmartinez@oxblue.com>

    Handles communication between microcontroller
    and Raspberry Pi that takes the pictures.
    STATES:
    - COMM_PIN_READY is HIGH: Raspberry is ready
    - COMM_PIN_BUSY is HIGH: Raspberry is taking/uploading the picture
      Power will be supplied unless this pin is LOW
    - COMM_PIN_DONE is HIGH: Raspberry is ready to be powered off
      Power will be supplied until this pin goes HIGH

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

#ifndef RASPBERRY_COMM_H
#define RASPBERRY_COMM_H

#include <Arduino.h>
#include "static.h"

uint8_t ox_camera_state = 0;
uint8_t comm_pins = 0;

bool comm_read_pins(void *) {
  if (digitalRead(COMM_PIN_READY) == HIGH)
    comm_pins |= (uint8_t)1 << 1;
  else
    comm_pins &= ~((uint8_t)1 << 1);

  if (digitalRead(COMM_PIN_BUSY) == HIGH)
    comm_pins |= (uint8_t)1 << 0;
  else
    comm_pins &= ~((uint8_t)1 << 0);

  if (digitalRead(COMM_PIN_DONE) == HIGH)
    comm_pins |= (uint8_t)1 << 2;
  else
    comm_pins &= ~((uint8_t)1 << 2);
  return true;
}

bool comm_is_busy() {
  return comm_pins & (1<<0);
}

bool comm_is_ready() {
  return comm_pins & (1<<1);
}

bool comm_is_done() {
  return comm_pins & (1<<2);
}

#endif
