//
// Created by mdmbct on 2022/10/7.
//

#include "MAX6675Measure.h"

MAX6675Measure::MAX6675Measure(uint8_t sckPin, uint8_t csPin, uint8_t soPin) {
    this->max6675 = new MAX6675(sckPin, csPin, soPin);
}

float MAX6675Measure::readTemp(uint8_t count) {
//    float thermocoupleCelsius = 0;
//    for (int i = 0; i < count; ++i) {
          // MAX6675更新 至少250ms
//        // 250ms => 显然不行。这里只读取1次
//        delayMicroseconds(250000);
//        thermocoupleCelsius += max6675->readCelsius();
//    }
//    return thermocoupleCelsius / (float) count;
    return max6675->readCelsius();
}
