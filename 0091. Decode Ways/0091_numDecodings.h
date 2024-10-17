#pragma once
#include <string>
#include <unordered_map>
using namespace std;

/*
思路1：一维动规
本题其实是“爬楼梯”的一种特殊形式，dp[i] = dp[i-1] + dp[i-2] 在部分情况下成立。
回顾一下“爬楼梯”：
  ● 1个台阶有1种方法；2个台阶有2种方法；从第三个台阶开始，它的上一跳有2种可能：在i-1处，或者在i-2处；
  ● 约定0个台阶有1种方法；这样可以使用递推公式推导出前2个台阶的方法：dp[2] = dp[1] + dp[0]
*/
class Solution {
public:
    int numDecodings(string s)
    {
        if (s[0] == '0') {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n + 1); // dp[i]表示前i个字符对应的解码方法的总数
        dp[0] = 1; // 约定前0个字符的解码方法为1，这样是为了使递推公式变得通用。
        dp[1] = 1; // 排除了s[0]为'0'的情况
        for (int i = 2; i <= n; ++i) { // 前i个字符，末尾字符的下标为i-1
            // 有条件的递推公式：dp[i] = dp[i-1] + dp[i-2]
            if (s[i - 1] > '0') {
                dp[i] = dp[i - 1];
            }
            if (s[i - 2] > '0' && (((s[i - 2] - '0') * 10 + s[i - 1] - '0') < 27)) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

/*
思路2：记忆化DFS
2个搜索方向：每次走1步；每次走2步；
*/
class Solution_0091_2 {
public:
    unordered_map<string, int> cache;

    int numDecodings(string s) { return dfs(s, 0, 1) + dfs(s, 0, 2); }

    int dfs(const string& s, int start, int step)
    {
        string key = to_string(start) + "_" + to_string(step);
        if (cache.count(key) > 0) {
            return cache[key];
        }
        if (s[start] == '0' || start + step > s.size()) {
            return 0;
        }
        int num = 0;
        for (int i = start; i < start + step; ++i) {
            num = num * 10 + s[i] - '0';
        }
        if (num > 26) {
            return 0;
        }
        if (start + step == s.size()) {
            return 1;
        }
        cache[key] = dfs(s, start + step, 1) + dfs(s, start + step, 2);
        return cache[key];
    }
};