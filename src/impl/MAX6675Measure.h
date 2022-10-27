//
// Created by mdmbct on 2022/10/7.
//

#ifndef ESP32HEAT_MAX6675MEASURE_H
#define ESP32HEAT_MAX6675MEASURE_H

#include <max6675.h>
#include "core/TempMeasure.h"

class MAX6675Measure : public TempMeasure {
private:
    MAX6675 max6675;

public:
    MAX6675Measure(uint8_t sckPin, uint8_t csPin, uint8_t soPin) : max6675(sckPin, csPin, soPin) {

    }

    float readTemp(uint8_t count) override {
        //    float thermocoupleCelsius = 0;
//    for (int i = 0; i < count; ++i) {
        // MAX6675更新 至少250ms
//        // 250ms => 显然不行。这里只读取1次
//        delayMicroseconds(250000);
//        thermocoupleCelsius += max6675->readCelsius();
//    }
//    return thermocoupleCelsius / (float) count;
        return max6675.readCelsius();
    }

};


#endif //ESP32HEAT_MAX6675MEASURE_H
