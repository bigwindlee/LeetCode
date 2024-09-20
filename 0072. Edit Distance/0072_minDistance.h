#pragma once
#include <string>
#include <vector>
using namespace std;

/*
72. 编辑距离
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
你可以对一个单词进行如下三种操作：
  ● 插入一个字符
  ● 删除一个字符
  ● 替换一个字符
*/

/*
思路分析：经典二维DP

dp[i][j]表示word1的前i个字符转换成word2的前j个字符所用的步数。dp[m][n]就是最终所求结果，所以矩阵维度：(m+1) * (n+1)

dp[i][j]的上一跳有几种可能性呢？

dp[i-1][j-1]表示word1的前i-1个字符已经转换成了word2的前j-1个字符，
此时如果分别添加一个相同字符，不影响转换效果，所以 dp[i][j] = dp[i-1][j-1] 。
如果分别添加一个不同字符，那么需要一个替换操作，所以 dp[i][j] = dp[i-1][j-1] + 1 。

dp[i-1][j]达成转换，dp[i][j]也要达成的话，把word1多出来的字符删掉（删除操作），所以dp[i][j] = dp[i-1][j] + 1 ；
dp[i][j-1]达成转换，dp[i][j]也要达成的话，把word2多出来的字符添加到word1后面（插入操作），所以 dp[i][j] = dp[i][j-1] + 1 ；

dp[i][j]的上一跳只有这3种可能性，题目要求“最少操作数”，所以上一跳要选择最小的那一个：
在 word1[i-1] != word2[j-1] 的情况下（递推式！重要！）：
dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
*/

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // 二维DP

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0) {
                    dp[i][j] = j; // 添加j个字符即达成转换
                } else if (j == 0) {
                    dp[i][j] = i; // 删除i个字符即达成转换
                } else if (word1[i - 1] == word2[j - 1]) { // 注意前i个字符的末尾index为i-1，前j个字符的末尾index为j-1；
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                }
            }
        }
        return dp[m][n];
    }
};