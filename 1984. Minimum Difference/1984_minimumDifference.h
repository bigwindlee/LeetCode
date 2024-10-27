#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
1984. 学生分数的最小差值
给你一个 下标从 0 开始 的整数数组 nums ，其中 nums[i] 表示第 i 名学生的分数。另给你一个整数 k 。
从数组中选出任意 k 名学生的分数，使这 k 个分数间 最高分 和 最低分 的 差值 达到 最小化 。
返回可能的 最小差值 。
*/

/*
思路分析：定长滑动窗口
长度为k的定长滑动窗口；
但凡是定长滑动窗口，可以直接计算出窗口左右下标的初始值；
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k)
    {
        if (k <= 1)
            return 0;
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        int left = 0, right = k - 1; // 长度为k的定长滑动窗口
        while (right < nums.size()) {
            ans = min(ans, nums[right++] - nums[left++]);
        }
        return ans;
    }
};
