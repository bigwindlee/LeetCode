#pragma once
#include <string>
#include <unordered_map>
using namespace std;

/*
哈希表 + 二分查找法
本题关键：
1）数据结构的设计：同一个key可以在不同时间戳下有多个值，也就是一个key对应的是多个二元组pair(timestamp, value)组成的数组：
    unordered_map<string, vector<pair<int, string>>>
2）因为时间戳的特点，二元组pair(timestamp, value)是按照timestamp严格递增的，因此可以使用二分查找快速的定位符合条件的timestamp及其对应的value。

隐含条件：
由于 set 操作中的时间戳都是严格递增的，因此二元组列表中保存的时间戳也是严格递增的。这是题干中的“时间戳”所隐含的前提条件。
这就保证了插入的数据是按照timestamp递增的，可以基于timestamp使用二分查找法。
*/
class TimeMap {
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        // push_back需要一个现有对象（复制或移动）。emplace_back使用提供的参数直接在容器中构造对象。
        // 它直接在vector分配的内存中构造对象，比push_back更高效，因为它避免了不必要的复制或移动操作。
        // 例如：push_back(std::make_pair(2, "example2"));  // 创建一个临时 pair 并移动到 vector 中
        store[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        if (store.find(key) == store.end()) // c++的哈希表怎样判断一个key是否存在
            return "";

        const auto& values = store[key];
        string ans;

        // 标准的二分查找模板
        int left = 0, right = values.size() - 1; // 用vector数组的第一个元素和最后一个元素的下标初始化(left, right)；
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) {
                // 不要试图一次就找到最终的ans，而是把第一个可能的解赋值给ans，并使用“更”符合条件的解对ans进行刷新；
                ans = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

private:
    unordered_map<string, vector<pair<int, string>>> store;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */