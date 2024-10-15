#include "LongestPalindrome.h"
#include <vector>

using namespace std;

bool isPalindrome(const string& s)
{
    int len = s.length();
    for (int i = 0; i < len - 1 - i; i++) {
        // 一头一尾2个指针同时向中间移动
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

/* 暴力求解：
 * 1) 给定index i，遍历从这个字符开始的所有子串（从长到短），如果子串为回文，则找到从 index i 开始的最长子串。    
 * 时间复杂度：
 * 1）遍历字符串子串：嵌套一个循环、O(n^2)；判断是否为回文：再次嵌套一个循环、O(n^3)。
 * 缺点：
 * 时间复杂度太高，对于长字符串会超时。
 */
string LongestPalindrome::longestPalindrome_1(string s)
{
    if (s.length() < 2)
        return s;

    int longest = 0;
    int len = s.length();
    string palindrome;

    for (int i = 0; i < len; i++) {
        if (len - i < longest) {
            break;
        }
        for (int j = len - i; j > 0; j--) {
            if (j < longest) {
                continue;
            }
            string sub = s.substr(i, j);
            if (sub.length() <= longest) {
                continue;
            }
            if (isPalindrome(sub)) {
                longest = sub.length();
                palindrome = sub;
                continue;
            }
        }
    }
    return palindrome;
}

/*
* 动态规划
* 一个回文的上一步是什么状态？上一步也是回文（dp[i + 1][j - 1]为true），然后在首尾两端分别扩充一个相同的字符（s[i] == s[j]）。
* 用 dp[i][j] 表示从下标 i 到下标 j 的子串是否是回文，是则为 true ，否则为 false 。
* 回文的初始状态（边界条件）是什么？有2种最简单的回文：1）奇数个字符，比如"a"，"aba"，2）偶数个字符：比如："abba"
* 因此从单个字符或者2个相同的字符开始进行扩充。
*/
class Solution {
public:
    string longestPalindrome(string s)
    {
        int start = 0, maxlen = 1, n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n)); // 二维DP
        // 注意填表的顺序：i从右下角向上走，j从左到右；这是区间DP的常见套路；
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && (j - i < 2 || dp[i + 1][j - 1]); // 核心
                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
