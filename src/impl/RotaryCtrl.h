// 旋转编码器操作
// 参考：https://zhuanlan.zhihu.com/p/349824627?utm_id=0
// Created by mdmbct on 10/1/22.
//

#ifndef ARDUINOESPHEAT_ROTARYCTRL_H
#define ARDUINOESPHEAT_ROTARYCTRL_H

#include "core/Ctrl.h"
#include "RotaryEncoder.h"

class RotaryCtrl : public Ctrl {

private:
    uint8_t buttonPin;
    uint8_t aOutPin;
    uint8_t bOutPin;
    OneButton button;
    /**
     * 脉冲计数
     */
    int count;

public:

    RotaryCtrl(uint8_t buttonPin, uint8_t aOutPin, uint8_t bOutPin);

    void attachButtonInterrupt() override;
};

extern Ctrl *rotaryCtrl;

#endif //ARDUINOESPHEAT_ROTARYCTRL_H
