/*
    ** Odin - Camera Controller **
    copyright (c) 2021 Raff Martinez-Marjanski.
    All rights reserved.
    Author: Raff Martinez-Marjanski <archangel.raffael@gmail.com>

    Senses voltage from 2 resistor dividers.
    The current is measured based on the value of SENSE_RESISTOR.

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
#ifndef VOLTAGE_SENSING_H
#define VOLTAGE_SENSING_H

#include <Arduino.h>
#include "static.h"

float resistor_voltage = 0.0;
float output_voltage = 0.0;
float output_current = 0.0;

void read_resistor_voltage() {
  int d = analogRead(RESISTOR_PIN);
  float v = d * 10 / READING_AT_10_VOLTS;
  resistor_voltage = v;
}

void read_output_voltage() {
  int d = analogRead(VOUT_PIN);
  float v = d * 10 / READING_AT_10_VOLTS;
  output_voltage = v;
}

void read_output_current() {
  output_current = (resistor_voltage - output_voltage) / SENSE_RESISTOR;
}

bool sense_voltages(void *) {
  read_resistor_voltage();
  read_output_voltage();
  read_output_current();
  return true;
}

#endif
