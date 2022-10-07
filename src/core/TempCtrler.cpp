//
// Created by mdmbct on 10/1/22.
//

#include "TempCtrler.h"

TempCtrler::TempCtrler(uint8_t pwmPin, bool _isPMOS) {
    this->pwmPin = pwmPin;
    pinMode(pwmPin, OUTPUT);
    this->isPMOS = _isPMOS;
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

void TempCtrler::stopHeat() const {
    if (isPMOS) {
        digitalWrite(pwmPin, HIGH);
    } else {
        digitalWrite(pwmPin, LOW);
    }
}

void TempCtrler::heat(float curTemp, float targetTemp) const {
    // todo: PID调温
    uint16_t pwmOut = 0;
    if (isPMOS) {
        digitalWrite(pwmPin, 255 - pwmOut);
    } else {
        digitalWrite(pwmPin, pwmOut);
    }
}

uint16_t TempCtrler::getAvgTemp() {
    return avgTemp;
}

