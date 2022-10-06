//
// Created by mdmbct on 10/4/22.
//

#ifndef ESP8285HEAT_COMPONENT_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "core/UIData.h"
#include "core/Ctrl.h"


#define NO_COMP 255
// 确定操作 不进行界面切换

struct Component {
    uint8_t index;
//    uint8_t previousIndex;
//    uint8_t confirmIndex;
    uint8_t nextIndex;
    char *name;
    void (*uiDataUpdater)(CtrlType ctrlType);
};

// 用来临时存储翻过去的界面
//#define MENU_STACK_MAX_SIZE 5
//struct MenuStack {
//    uint8_t indexs[MENU_STACK_MAX_SIZE];
//    // 指向栈顶元素的下一个位置 （uint_8不能为-1）
//    uint8_t top = 0;
//};
//
//MenuStack menuStack{};
//
//bool pushMenu(uint8_t index) {
//    if (menuStack.top <= MENU_STACK_MAX_SIZE - 1) {
//        menuStack.indexs[menuStack.top] = index;
//        menuStack.top++;
//        return true;
//    }
//    return false;
//}
//
//uint8_t popMenu() {
//    if (menuStack.top != 0) {
//        uint8_t index = menuStack.indexs[menuStack.top];
//        menuStack.top--;
//        return index;
//    }
//    return NO_COMP;
//}

// 界面切换
void homeSwUpdater(CtrlType ct);
extern Component homeSw;

void settingsSwUpdater(CtrlType ct);
extern Component settingsSw;

void aboutSwUpdater(CtrlType ct);
extern Component aboutSw;

void tipConfSwUpdater(CtrlType ct);
extern Component tipConfSw;

// 不同界面
void homeScrUpdater(CtrlType ct);
extern Component homeScr;

void settingsScrUpdater(CtrlType ct);
extern Component settingsScr;

void aboutScrUpdater(CtrlType ct);
extern Component aboutScr;

void tipConfScrUpdater(CtrlType ct);
extern Component tipConfScr;
//Component sysInfo = {7, 3, 3, "SYS INFO"};


// Home界面
// 当前温度
void currentTempInfoUpdater(CtrlType ct);
extern Component currentTempInfo;

// 休眠
void dormancySwUpdater(CtrlType ct);
extern Component dormancySw;

// 快速升温
void fastHeatSwUpdater(CtrlType ct);
extern Component fastHeatSw;

// 设置界面中的菜单
void volumeSetUpdater(CtrlType ct);
extern Component volumeSet;

void brightnessSetUpdater(CtrlType ct);
extern Component brightnessSet;

void screenRotateUpdater(CtrlType ct);
extern Component screenRotate;

void initTempSetUpdater(CtrlType ct);
extern Component initTempSet;

void tempStepSetUpdater(CtrlType ct);
extern Component tempStepSet;

void dormancyTempSetUpdater(CtrlType ct);
extern Component dormancyTempSet;

void stateChangeSecsUpdater(CtrlType ct);
extern Component stateChangeSecs;

void dormancyMinsSetUpdater(CtrlType ct);
extern Component dormancyMinsSet;

extern Component components[];
extern U8G2 u8g2;

#define ESP8285HEAT_COMPONENT_H

#endif //ESP8285HEAT_COMPONENT_H
