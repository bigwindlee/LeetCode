#pragma once

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>

class BoundedBlockingQueue {
private:
    std::queue<int> q; // 队列存储元素
    int capacity; // 队列容量
    std::mutex mtx; // 互斥锁，保护队列访问
    std::condition_variable not_full; // 用于等待队列不满
    std::condition_variable not_empty; // 用于等待队列不空

public:
    // 构造函数，初始化队列容量
    BoundedBlockingQueue(int capacity)
    {
        this->capacity = capacity;
    }

    // 生产者将元素加入队列，如果队列满，则阻塞
    void enqueue(int element)
    {
        std::unique_lock<std::mutex> lock(mtx);
        // 如果队列满了，则阻塞等待，直到有空间
        not_full.wait(lock, [this]() { return q.size() < capacity; });

        q.push(element); // 将元素加入队列
        not_empty.notify_one(); // 通知消费者队列不再为空
    }

    // 消费者从队列中取出元素，如果队列为空，则阻塞
    int dequeue()
    {
        std::unique_lock<std::mutex> lock(mtx);
        // 如果队列为空，则阻塞等待，直到有元素
        not_empty.wait(lock, [this]() { return !q.empty(); });

        int element = q.front(); // 取出队尾元素
        q.pop(); // 将元素从队列中移除
        not_full.notify_one(); // 通知生产者队列不再满
        return element;
    }

    // 返回队列的当前大小
    int size()
    {
        std::unique_lock<std::mutex> lock(mtx); // 获取锁保护队列
        return q.size(); // 返回当前队列中的元素个数
    }
};
