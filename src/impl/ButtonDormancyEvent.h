//
// Created by mdmbct on 2022/10/7.
//

#ifndef ESP32HEAT_BUTTONDORMANCYEVENT_H
#define ESP32HEAT_BUTTONDORMANCYEVENT_H

#include "core/DormancyEvent.h"

class ButtonDormancyEvent : public DormancyEvent{
private:
    uint8_t pin;

public:

    explicit ButtonDormancyEvent(uint8_t pin) {
        this->pin = pin;
        pinMode(pin, INPUT_PULLUP);
    }

    bool isDormancy(unsigned long curTime) override {
        return false;
    }

    void checkState() {

    }

};

#endif //ESP32HEAT_BUTTONDORMANCYEVENT_H
