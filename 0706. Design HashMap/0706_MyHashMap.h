#pragma once
#include <list>
#include <vector>
using namespace std;

/*
706. 设计哈希映射
不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
实现 MyHashMap 类：
  - MyHashMap() 用空映射初始化对象
  - void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
  - int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
  - void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。

思路分析：（使用复合数据结构`vector + list + pair`实现哈希表）
实现哈希表的原理，其实我们会遇到一个抉择，那就是时间和空间的取舍。
实现方式有两种：
  - 超大数组：不考虑空间复杂度，创建超大数组，每个数都能单独存入，且不会位置冲突。
  - 链地址法：空间/时间的最佳实践，基于数组实现，并且通过一个 hash 函数生成一个对应的索引，当多个数索引一致的时候，再处理冲突问题，一般我们使用链地址法解决冲突。

Q: `base = 769`，这是一个特殊的数字吗？
A: 一个足够大的质数：
    · 当哈希函数生成的哈希值分布较均匀时，使用质数作为哈希表的大小可以有效减少冲突（即多个键映射到相同的索引）。
    · 质数避免了哈希值与表大小之间的简单模数关系，减少了同余现象，从而确保了哈希函数在所有可能的键值上尽量均匀分布。
    · 769 是一个常用的质数，因为它足够大，可以容纳适量的元素，且在某些算法中性能较好。
*/
class MyHashMap {
private:
    vector<list<pair<int, int>>> data; // 容纳所有键值对的底层数据结构
    static const int base = 769; // vector的大小
    static int hash(int key) { return key % base; } // 对769取余，作为hash值，用作vector的下标。

public:
    /** Initialize your data structure here. */
    MyHashMap()
        : data(base)
    {
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int idx = hash(key);
        for (auto it = data[idx].begin(); it != data[idx].end(); ++it) {
            if (it->first == key) {
                // 已存在则刷新
                it->second = value;
                return;
            }
        }
        // 不存在则添加到双向链表末尾
        data[idx].push_back({ key, value });
    }

    /** Returns the value to which the specified key is mapped, or -1 if this
     * map contains no mapping for the key */
    int get(int key)
    {
        int idx = hash(key);
        for (auto it = data[idx].begin(); it != data[idx].end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a
     * mapping for the key */
    void remove(int key)
    {
        int idx = hash(key);
        for (auto it = data[idx].begin(); it != data[idx].end(); ++it) {
            if (it->first == key) {
                data[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */