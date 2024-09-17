#pragma once
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int count;
    mutex mtx;
    condition_variable cv;
    bool zeroTurn; // 用于标记是否应该输出0

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
        this->count = 1;
        this->zeroTurn = true; // 从输出0开始
    }

    // 输出0
    void zero(function<void(int)> printNumber)
    {
        for (int i = 0; i < n; ++i) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return zeroTurn; });
            printNumber(0);
            zeroTurn = false;
            cv.notify_all(); // 唤醒奇数或偶数线程
        }
    }

    // 输出偶数
    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return !zeroTurn && count % 2 == 0; });
            printNumber(count++);
            zeroTurn = true;
            cv.notify_all(); // 唤醒zero线程
        }
    }

    // 输出奇数
    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return !zeroTurn && count % 2 == 1; });
            printNumber(count++);
            zeroTurn = true;
            cv.notify_all(); // 唤醒zero线程
        }
    }
};