//
// Created by mdmbct on 2022/10/7.
//

#ifndef ESP32HEAT_MAX6675MEASURE_H
#define ESP32HEAT_MAX6675MEASURE_H

#include <max6675.h>
#include "core/TempMeasure.h"

class MAX6675Measure : public TempMeasure{
private:
    MAX6675 *max6675;

public:
    MAX6675Measure(uint8_t sckPin, uint8_t csPin, uint8_t soPin);

    float readTemp(uint8_t count) override;

};


#endif //ESP32HEAT_MAX6675MEASURE_H
