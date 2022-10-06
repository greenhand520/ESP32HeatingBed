//
// Created by mdmbct on 10/4/22.
//

#include <Arduino.h>
#include "core/Core.h"
#include "impl/RotaryCtrl.h"
#include "impl/MAX6675Measure.h"
#include "impl/ButtonDormancyEvent.h"
#include "ui/Display.h"

#define MAX6675_SCK_PIN 1
#define MAX6675_CS_PIN 2
#define MAX6675_SO_PIN 3
#define SCL_PIN 9
#define HEAT_PWM_PIN 10
#define ROTARY_A_PIN 11
#define ROTARY_B_PIN 11
#define ROTARY_BTU_PIN 12
#define SDA_PIN 13
#define RESET_PIN 14
#define STOP_BUT_PIN 15
#define BUZZ_PIN 16

UIData uiData{};
ButtonDormancyEvent *buttonDormancyEvent = new ButtonDormancyEvent(STOP_BUT_PIN);
Ctrl *rotaryCtrl = new RotaryCtrl(ROTARY_BTU_PIN, ROTARY_A_PIN, ROTARY_B_PIN);
Core core = Core(BUZZ_PIN,
                 rotaryCtrl,
                 buttonDormancyEvent,
                 new MAX6675Measure(MAX6675_SCK_PIN, MAX6675_CS_PIN, MAX6675_SO_PIN));
U8G2 u8g2 = screenDriver(SDA_PIN, SCL_PIN, RESET_PIN);

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
