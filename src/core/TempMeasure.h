//
// 测温
// Created by mdmbct on 10/1/22.
//

#ifndef ESPHEAT_TEMPMEASURE_H
#define ESPHEAT_TEMPMEASURE_H

#include "Arduino.h"

class TempMeasure {

public:

    /**
     * 获取count次的温度值 返回的count次的平均值
     * @param count
     * @return
     */
    virtual uint16_t readTemp(uint8_t count) = 0;


};

#endif //ESPHEAT_TEMPMEASURE_H
