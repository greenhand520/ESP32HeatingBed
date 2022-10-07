//
// Created by mdmbct on 10/4/22.
//

#include <Arduino.h>
#include "core/Core.h"
#include "impl/RotaryCtrl.h"
#include "impl/MAX6675Measure.h"
#include "impl/ButtonDormancyEvent.h"
#include "ui/Display.h"

#define MAX6675_SCK_PIN 35 // GPIO18
#define MAX6675_CS_PIN 34 // GPIO5
#define MAX6675_SO_PIN 38 // GPIO19

#define SDA_PIN 42 // GPIO21
#define SCL_PIN 39 // GPIO22

#define HEAT_PWM_PIN 15 // GPIO26

#define ROTARY_A_PIN 11 // GPIO27
#define ROTARY_B_PIN 11 // GPIO14
#define ROTARY_BTU_PIN 12 // GPIO33

#define STOP_BUT_PIN 34 // GPIO5

#define BUZZ_PIN 14 // GPIO25

#define VBUS_ADC_PIN // GPIO4

UIData uiData{};
ButtonDormancyEvent *buttonDormancyEvent = new ButtonDormancyEvent(STOP_BUT_PIN);
Ctrl *rotaryCtrl = new RotaryCtrl(ROTARY_BTU_PIN, ROTARY_A_PIN, ROTARY_B_PIN);
Core core = Core(BUZZ_PIN,
                 rotaryCtrl,
                 buttonDormancyEvent,
                 new MAX6675Measure(MAX6675_SCK_PIN, MAX6675_CS_PIN, MAX6675_SO_PIN));
U8G2 u8g2 = SSD1306_12864Driver(SDA_PIN, SCL_PIN);

void setup() {
    noInterrupts();
    core.setup(HEAT_PWM_PIN);
    screenDriverInit();
    interrupts();
}

void loop() {
    buttonDormancyEvent->checkState();
    core.loop();
    refreshScreen(rotaryCtrl->popCtrl());
}
