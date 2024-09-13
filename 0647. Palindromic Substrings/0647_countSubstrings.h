#pragma once
#include <string>
#include <vector>
using namespace std;

/*
647. 回文子串
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
*/

/*
思路分析：区间DP
但凡设计到字符串的区间问题，而且和区间内收产生的子区间存在递推关系，都要考虑区间DP！
区间 DP 的状态通常用 `dp[i][j]` 表示，表示从序列索引 `i` 到 `j` 这一子区间的最优解。`i` 和 `j` 表示区间的左右边界。
*/
class Solution {
public:
    int countSubstrings(string s)
    {
        int ans = 0, n = s.size();
        // dp[i][j] 表示 s[i:j] 是否是回文；
        // 默认不是回文，只需找出是回文的子串；
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // 从下往上填表（i从大到小，j从左往右）
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    // 单个字符或两个字符是回文，不需要提前填充对角线；
                    // 长度大于2时，取决于内部子串（边界内收）是否是回文；
                    dp[i][j] = (j - i < 2) ? true : dp[i + 1][j - 1];
                    ans += dp[i][j] ? 1 : 0;
                }
            }
        }

        return ans;
    }
};
