#pragma once
#include <vector>
using namespace std;

/*
思路分析：（前缀和变种）
连续子数组的和的最大值。可以借鉴“前缀和”的思路，在从左至右遍历数组的过程中，把nums[i]左边的元素之和累加到nums[i]；
但是！如果左边的元素之和为负，那么舍弃左边的元素，相当于从nums[i]开始重新计算前缀和！

动态规划：
该解法本质上还是DP。难点在于定义状态。只有定义出合适的状态，才能找到整体和部分之间的联系，建立递推公式！
本题的状态定义：dp[i]代表以sales[i]结尾的连续子数组的最大和。
那么只有当dp[i-1]为正收益时，才会累加到sales[i]，形成dp[i]；
如果dp[i-1]为负收益，则舍弃，dp[i] = sales[i];
修改原数组用作dp数组，所以递推公式为：sales[i] = max(sales[i-1], 0);

相同题目："53. 最大子数组和"
https://leetcode.cn/problems/maximum-subarray/description/
*/
class Solution_01 {
public:
    int maxSales(vector<int>& sales)
    {
        int ans = sales[0];
        for (int i = 1; i < sales.size(); ++i) {
            sales[i] += max(sales[i - 1], 0); // 舍弃左边的负收益子数组，重新计算前缀和！
            ans = max(ans, sales[i]); // 用当前的前缀和挑战最大值
        }
        return ans;
    }
};
