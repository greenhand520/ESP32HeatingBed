//
// 达到目标温度后 触发休眠的事件
// Created by mdmbct on 10/2/22.
//

#ifndef ESP8285HEAT_DORMANCYEVENT_H
#define ESP8285HEAT_DORMANCYEVENT_H

#include <Arduino.h>

class DormancyEvent {
protected:
    /**
     * 静态多少秒后开始休眠 动态多少秒后开始工作 默认5s 根据这个调节灵敏度 0 ～ 30 0：关闭休眠
     */
    uint8_t waitSecs = 5;

public:

    void setWaitSecs(uint8_t _waitSecs) {
        this->waitSecs = constrain(_waitSecs, 0, 30) * 10;
    }

    virtual bool isDormancy(unsigned long curTime) = 0;

//    virtual bool isWork(unsigned long curTime) = 0;

};

#endif //ESP8285HEAT_DORMANCYEVENT_H
