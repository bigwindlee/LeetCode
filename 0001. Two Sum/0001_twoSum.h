#pragma once
#include <unordered_map>
#include <vector>
using namespace std;

/*
1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

思路分析：（哈希表）
暴力搜索：使用2个循环对所有的成对组合进行遍历，判断其和是否等于target。时间复杂度O(n^2)。
优化版：使用哈希表，建立从value到index的映射，这样可以快速的知道某个值是否存在，以及对应的index。
哈希表的查找是O(1)，本方法只需要遍历一次数组，时间复杂度O(n)，空间复杂度O(n)。

技巧总结：
对于数组，建立从value到index的哈希表映射，mp[nums[i]] = i，是一种常用技法。
*/
class Solution_0001 {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> um; // 建立从value到index的哈希表映射
        for (int i = 0; i < nums.size(); ++i) {
            if (um.count(target - nums[i]) > 0) { // 查表，队友是否存在（已经遍历过）
                return { um[target - nums[i]], i };
            }
            um[nums[i]] = i; // 入表
        }
        return { -1, -1 };
    }
};
