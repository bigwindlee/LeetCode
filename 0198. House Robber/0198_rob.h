#pragma once
#include <vector>
using namespace std;

/*
198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

思路分析：
题目的意思是从给定数组中找出不连续的数，使其和最大。
对于数组中的任何一个数，都只有2中可能，在、或者不在最终的最大和序列中。马上联想到 0-1 背包问题。经典DP问题。
dp[i]表示下标闭区间[0, i]的所有数的不连续最大和；那么问题的核心是，dp[i]和dp[i-1]，甚至dp[i-2]之间是什么关系？
此时nums[i]只有2中可能，（在 or 不在）最大和序列中；
1）如果在，那么nums[i-1]肯定不在（因为不能连续），此时dp[i]就等于 dp[i-2] + nums[i]
2）如果不在，此时dp[i]就等于 dp[i-1]
dp[i]取2中情况中的最大值，所以找到了递推公式：dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
*/
class Solution_0198 {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};