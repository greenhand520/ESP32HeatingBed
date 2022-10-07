//
// Created by mdmbct on 10/4/22.
//

#ifndef ESP8285HEAT_DISPLAY_H
#define ESP8285HEAT_DISPLAY_H

#include <Arduino.h>
#include "Component.h"

//U8G2 SH1107_12864Driver(uint8_t sdaPin, uint8_t sclPin, uint8_t resetPin);

U8G2 SSD1306_12864Driver(uint8_t sdaPin, uint8_t sclPin);

void screenDriverInit();

void setRotate(bool isRotate);

void setBrightness(uint8_t _brightness);

void refreshScreen(CtrlType ct);

#endif //ESP8285HEAT_DISPLAY_H
