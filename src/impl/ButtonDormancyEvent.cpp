//
// Created by mdmbct on 2022/10/7.
//

#include "ButtonDormancyEvent.h"

ButtonDormancyEvent::ButtonDormancyEvent(uint8_t _pin) {
    this->pin = _pin;
    pinMode(pin, INPUT_PULLUP);
}

bool ButtonDormancyEvent::isDormancy(unsigned long curTime) {
    return false;
}

void ButtonDormancyEvent::checkState() {

}
