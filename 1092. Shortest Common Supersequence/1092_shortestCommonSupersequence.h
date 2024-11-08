#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string& s, string& t)
    {
        // f[i+1][j+1] 表示 s 的前 i 个字母和 t 的前 j 个字母的最短公共超序列的长度
        int m = s.length(), n = t.length();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (int j = 0; j <= n; ++j) {
            f[0][j] = j; // 递归边界
        }
        for (int i = 1; i <= m; ++i) {
            f[i][0] = i; // 递归边界
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) { // 最短公共超序列一定包含 s[i]
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else { // 取更短的组成答案
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        string ans;
        int i = m - 1, j = n - 1; // s和t的末字符下标
        while (i >= 0 && j >= 0) {
            if (s[i] == t[j]) { // 公共超序列一定包含 s[i]
                ans += s[i];
                --i;
                --j; // 相当于继续递归 make_ans(i - 1, j - 1)
            } else if (f[i + 1][j + 1] == f[i][j + 1] + 1) {
                ans += s[i--]; // 相当于继续递归 make_ans(i - 1, j)
            } else {
                ans += t[j--]; // 相当于继续递归 make_ans(i, j - 1)
            }
        }
        reverse(ans.begin(), ans.end());
        // 补上前面的递归边界
        return s.substr(0, i + 1) + t.substr(0, j + 1) + ans;
    }
};