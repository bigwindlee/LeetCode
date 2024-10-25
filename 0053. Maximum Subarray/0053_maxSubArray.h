﻿#pragma once
#include <vector>
using namespace std;

/*
* 53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
`子数组`是数组中的一个连续部分。

思路分析：（动态规划）
在遍历数组的过程中，设置sum变量记录`以当前节点结尾`的连续数组的和的最大值。
`以当前节点结尾`这个条件非常重要，也就是说nums[i]一定要计算在内；
至于左边的连续子数组（以nums[i-1]结尾），如果是正收益就接纳，如果是负收益就舍弃（意味着从nums[i]开始，重新计算连续子数组）。
这也是DP问题的核心：状态的定义非常重要，只有合适的状态，才能找到整体与部分之间的联系，从而建立递推公式。

联想帮助理解：
sum就像一个书记员，在行军的过程中，随时的记录左边的连续子数组累加到当前节点的累加和。
要对左边的累加和进行决策：正收益则保留，负收益则舍弃（重新开始计算连续子数组）。
当前节点一定要计算在内，因为这有这样，才有可能继续向下一个节点继续累加。否则连续性就被中断了。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int ans = nums[0], sum = 0;
        for (int i : nums) {
            sum = i + max(0, sum); // DP递推公式：上一轮的sum，正收益则连接，负收益则舍弃（重新计算连续子数组）。
            ans = max(ans, sum); // `以当前节点结尾`的连续子数组累加和，挑战最大值。
        }
        return ans;
    }
};
