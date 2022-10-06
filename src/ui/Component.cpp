//
// Created by mdmbct on 10/4/22.
//

#include "Component.h"

void nextClickedUpdater(Component curComp) {
    uiData.lastCompIndex = curComp.index;
    uiData.curCompIndex = curComp.nextIndex;
}

void homeSwUpdater(CtrlType ct) {

    switch (ct) {
        case PREVIOUS:
            uiData.curCompIndex = 3;
            uiData.lastCompIndex = 0;
            break;
        case NEXT:
            nextClickedUpdater(components[uiData.curCompIndex]);
            break;
        case CONFIRM:
            break;
        default:
            break;
    }
}

void settingsSwUpdater(CtrlType ct) {

}

void aboutSwUpdater(CtrlType ct) {

}

void tipConfSwUpdater(CtrlType ct) {

}

void homeScrUpdater(CtrlType ct) {

}

void settingsScrUpdater(CtrlType ct) {

}

void aboutScrUpdater(CtrlType ct) {

}

void tipConfScrUpdater(CtrlType ct) {

}

void currentTempInfoUpdater(CtrlType ct) {

}

void dormancySwUpdater(CtrlType ct) {

}

void fastHeatSwUpdater(CtrlType ct) {

}

void volumeSetUpdater(CtrlType ct) {

}

void brightnessSetUpdater(CtrlType ct) {

}

void screenRotateUpdater(CtrlType ct) {

}

void initTempSetUpdater(CtrlType ct) {

}

void tempStepSetUpdater(CtrlType ct) {

}

void dormancyTempSetUpdater(CtrlType ct) {

}

void stateChangeSecsUpdater(CtrlType ct) {

}

void dormancyMinsSetUpdater(CtrlType ct) {

}

// 界面切换
Component homeSw = {0, 1, "HOME", homeSwUpdater};
Component settingsSw = {1, 2, "SETTINGS", settingsSwUpdater};
Component aboutSw = {2, 3, "ABOUT", aboutSwUpdater};
Component tipConfSw = {3, 0, "TIP CONFIG", tipConfSwUpdater};

// 不同界面
Component homeScr = {4, NO_COMP, "", homeScrUpdater};
Component settingsScr = {5, NO_COMP, "", settingsScrUpdater};
Component aboutScr = {6, NO_COMP, "", aboutScrUpdater};
Component tipConfScr = {7, NO_COMP, "", tipConfScrUpdater};
//Component sysInfo = {7, 3, 3, "SYS INFO"};

// Home界面
// 当前温度
Component currentTempInfo = {8, 9, "", currentTempInfoUpdater};
// 休眠
Component dormancySw = {9, 10, "", dormancySwUpdater};
// 快速升温
Component fastHeatSw = {10, 8, "", fastHeatSwUpdater};

// 设置界面中的菜单
Component volumeSet = {11, 12, "Volume: ", volumeSetUpdater};
Component brightnessSet = {12, 13, "Brightness: ", brightnessSetUpdater};
Component screenRotate = {13, 14, "Screen Rotate: ", screenRotateUpdater};
Component initTempSet = {14, 15, "Init Temperature: ", initTempSetUpdater};
Component tempStepSet = {15, 16, "Temperature Step: ", tempStepSetUpdater};
Component dormancyTempSet = {16, 17, "Dormancy Temperature: ", dormancyTempSetUpdater};
Component stateChangeSecs = {17, 18, "State Change Wait Secs: ", stateChangeSecsUpdater};
Component dormancyMinsSet = {18, 19, "Dormancy Mins: ", dormancyMinsSetUpdater};

Component components[] = {
        homeSw, settingsSw, aboutSw, tipConfSw,
        homeScr, settingsScr, aboutScr, tipConfScr,
        currentTempInfo, dormancySw, fastHeatSw,
        volumeSet, brightnessSet, screenRotate, initTempSet, tempStepSet, dormancyTempSet, stateChangeSecs,
        dormancyMinsSet
};
