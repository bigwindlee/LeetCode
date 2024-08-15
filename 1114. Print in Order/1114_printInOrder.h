#pragma once
#include <functional>
#include <mutex>
using namespace std;

/*
1114. �����ӡ
����һ���ࣺ
public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
������ͬ���߳� A��B��C ���Ṳ��һ�� Foo ʵ����
�߳� A ������� first() ����
�߳� B ������� second() ����
�߳� C ������� third() ����
������޸ĳ�����ȷ�� second() ������ first() ����֮��ִ�У�third() ������ second() ����֮��ִ�С�

˼·������
Ҫ��֤�߳�A/B/C��ִ��˳�򣬾���Ҫһ���̼߳�ͬ���Ļ��ơ�����ʹ��c++��unique_lock����semaphore��ʵ�֡�
lock1���ڱ�֤A/B��˳���߳�A�ͷ�lock1���߳�B�ȴ�lock1����ôB��Ȼ��A�ĺ���ִ�У�
lock2���ڱ�֤B/C��˳���߳�B�ͷ�lock2���߳�C�ȴ�lock2����ôC��Ȼ��B�ĺ���ִ�У�
ʹ�� lock_guard ���� unique_lock �ṩ�� RAII ���������� mutex ���󣬶�����ֱ�Ӳ��� mutex ����
���� lock_guard ֻӵ�й������������������ʵ�� RAII ���ƣ��� unique_lock ��һ�������� mutex ����Ȩ��װ������װ������ mutex �ĺ�����

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
        lock_guard<mutex> guard(mtx1); // �����ȴ�mtx1���ͷ�
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        lock2.unlock();
    }

    void third(function<void()> printThird)
    {
        lock_guard<mutex> guard(mtx2); // �����ȴ�mtx2���ͷ�
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};