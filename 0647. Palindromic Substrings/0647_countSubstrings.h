#pragma once
#include <string>
#include <vector>
using namespace std;

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
