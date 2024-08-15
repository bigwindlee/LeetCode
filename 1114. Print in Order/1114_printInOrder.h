#pragma once
#include <functional>
#include <mutex>
using namespace std;

/*
1114. 按序打印
给你一个类：
public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
三个不同的线程 A、B、C 将会共用一个 Foo 实例。
线程 A 将会调用 first() 方法
线程 B 将会调用 second() 方法
线程 C 将会调用 third() 方法
请设计修改程序，以确保 second() 方法在 first() 方法之后被执行，third() 方法在 second() 方法之后被执行。

思路分析：
要保证线程A/B/C的执行顺序，就需要一种线程间同步的机制。可以使用c++的unique_lock或者semaphore来实现。
lock1用于保证A/B的顺序：线程A释放lock1，线程B等待lock1，那么B必然在A的后面执行；
lock2用于保证B/C的顺序：线程B释放lock2，线程C等待lock2，那么C必然在B的后面执行；
使用 lock_guard 或者 unique_lock 提供的 RAII 机制来管理 mutex 对象，而不是直接操作 mutex 对象；
其中 lock_guard 只拥有构造和析构函数，用来实现 RAII 机制，而 unique_lock 是一个完整的 mutex 所有权包装器，封装了所有 mutex 的函数。

*/
class Foo {
public:
    mutex mtx1, mtx2;
    unique_lock<mutex> lock1, lock2;
    Foo()
        : lock1(mtx1, try_to_lock)
        , lock2(mtx2, try_to_lock)
    {
    }

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        lock1.unlock();
    }

    void second(function<void()> printSecond)
    {
        lock_guard<mutex> guard(mtx1); // 阻塞等待mtx1被释放
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        lock2.unlock();
    }

    void third(function<void()> printThird)
    {
        lock_guard<mutex> guard(mtx2); // 阻塞等待mtx2被释放
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};