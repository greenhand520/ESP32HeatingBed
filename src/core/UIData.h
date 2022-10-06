//
// Created by mdmbct on 10/1/22.
//

#ifndef ESPHEAT_UIDATA_H
#define ESPHEAT_UIDATA_H

#include <Arduino.h>

/**
 * 烙铁配置
 */
struct TipConf {
    char *name;
    uint8_t index;
    float p;
    float i;
    float d;
};

struct Settings {

    /**
     * 当前使用的烙铁配置索引
     */
    uint8_t curTipIndex = 0;

    /**
     * 休眠状态的时间 min 5 ～ 30
     */
    uint8_t dormancyMins = 20;

    /**
     * 休眠温度 ℃ 0 ～ 100
     */
    uint16_t dormancyTemp = 80;

    /**
     * 初始温度 比低温系膏熔点高几度 ℃
     */
    uint16_t initTemp = 145;

    /**
     * 温度步进 ℃ 1 ～ 10
     */
    uint8_t tempStep = 5;

    /**
     * 音量 0 ～ 10
     */
    uint8_t volume = 5;

    /**
     * 屏幕亮度
     */
    uint8_t brightness = 5;

    /**
     * 工作/休眠状态改变等待时间 第一次触发状态改变到确认状态改变的等待时间   0 ～ 30  0：关闭自动休眠
     */
    uint8_t stateChangeWaitSecs = 5;

    /**
     * 屏幕旋转
     */
    bool isRotate = false;

    TipConf tipConfs[5] = {
            {"Default", 0, 30, 0, 5},
            {"Conf2",   1, 20, 1, 5},
            {"Conf3",   2, 20, 1, 5},
            {"Conf3",   1, 20, 1, 5},
            {"Conf4",   2, 20, 1, 5}
    };
};

struct UIData {
    /**
     * 当前组件索引 默认Home界面
     */
    uint8_t curCompIndex = 1;
    /**
     * 上一个组件索引 默认Home界面图标
     */
    uint8_t lastCompIndex = 0;
    /**
     * 打开屏幕
     */
    bool onScreen = true;
    /**
     * 展示休眠图标
     */
    bool showDormancyIco = false;
    /**
     * 展示快速加热图标
     */
    bool showFastHeatIco = false;

    /**
     * 当前温度
     */
    double currentTemp;

    /**
     * 目标温度
     */
    uint16_t targetTemp;

    Settings settings = {};

};

extern UIData uiData;

#endif //ESPHEAT_UIDATA_H
