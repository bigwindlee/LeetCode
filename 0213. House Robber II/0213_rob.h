#pragma once
#include <vector>
using namespace std;

/*
213. 打家劫舍 II
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
*/

/*
思路分析：一维DP
打家劫舍类问题是一类经典的一维动规题目；定义dp数组，其中dp[i]表示前i家被偷窃的最高金额；
本题的特殊之处在于，所有房屋围成一圈，nums[0]和nums[n-1]是相邻的，不能同时被劫！
解决思路是，把nums[0]是否被劫的情况分开来处理：
    1）nums[0]被劫，则nums[n-1]受限制，不能被劫；此时dp[n] = dp[n-1]
    2）nums[0]不被劫，则nums[n-1]不受限制；不需要单独处理dp[n]

nums[0]只有2种可能；2种情况都需要递推到dp[n]，取出其中较大的dp[n]即可。
*/
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1);

        // nums[0]被偷，nums[n-1]受限制，不能被偷
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            if (i == 2 || i == n) { // nums[n-1]不能被偷
                dp[i] = dp[i - 1];
            } else {
                dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
            }
        }
        int ans = dp[n];

        // nums[0]不被偷，nums[n-1]不受限制，不需要特殊处理。
        dp[1] = 0; // 清零，从2开始重新填表
        for (int i = 2; i <= n; ++i) {
            if (i == 2) {
                dp[i] = nums[i - 1];
            } else {
                dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
            }
        }
        ans = max(ans, dp[n]);
        return ans;
    }
};