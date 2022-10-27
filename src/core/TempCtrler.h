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

    TempCtrler(uint8_t pwmPin, bool isPMOS = true) : pwmPin(pwmPin), isPMOS(isPMOS) {
        pinMode(pwmPin, OUTPUT);
        // 初始化的时候 关闭加热
        stopHeat();
        // 初始化PID
        TipConf tc = uiData.settings.tipConfs[uiData.settings.curTipIndex];
        this->pid = new PID(&uiData.currentTemp, &pidOut, &setpoint, tc.p, tc.i, tc.d, DIRECT);
        // PID输出限幅
        pid->SetOutputLimits(0, 255);
        // PID控制模式
        pid->SetMode(AUTOMATIC);
    }

    void stopHeat() const {
        if (isPMOS) {
            digitalWrite(pwmPin, HIGH);
        } else {
            digitalWrite(pwmPin, LOW);
        }
    }

    /**
     * 温控调温
     * @param curTemp 几个当前温度
     * @param count 获取到的当前温度数量
     * @param targetTemp 目标温度
     */
    void heat(float curTemp, float targetTemp) const {
        // todo: PID调温
        uint16_t pwmOut = 0;
        if (isPMOS) {
            digitalWrite(pwmPin, 255 - pwmOut);
        } else {
            digitalWrite(pwmPin, pwmOut);
        }
    }

    uint16_t getAvgTemp() {
        return avgTemp;
    }

};

#endif //ESPHEAT_TEMPREG_H
