//
// 操控
// Created by mdmbct on 10/1/22.
//

#ifndef ARDUINOESPHEAT_CTRL_H
#define ARDUINOESPHEAT_CTRL_H

#include <Arduino.h>
#include <OneButton.h>

#define MAX_FIFO_QUEUE_SIZE 10


typedef enum {
//  无操作        上一个、减      下一个、加     确认       菜单、设置    返回
    NO_CTRL = 0, PREVIOUS = 1, NEXT = 2, CONFIRM = 3, MENU = 4, BACK = 5
} CtrlType;

// 从队列末尾拿元素操作
struct CtrlTypeFIFOQueue {
    // 操作类型
    CtrlType data[MAX_FIFO_QUEUE_SIZE];
    // 队列头尾指针
    // 这里队尾指针指向最后一个元素
    int front, rear;
};

class Ctrl {

protected:
    // 存储操作的先进先出队列
    CtrlTypeFIFOQueue ctrlQueue{};

public:
    Ctrl() {
        ctrlQueue.front = ctrlQueue.rear = 0;
    }

    void pushCtrl(CtrlType ct) {
        if (ctrlQueue.rear < MAX_FIFO_QUEUE_SIZE) {
            // 队列未满
            // 队列末尾添加元素 队尾指针加一
            ctrlQueue.data[ctrlQueue.rear + 1] = ct;
            ctrlQueue.rear = (ctrlQueue.rear + 1) % MAX_FIFO_QUEUE_SIZE;
        }
    }

    /**
     * 从队列中弹出当前操作
     * @return
     */
    CtrlType popCtrl() {
        if (ctrlQueue.rear != ctrlQueue.front) {
            CtrlType ctrlType = ctrlQueue.data[ctrlQueue.front];
            ctrlQueue.front = (ctrlQueue.front + 1) % MAX_FIFO_QUEUE_SIZE;
            return ctrlType;
        } else {
            // 对空
            return NO_CTRL;
        }
    }

    /**
     * 获取当前操作 操作仍保存在队列中
     * @return
     */
    CtrlType curCtrl() {
        if (ctrlQueue.rear != ctrlQueue.front) {
            CtrlType ctrlType = ctrlQueue.data[ctrlQueue.front];
            return ctrlType;
        } else {
            // 对空
            return NO_CTRL;
        }
    }

    void clearCtrlQueue() {
        for (int i = ctrlQueue.front; i <= ctrlQueue.rear; ++i) {
            ctrlQueue.data[i] = NO_CTRL;
        }
    }

    /**
     * 添加中断
     */
    virtual void attachButtonInterrupt() = 0;
};

#endif //ARDUINOESPHEAT_CTRL_H
