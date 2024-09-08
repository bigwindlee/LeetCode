#pragma once
#include <string>
#include <vector>
using namespace std;

/*
1312. 让字符串成为回文串的最少插入次数
给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
请你返回让 s 成为回文串的 最少操作次数 。
「回文串」是正读和反读都相同的字符串。
*/

/*
思路分析：（区间DP / 通过区间收缩来定义子问题）
  ● 动态规划定义：定义 dp[i][j] 为在子串 s[i...j] 中，将其转换为回文串所需的最少插入次数。
  ● 转移方程：
      - 当 s[i] == s[j] 时，dp[i][j] = dp[i+1][j-1]。
      - 当 s[i] != s[j] 时，dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1。
  ● 初始化：对于所有 i，dp[i][i] = 0，因为单个字符本身就是回文。
  ● 计算顺序：由于每个状态依赖于其子问题，我们应该从小到大的范围内填充 dp 表。

相同题目：https://github.com/bigwindlee/LeetCode/tree/master/0516.%20Longest%20Palindromic%20Subsequence
对DP矩阵的初始化、填充顺序完全一样。以dp[i][j]为右上角的4个小方格组成的正方形，dp[i][j]由左边、下边、左下边的三个小方格来决定。
*/
class Solution_1312 {
public:
    int minInsertions(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        // 单个字符本身就是回文串，需要0次插入次数。填充dp矩阵对角线。
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1]; // 区间左边界`和`右边界收缩
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]); // 区间左边界`或`右边界收缩
                }
            }
        }
        return dp[0][n - 1];
    }
};