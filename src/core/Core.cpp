//
// Created by mdmbct on 10/1/22.
//
#include "Core.h"

Core::Core(uint8_t buzzPin, Ctrl *c, DormancyEvent *de, TempMeasure *tm) {
    this->ctrl = c;
    this->dormancyEvent = de;
    this->tempMeasure = tm;
    this->buzz = new Buzz(buzzPin, uiData.settings.volume);
    // 加载uiData.settings
    loadSettings(uiData.settings);
}

void Core::setup(uint8_t pwmPin) {
    ctrl->attachButtonInterrupt();
    dormancyEvent->setWaitSecs(uiData.settings.stateChangeWaitSecs);
    uiData.targetTemp = uiData.settings.initTemp;
    // 开机音效
    buzz->setMelody(BOOT_MELODY);
    // 先测温 为温控初始化做准备
    uiData.currentTemp = tempMeasure->readTemp(10);
    this->tempCtrler = new TempCtrler(pwmPin, true);
}

void Core::heat(uint16_t targetTemp) {
    if (targetTemp == 0) {
        tempCtrler->stopHeat();
    } else {
        // 调温 读取温度前停止加热
        tempCtrler->stopHeat();
//        uint16_t temp = tempMeasure->readTemp(10);
        tempCtrler->heat(tempMeasure->readTemp(10), targetTemp);
    }
    // 更新UI数据
    uiData.currentTemp = tempCtrler->getAvgTemp();
}

void Core::work() {
    uiData.onScreen = true;
    dormancyStartTime = UINT32_MAX;
    // 展示休眠图标
    uiData.showDormancyIco = false;
    heat(uiData.targetTemp);
}

void Core::dormancy(unsigned long curTime) {
    if (curTime - dormancyStartTime > uiData.settings.dormancyMins * 60000) {
        // 停止加热
        heat(0);
        buzz->setMelody(DORMANCY_MELODY);
        // 关闭屏幕
        uiData.onScreen = false;
    } else {
        // 展示休眠图标
        uiData.showDormancyIco = true;
        heat(uiData.settings.dormancyTemp);
    }
}

void Core::loop() {
    // 检查状态
    unsigned long curTime = millis();
    if (dormancyEvent->isDormancy(curTime)) {
        if (dormancyStartTime == UINT32_MAX) {
            // 刚触发 经过设定的等待时间后）
            dormancyStartTime = curTime;
            buzz->setMelody(DORMANCY_MELODY);
        }
        dormancy(curTime);
    } else {
        work();
    }

    // 播放声音
    buzz->play();

    // 取操作 到屏幕显示时候 再删除当前操作
    CtrlType ct = ctrl->curCtrl();
    switch (ct) {
        case PREVIOUS:
            buzz->setMelody(CLICK_MELODY);
            break;
        case NEXT:
            buzz->setMelody(CLICK_MELODY);
            break;
        case MENU:
            buzz->setMelody(MENU_CLICKED_MELODY);
            break;
        case CONFIRM:
            buzz->setMelody(CONFIRM_CLICKED_MELODY);
            break;
        case BACK:
            buzz->setMelody(CLICK_MELODY);
            break;
        default:
            break;
    }
}











