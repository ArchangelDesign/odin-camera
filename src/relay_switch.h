/*
    ** Odin - Camera Controller **
    copyright (c) 2021 OxBlue part of Hexagon.
    All rights reserved.
    Author: Raff Martinez-Marjanski <rmartinez@oxblue.com>

    Controls the relay switch to turn on/off the camera

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

#ifndef RELAY_SWITCH_H
#define RELAY_SWITCH_H

#include <Arduino.h>
#include "static.h"
#include "picture_snapper.h"
#include "buzzer.h"

bool relay_state = false;
unsigned long turn_on_time = 0;

void relay_engage() {
  if (relay_state)
    return;
  digitalWrite(RELAY_PIN, HIGH);
  turn_on_time = millis();
  relay_state = true;
}

void relay_disengage() {
  digitalWrite(RELAY_PIN, LOW);
  relay_state = false;
}

int get_open_duration() {
  return (millis() - turn_on_time) / 1000 / 60;
}

void relay_tick() {
  if (relay_state && get_open_duration() >= MAX_OPEN_DURATION) {
    if (comm_is_busy()) {
      buzzer_beep(1);
      Serial.println(F("E: Camera is still busy"));
      return;
    }
    if (!comm_is_done()) {
      buzzer_beep(3);
      Serial.println(F("E: Camera is not busy and not done."));
      return;
    }
    picture_taken(NULL);
    relay_disengage();
  }
}

bool is_relay_engaged() {
  return relay_state == 1;
}

bool control_relay(void *) {
  if (should_take_picture() && !is_relay_engaged()) {
    relay_engage();
    taking_picture();
  }

  relay_tick();
  return true;
}

#endif
