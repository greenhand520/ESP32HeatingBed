//
// Created by mdmbct on 10/1/22.
//

#include "Ctrl.h"

Ctrl::Ctrl() {
    ctrlQueue.front = ctrlQueue.rear = 0;
}

void Ctrl::pushCtrl(CtrlType ct) {
    if (ctrlQueue.rear < MAX_FIFO_QUEUE_SIZE) {
        // 队列未满
        // 队列末尾添加元素 队尾指针加一
        ctrlQueue.data[ctrlQueue.rear + 1] = ct;
        ctrlQueue.rear = (ctrlQueue.rear + 1) % MAX_FIFO_QUEUE_SIZE;
    }
}

CtrlType Ctrl::popCtrl() {
    if (ctrlQueue.rear != ctrlQueue.front) {
        CtrlType ctrlType = ctrlQueue.data[ctrlQueue.front];
        ctrlQueue.front = (ctrlQueue.front + 1) % MAX_FIFO_QUEUE_SIZE;
        return ctrlType;
    } else {
        // 对空
        return NO_CTRL;
    }
}

void Ctrl::clearCtrlQueue() {
    for (int i = ctrlQueue.front; i <= ctrlQueue.rear; ++i) {
        ctrlQueue.data[i] = NO_CTRL;
    }
}

CtrlType Ctrl::curCtrl() {
    if (ctrlQueue.rear != ctrlQueue.front) {
        CtrlType ctrlType = ctrlQueue.data[ctrlQueue.front];
        return ctrlType;
    } else {
        // 对空
        return NO_CTRL;
    }
}
