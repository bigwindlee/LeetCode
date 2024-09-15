#pragma once
#include <string>
#include <vector>
using namespace std;

/*
1143. 最长公共子序列 
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
  ● 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
*/

/*
思路分析：二维动态规划
二维数组 `dp[i][j]` 表示字符串`text1`的前`i`个字符 和 `text2`的前`j`个字符的最长公共子序列的长度。
i 取值范围：[0, m]；j 取值范围：[0, n]；所以dp的大小为：(m+1) * (n+1)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) { // 前 i 个字符的末尾索引是 i-1
                    dp[i][j] = dp[i - 1][j - 1] + 1; // text1和text2分别去掉末尾字符
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // text1去掉末尾字符，或者text2去掉末尾字符
                }
            }
        }
        return dp[m][n];
    }
};