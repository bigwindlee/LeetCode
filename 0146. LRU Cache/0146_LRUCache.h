#pragma once
#include <list>
#include <unordered_map>
using namespace std;

/*
146. LRU 缓存
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
  - LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
  - int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
  - void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。
    如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/

/*
思路分析：（复合数据结构：双向链表 + 哈希表）
怎样表达出`最近最少使用`？要按照最近的使用时间进行排序。很显然节点需要频繁的调整顺序，使用双向链表list很合适；
题干要求 get 和 put 必须以 O(1) 的平均时间复杂度运行。O(1)时间复杂度是哈希表的特点。因此要用哈希表建立从`key`到`双向链表节点迭代器`之间的映射。

注意：
    - 无论读写，都要移动到链表的头节点，并刷新hash表中记录的位置。

*/
class LRUCache {
public:
    int cap;
    list<pair<int, int>> cache; // 双向链表存储键值对
    unordered_map<int, list<pair<int, int>>::iterator> hash; // 哈希表记录节点位置（从key到节点在双向链表中的迭代器之间的映射）

    LRUCache(int capacity)
        : cap(capacity)
    {
    }

    int get(int key)
    {
        int ans = -1;
        auto it = hash.find(key);
        if (it != hash.end()) {
            ans = it->second->second;

            // 无论读写，都要移动到链表的头节点，并刷新hash表中记录的位置。
            cache.erase(it->second);
            cache.push_front({ key, ans });
            hash[key] = cache.begin();
        }
        return ans;
    }

    void put(int key, int value)
    {
        if (hash.count(key) > 0) {
            cache.erase(hash[key]); // 链表中摘除
        } else {
            if (cache.size() == cap) { // 如果容量已满
                // 从双向链表和哈希表中淘汰最老的一个
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        }
        // 无论读写，都要移动到链表的头节点，并刷新hash表中记录的位置。
        cache.push_front({ key, value });
        hash[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */