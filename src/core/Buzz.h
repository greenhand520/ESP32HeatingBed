//
// 蜂鸣器
// Created by mdmbct on 10/1/22.
//

#ifndef OESPHEAT_BUZZ_H
#define OESPHEAT_BUZZ_H

#ifdef ESP32
#define BUZZ_CHANNEL 2
#endif

#include <Arduino.h>

/**
 * 音符
 * 来自：https://docs.arduino.cc/built-in-examples/digital/toneMelody#hardware-required
 * 参考：https://www.zhihu.com/question/27166538/answer/35507740
 *      https://blog.csdn.net/fatway/article/details/118859714
 */
typedef enum {
    NOTE_NONE = 0,
    NOTE_C4 = 262,
    NOTE_CS4 = 277,
    NOTE_D4 = 294,
    NOTE_DS4 = 311,
    NOTE_E4 = 330,
    NOTE_F4 = 349,
    NOTE_FS4 = 370,
    NOTE_G4 = 392,
    NOTE_GS4 = 415,
    NOTE_A4 = 440,
    NOTE_AS4 = 466,
    NOTE_B4 = 494
} Note;

// 音效
struct Tone {
    Note note;
    int delay;
};

class Buzz {
private:
    // 音量 0 ～ 10
    uint8_t volume;
    // 蜂鸣器引脚 带pwm输出
    uint8_t pin;
    // 是否还在播放音效
    bool isPlaying = true;
    // 播放的音效
    Tone *playingMelody = nullptr;
    // 当前播放到的音符
    uint16_t playingIndex = 0;

public:
    /**
     * 初始化
     * @param pin 蜂鸣器引脚 带pwm输出
     * @param volume 音量 0 ～ 10
     */
    Buzz(uint8_t pin, uint8_t volume = 5) : pin(pin), volume(volume) {
        pinMode(pin, OUTPUT);
        setVolume(volume);
        #ifdef ESP32
                //将通道与对应的引脚连接
                ledcAttachPin(pin, BUZZ_CHANNEL);
                // 设置通道
                ledcSetup(BUZZ_CHANNEL, 0, 8);
        #endif
    }

    void setVolume(uint8_t _volume) {
        this->volume = constrain(_volume, 0, 10);
        analogWrite(pin, volume * 20);
//    analogWriteRange(255);
    }

    // 只设置音效。在loop函数中 循环调用play播放
    void setMelody(Tone melody[]) {
        this->playingMelody = melody;
        this->playingIndex = 0;
    }

    /**
     * 播放音效
     * 参考： https://www.esp32.com/viewtopic.php?t=4978
     */
    void IRAM_ATTR play() {
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
};

// 所有的音效最后一个音符都要是NOTE_NONE
extern Tone BOOT_MELODY[];
// 开始休眠时的音效
extern Tone DORMANCY_MELODY[];
// 单击音效
extern Tone CLICK_MELODY[];
// 双击音效
extern Tone CONFIRM_CLICKED_MELODY[];

extern Tone MENU_CLICKED_MELODY[];

#endif //OESPHEAT_BUZZ_H
