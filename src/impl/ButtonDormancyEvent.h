//
// Created by mdmbct on 2022/10/7.
//

#ifndef ESP32HEAT_BUTTONDORMANCYEVENT_H
#define ESP32HEAT_BUTTONDORMANCYEVENT_H

#include "core/DormancyEvent.h"

class ButtonDormancyEvent : public DormancyEvent{

public:

    explicit ButtonDormancyEvent(uint8_t pin);

    bool isDormancy(unsigned long curTime) override;

    void checkState();

};

#endif //ESP32HEAT_BUTTONDORMANCYEVENT_H
