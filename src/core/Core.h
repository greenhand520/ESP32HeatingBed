//
// Created by mdmbct on 10/1/22.
//

#ifndef ESP8285HEAT_CORE_H
#define ESP8285HEAT_CORE_H

#include <Arduino.h>
#include "Buzz.h"
#include "Storage.h"
#include "DormancyEvent.h"
#include "TempCtrler.h"
#include "Ctrl.h"
#include "TempMeasure.h"
#include "UIData.h"

class Core {
private:
    Buzz *buzz;
    Ctrl *ctrl;
    DormancyEvent *dormancyEvent;
    TempMeasure *tempMeasure;
    TempCtrler *tempCtrler;
//    UIData uiData;
    // 一些状态信息
    unsigned long dormancyStartTime = UINT32_MAX;

    void heat(uint16_t targetTemp);

    void work();

    void dormancy(unsigned long curTime);

//    uint16_t avgTemp(uint16_t curTemps[], uint8_t count);

public:
    /**
     * 图形驱动之前调用
     * @param buzzPin
     * @param pwmPin
     * @param c
     * @param de
     * @param tm
     */
    Core(uint8_t buzzPin, Ctrl *c, DormancyEvent *de, TempMeasure *tm);

    void setup(uint8_t pwmPin);

    /**
     * 更新UIData 控制蜂鸣器 温度检测 温控 按键检测
     */
    void loop();
};

#endif //ESP8285HEAT_CORE_H