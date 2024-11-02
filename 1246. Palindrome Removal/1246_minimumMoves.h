#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*
1246. 删除回文子数组
给你一个整数数组 arr，每一次操作你都可以选择并删除它的一个 回文 子数组 arr[i], arr[i+1], ..., arr[j]（ i <= j）。
注意，每当你删除掉一个子数组，右侧元素都会自行向前移动填补空位。
请你计算并返回从数组中删除所有数字所需的最少操作次数。
*/

/*
思路分析：区间DP
分成3中情况讨论：
    1）长度为1的区间，必然是回文，代价是1；
    2）长度为2的区间，取决于是否是回文，代价是1或者2；
    3）长度为3的区间；
*/
class Solution {
public:
    int minimumMoves(vector<int>& arr)
    {
        int n = arr.size();
        int dp[101][101];

        // 长度为1的区间必然是回文，代价是1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        // 长度为2的区间取决于是否回文，代价是1或2
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = arr[i] == arr[i + 1] ? 1 : 2;
        }

        // 区间长度>=3
        // 以区间长度3为例，分成2个长度分别为1、2的区间讨论；而长度为1、2的区间，之前已经填充过了；
        // 以此类推，形成递推公式；
        for (int len = 3; len <= n; ++len) {
            int i = 0, j = i + len - 1; // 双指针：区间首尾下标
            while (j < n) {
                dp[i][j] = len; // 初始为最坏的情况：分别删除每个字符
                for (int k = 0; k < len - 1; ++k) { // 分成2个区间：[i, k]，[k+1, j]
                    dp[i][j] = min(dp[i][j], dp[i][i + k] + dp[i + k + 1][j]);
                }
                if (arr[i] == arr[j]) { // 首尾字符相同，区间内收
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                }

                // 长度为len的窗口滑动
                ++i;
                ++j;
            }
        }

        return dp[0][n - 1];
    }
};
