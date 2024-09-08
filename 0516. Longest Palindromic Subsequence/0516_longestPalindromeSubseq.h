#pragma once
#include <string>
#include <vector>
using namespace std;

/*
516. 最长回文子序列
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
*/

/*
解题思路：（经典DP / 不连续子序列问题）
  ● 动态规划定义：dp[i][j] 表示子串 s[i...j] 中最长回文子序列的长度。
  ● 转移方程：
      - 如果 s[i] == s[j]，则 dp[i][j] = dp[i+1][j-1] + 2。
      - 如果 s[i] != s[j]，则 dp[i][j] = max(dp[i+1][j], dp[i][j-1])。
  ● 初始化：单个字符的最长回文子序列长度为 1，即对所有 i，dp[i][i] = 1。
  ● 计算顺序：从底部向上填充 dp 表，即从字符串的末尾开始向前计算。
*/
class Solution_0516 {
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        // 初始化，单字符的回文子序列长度是1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        // 从底部向上，从左到右填表
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2; // 左下角的方块 + 2
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // 左边的方块和下边的方块取大的那个
                }
            }
        }

        return dp[0][n - 1];
    }
};
