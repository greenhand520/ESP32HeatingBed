//
// Created by mdmbct on 10/4/22.
//

#include <Arduino.h>
#include "core/Core.h"
#include "impl/RotaryCtrl.h"
#include "impl/MAX6675Measure.h"
#include "impl/ButtonDormancyEvent.h"
#include "ui/Display.h"

#define MAX6675_SCK_PIN 18 // GPIO18
#define MAX6675_CS_PIN 5 // GPIO5
#define MAX6675_SO_PIN 19 // GPIO19

#define SDA_PIN 21 // GPIO21
#define SCL_PIN 22 // GPIO22

#define HEAT_PWM_PIN 26 // GPIO26

#define ROTARY_A_PIN 27 // GPIO27
#define ROTARY_B_PIN 14 // GPIO14
#define ROTARY_BTU_PIN 33 // GPIO33

#define STOP_BUT_PIN 5 // GPIO5
#define WS2812_PIN 18 // GPIO18
#define FAN_PIN 23 // GPIO23

#define BUZZ_PIN 25 // GPIO25

#define VBUS_ADC_PIN 4 // GPIO4

UIData uiData{};
ButtonDormancyEvent *buttonDormancyEvent = new ButtonDormancyEvent(STOP_BUT_PIN);
Ctrl *rotaryCtrl = new RotaryCtrl(ROTARY_BTU_PIN, ROTARY_A_PIN, ROTARY_B_PIN);
Core core = Core(BUZZ_PIN,
                 rotaryCtrl,
                 buttonDormancyEvent,
                 new MAX6675Measure(MAX6675_SCK_PIN, MAX6675_CS_PIN, MAX6675_SO_PIN),
                 HEAT_PWM_PIN, true);
U8G2 u8g2 = SSD1306_12864Driver(SDA_PIN, SCL_PIN);

void setup() {
    noInterrupts();
    core.setup();
    screenDriverInit();
    interrupts();
}

void loop() {
    buttonDormancyEvent->checkState();
    core.loop();
    refreshScreen(rotaryCtrl->popCtrl());
}
