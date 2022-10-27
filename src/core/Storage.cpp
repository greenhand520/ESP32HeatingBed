//
// Created by mdmbct on 2022/10/27.
//
#include "Storage.h"

// 来自：https://github.com/esp8266/Arduino/issues/1539
void storeStruct(void *data_source, size_t size) {
    // 申请具体大小的ram内存空间并从flash中读取相应数据到内存
    EEPROM.begin(size * 2);
    for (size_t i = 0; i < size; i++) {
        char data = ((char *) data_source)[i];
        EEPROM.write(i, data);
    }
    EEPROM.end();
}

void loadStruct(void *data_dest, size_t size) {
    EEPROM.begin(size * 2);
    for (size_t i = 0; i < size; i++) {
        char data = EEPROM.read(i);
        ((char *) data_dest)[i] = data;
    }
}

void loadSettings(Settings settings) {
    EEPROM.begin(4);
    // 如果第一个字节存储的数据不是0，则继续加载设置数据
    uint8_t heatTime = EEPROM.read(0);
    if (heatTime != 0) {
        loadStruct(&settings, sizeof(settings));
    }
}

/**
 * 设置页中每修改一个数据调用对应的setXXX函数临时保存
 * 最后只在离开设置页面调用该函数写入epprom
 */
void saveSettings(Settings settings) {
    storeStruct(&settings, sizeof(settings));
}