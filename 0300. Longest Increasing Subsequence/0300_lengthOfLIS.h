#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*
方法二：贪心 + 二分查找  O(n log n)
这种方法使用一个数组 tails，其中 tails[i] 存储长度为 i+1 的所有递增子序列中最小的尾部元素。
通过使用二分查找，我们可以在 tails 中找到一个位置来更新尾部元素。

时间复杂度：O(n log n)，其中 n 是数组的长度。 空间复杂度：O(n)。
思维难点：
    注意tails存储的是什么？并不是最长递增子序列本身，仅仅用tails[i]来表示长度为 i+1 的所有递增子序列中最小的尾部元素！
    遍历的过程中要让这个尾部元素尽可能的小！
*/
class Solution_0300_02 {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> tails;
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end())
                tails.push_back(num);
            else
                *it = num; // 因为比左侧的尾部元素大，所有连接在它右边。
        }
        return tails.size();
    }
};

/*
方法一：（经典DP / 最长递增子序列）  O(n^2)

思路分析：
dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度。我们遍历数组中的每个元素，对于每个元素，再次遍历其之前的所有元素，更新 dp 数组。

时间复杂度：O(n^2)，其中 n 是数组的长度。 空间复杂度：O(n)。
*/
class Solution_0300_01 {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int ans = 1, n = nums.size();
        vector<int> dp(n, 1); // dp[i]表示以nums[i]结尾的最长递增子序列的长度
        for (int i = 0; i < n; ++i) {
            // 枚举左边的每一个nums[j]，只要比nums[i]小，就和它拼接起来形成一个以nums[i]结尾的递增子序列，其长度为dp[j]+1；用它挑战dp[i]；
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]); // 用dp[i]挑战ans
        }
        return ans;
    }
};