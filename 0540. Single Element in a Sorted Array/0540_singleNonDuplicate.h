#pragma once
#include <vector>
using namespace std;

/*
540. 有序数组中的单一元素
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
请你找出并返回只出现一次的那个数。
你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

思路分析：
见到“湮灭相同数字”，就要联想到异或操作。
*/
class Solution_0540 {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int ans = 0;
        for (int i : nums) {
            ans ^= i; // 异或操作湮灭相同的数字，使单一元素暴露出来。
        }
        return ans;
    }
};