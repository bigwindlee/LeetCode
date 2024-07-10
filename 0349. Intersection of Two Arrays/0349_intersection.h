#pragma once
#include <unordered_map>
#include <vector>
using namespace std;

/*
349. 两个数组的交集
给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

思路分析：
本题非常巧妙的利用哈希表的计数功能解决重复数字的问题！以nums1中的数字i作为key建立哈希表，使用nums2中的数字j直接操作哈希表（减1）；
如果j不在nums1中，um[j]值为-1；
如果j在nums1中，但j重复，um[j]就会被减了2次！

unordered_map设计哲学：
unordered_map 的 operator[] 访问不存在的key会自动插入（调用值类型的默认构造函数）；设计为自动插入是出于性能和简化代码的考虑，
而 Python 的 dict 则选择抛出异常以提供更显式的错误处理机制。这两种设计反映了两种语言在不同应用场景和使用哲学上的差异。
*/
class Solution_0349 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        unordered_map<int, int> um;
        for (int i : nums1) {
            um[i] = 1; // nums1中的数字作为key，其值设置为1，不必考虑重复的数字。
        }
        for (int j : nums2) {
            --um[j]; // 如果j是重复的数字，那么um[j]被减了2次！
            if (um[j] == 0)
                ans.push_back(j);
        }
        return ans;
    }
};