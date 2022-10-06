//
// Created by mdmbct on 10/1/22.
//

#include "RotaryCtrl.h"

RotaryCtrl::RotaryCtrl(uint8_t buttonPin, uint8_t aOutPin, uint8_t bOutPin) : buttonPin(buttonPin), aOutPin(aOutPin),
                                                                              bOutPin(bOutPin) {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(aOutPin, INPUT_PULLUP);
    pinMode(bOutPin, INPUT_PULLUP);

    this->button = OneButton(buttonPin);
    button.setDebounceTicks(25);
    button.setClickTicks(30);
    button.setPressTicks(500);
}

void RotaryCtrl::attachButtonInterrupt() {
    button.attachClick([]() {
        rotaryCtrl->pushCtrl(CONFIRM);
    });
    button.attachDoubleClick([]() {
        rotaryCtrl->pushCtrl(BACK);
    });
    button.attachLongPressStop([]() {
        rotaryCtrl->pushCtrl(MENU);
    });

//    attachButtonInterrupt(aOutPin, []() {
//
//    }, CHANGE);
}


