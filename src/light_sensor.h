/*
    ** Odin - Camera Controller **
    copyright (c) 2021 Raff Martinez-Marjanski.
    All rights reserved.
    Author: Raff Martinez-Marjanski <archangel.raffael@gmail.com>

    Reads the light sensor to allow camera to save energy when
    the battery is low and not much light.

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
#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <Arduino.h>
#include "static.h"

#define SENSOR_PIN 7
#define MAX_LIGHT_SENSOR_VALUE 800
#define MIN_LIGHT_SENSOR_VALUE 50

int get_light_percentage() {
  int value = analogRead(SENSOR_PIN);
  if (value < MIN_LIGHT_SENSOR_VALUE)
    return 100;
  if (value > MAX_LIGHT_SENSOR_VALUE)
    return 0;
  long buf = value - 50;
  buf = 800 - buf;
  return (buf * 100) / 800;
}

bool is_enough_light() {
  return get_light_percentage() > 25;
}

#endif
