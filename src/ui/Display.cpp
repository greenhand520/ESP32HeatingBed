//
// Created by mdmbct on 10/4/22.
//

#include "Display.h"

U8G2 screenDriver(uint8_t sdaPin, uint8_t sclPin, uint8_t resetPin) {
    if (uiData.settings.isRotate) {
        //    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C
        return U8G2_SH1107_64X128_F_HW_I2C(U8G2_R2, resetPin, sclPin, sdaPin);
    } else {
       return U8G2_SH1107_64X128_F_HW_I2C(U8G2_R0, resetPin, sclPin, sdaPin);
    }
}

void screenDriverInit() {
    u8g2.begin();
    u8g2.setBusClock(921600);
    u8g2.enableUTF8Print();
    u8g2.setFontPosTop();
    u8g2.setFont(u8g2_font_wqy12_t_gb2312);
    u8g2.setDrawColor(1);
    u8g2.setFontMode(1);
    setBrightness(uiData.settings.brightness);

}

void setRotate(bool isRotate) {
    u8g2.setDisplayRotation(isRotate ? U8G2_R2 : U8G2_R0);
}

void setBrightness(uint8_t _brightness) {
    u8g2.setContrast(constrain(_brightness, 1, 10) * 25);
}

void refreshScreen(CtrlType ct) {
    u8g2.clearBuffer();
    components[uiData.curCompIndex].uiDataUpdater(ct);
}


