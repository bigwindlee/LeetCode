#pragma once
#include <map>
#include <unordered_map>
using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length) { }

    void set(int index, int val) { hash[index][snap_id] = val; }

    int snap() { return snap_id++; }

    int get(int index, int snap_id)
    {
        if (hash.count(index)) {
            auto it = hash[index].upper_bound(snap_id);
            if (it != hash[index].begin()) {
                return prev(it)->second;
            }
        }
        return 0;
    }

    int snap_id = 0; // c++ 11: 非静态数据成员初始化
    unordered_map<int, map<int, int>> hash;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */