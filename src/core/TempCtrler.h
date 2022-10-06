//
// 温度控制
// Created by mdmbct on 10/1/22.
//

#ifndef ESPHEAT_TEMPREG_H
#define ESPHEAT_TEMPREG_H

#include <Arduino.h>
#include <PID_v1.h>
#include "UIData.h"

class TempCtrler {
private:
    uint8_t pwmPin;
    bool isPMOS = true;
    uint16_t avgTemp = 0;
    PID *pid;
    double pidOut = 0;
    double setpoint = 0;
public:

    TempCtrler(uint8_t pwmPin, bool _isPMOS);

    void stopHeat() const;

    /**
     * 温控调温
     * @param curTemp 几个当前温度
     * @param count 获取到的当前温度数量
     * @param targetTemp 目标温度
     */
    void heat(uint16_t curTemp, uint16_t targetTemp);

    uint16_t getAvgTemp();

};

#endif //ESPHEAT_TEMPREG_H
