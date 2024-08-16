#pragma once
#include <vector>
using namespace std;

/*
leetcode 338. 比特位计数
给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。

思路分析1：
常规思路：把整数i依次右移1位，并统计最低位1bit的个数。

思路分析2：
动态规划：DP的本质是寻找递推公式，用子集的运算表达式来表示全集。也就是 dp[i] = f(dp[j1], dp[j2])，其中 j1 < i, j2 < i。
本题中，把整数i的二进制表示划分成2个部分，最低位比特，以及左边剩下的部分。
左边剩下的部分中的1比特个数，表示为dp[i>>1]，那么它和dp[i]有什么区别呢？区别就在最低位比特！如果最低位是1bit，那么dp[i]就多1个！
所以找到了递推公式：dp[i] = dp[i>>1] + (i&1);
*/
class Solution {
public:
    // 常规解法：通过右移依次统计最低位1比特的个数。
    vector<int> countBits_1(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; ++i) {
            int b = i, count = 0;
            while (b) {
                count += b & 1;
                b >>= 1;
            }
            ans[i] = count;
        }
        return ans;
    }

    // DP解法
    vector<int> countBits_2(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i >> 1] + (i & 1); // 递推表达式
        }
        return dp;
    }
};