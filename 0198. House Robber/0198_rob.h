#pragma once
#include <vector>
using namespace std;

/*
198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*/

/*
思路分析：一维DP
dp[i]表示`前i家`被偷的最大金额；前i家的末位是nums[i-1]；
分nums[i-1]被偷、不被偷两种情况，分别讨论dp[i]与左边建立递推公式的情况：
  1）如果nums[i-1]不被偷，那么dp[i]等价于dp[i-1]；
  2）如果nums[i-1]被偷，那么nums[i-2]不能被偷，所以前i家被偷金额为：nums[i-1] + dp[i-2]
因为追求最大金额，所以dp[i]取两者的较大值。
*/
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1); // dp[i]表示`前i家`被偷的最大金额；
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            // 分nums[i-1]`被偷`与`不被偷`两种情况讨论，并取二者的较大值；
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }
};