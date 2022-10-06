// 相关函数参考：https://arduino-esp8266.readthedocs.io/en/latest/reference.html#analog-output
// ESP8285没有硬件PWM，PWM接⼝口功能由软件实现 会占用CPU计算
// Created by mdmbct on 10/1/22.
//

#include "Buzz.h"

#ifdef ESP32
#define BUZZ_CHANNEL 2
#endif

Buzz::Buzz(uint8_t pin, uint8_t volume) : pin(pin) {
    pinMode(pin, OUTPUT);
    setVolume(volume);
#ifdef ESP32
    //将通道与对应的引脚连接
    ledcAttachPin(pin, BUZZ_CHANNEL);
    // 设置通道
    ledcSetup(BUZZ_CHANNEL, 0, 8);
#endif
}

void Buzz::setMelody(Tone _melody[]) {
    this->playingMelody = _melody;
    this->playingIndex = 0;
}

void Buzz::setVolume(uint8_t _volume) {
    this->volume = constrain(_volume, 0, 10);
    analogWrite(pin, volume * 20);
//    analogWriteRange(255);
}

// 参考： https://www.esp32.com/viewtopic.php?t=4978
void IRAM_ATTR Buzz::play() {
    if (playingMelody == nullptr || volume == 0) {
        return;
    }

    if (playingMelody == nullptr || playingMelody[playingIndex].note == NOTE_NONE) {
        // 播放结束
        setMelody(nullptr);
    } else {
        // ESP32
        ledcWriteTone(BUZZ_CHANNEL, playingMelody[playingIndex].note);
        // ESP8266
        // analogWriteFreq(playingMelody[playingIndex].note);
        analogWrite(pin, volume);
        delay(playingMelody[playingIndex].delay);
        playingIndex++;
    }
}

// 所有的音效最后一个音符都要是NOTE_NONE
Tone BOOT_MELODY[] = {
        {NOTE_D4,   230},
        {NOTE_D4,   230},
        {NOTE_D4,   215},
        {NOTE_D4,   215},
        {NOTE_NONE, 0},
};
// 开始休眠时的音效
Tone DORMANCY_MELODY[] = {
        {NOTE_C4,   50},
        {NOTE_D4,   50},
        {NOTE_C4,   50},
        {NOTE_D4,   50},
        {NOTE_NONE, 0},
};
// 单击音效
Tone CLICK_MELODY[] = {
        {NOTE_E4,   100},
        {NOTE_NONE, 0},
};
// 双击音效
Tone CONFIRM_CLICKED_MELODY[] = {
        {NOTE_E4,   100},
        {NOTE_G4,   100},
        {NOTE_NONE, 0},
};

Tone MENU_CLICKED_MELODY[] = {
        {NOTE_E4,   200},
        {NOTE_NONE, 0},
};




