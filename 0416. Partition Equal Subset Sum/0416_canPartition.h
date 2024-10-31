#pragma once
#include <bitset>
#include <numeric>
#include <vector>
using namespace std;

/*
416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
*/

/*
思路分析：状压DP
凡是求一个`静态的和`是否可达（只有2种状态）的问题，考虑状压DP，使用bitset实现；
*/
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false; // 如果总和是奇数，则不可能均分
        }
        int target = sum / 2; // 静态和是否可达

        // dp[i]表示和为i是否可达；为1表示可达，为0表示不可达；
        bitset<10001> dp(1); // 初始时 dp[0] = 1，表示和为 0 可达
        for (int num : nums) {
            dp |= dp << num; // 将 num 加入到所有可能的子集和中
            if (dp[target]) {
                return true;
            }
        }

        return false;
    }
};