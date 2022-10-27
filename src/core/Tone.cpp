//
// Created by mdmbct on 2022/10/27.
//

#include "Buzz.h"

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
