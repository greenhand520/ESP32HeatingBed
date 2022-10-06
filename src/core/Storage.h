//
// Created by mdmbct on 10/1/22.
//

#ifndef OESPHEAT_SETTINGS_H
#define OESPHEAT_SETTINGS_H

#include <Arduino.h>
#include "UIData.h"
// Arduino for esp8266 中用的EEPROM其实是从外部flash中存储器最末尾开辟的4096字节空间，
// 每次操作写入的数据在4~4096字节之间（4字节对齐）；，所以，EEPROM可操作的地址为0~4095。

#include "EEPROM.h"

void loadSettings(Settings settings);

/**
 * 设置页中每修改一个数据调用对应的setXXX函数临时保存
 * 最后只在离开设置页面调用该函数写入epprom
 */
void saveSettings(Settings settings);

#endif //OESPHEAT_SETTINGS_H
