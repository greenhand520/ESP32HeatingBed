// 旋转编码器操作
// 参考：https://zhuanlan.zhihu.com/p/349824627?utm_id=0
// Created by mdmbct on 10/1/22.
//

#ifndef ARDUINOESPHEAT_ROTARYCTRL_H
#define ARDUINOESPHEAT_ROTARYCTRL_H

#include "core/Ctrl.h"
#include "RotaryEncoder.h"

extern Ctrl *rotaryCtrl;

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

    RotaryCtrl(uint8_t buttonPin, uint8_t aOutPin, uint8_t bOutPin) {
        pinMode(buttonPin, INPUT_PULLUP);
        pinMode(aOutPin, INPUT_PULLUP);
        pinMode(bOutPin, INPUT_PULLUP);

        this->button = OneButton(buttonPin);
        button.setDebounceTicks(25);
        button.setClickTicks(30);
        button.setPressTicks(500);
    }

    void attachButtonInterrupt() override {
        button.attachClick([]() {
            rotaryCtrl->pushCtrl(CONFIRM);
        });
        button.attachDoubleClick([]() {
            rotaryCtrl->pushCtrl(BACK);
        });
        button.attachLongPressStop([]() {
            rotaryCtrl->pushCtrl(MENU);
        });

//    attachButtonInterrupt(aOutPin, []() {
//
//    }, CHANGE);
    }
};



#endif //ARDUINOESPHEAT_ROTARYCTRL_H
