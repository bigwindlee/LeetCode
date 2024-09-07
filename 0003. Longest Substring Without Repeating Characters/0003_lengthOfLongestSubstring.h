#pragma once
#include <string>
#include <unordered_set>
using namespace std;

/*
3. 无重复字符的最长子串
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

思路分析：（滑动窗口）
“滑动窗口算法”是一种常用于解决数组或列表中相关问题的技术，特别是涉及到连续数据块的问题。这种算法通过创建一个可以在一定范围内滑动的窗口，来减少不必要的重复计算，从而优化性能。
编程模板：枚举右边界，连续滑动左边界！
*/
class Solution_0003 {
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0, i = 0;
        unordered_set<int> window;
        // 枚举右边界j
        for (int j = 0; j < s.size(); ++j) {
            while (window.count(s[j]) > 0) {
                window.erase(s[i++]); // 连续滑动左边界i
            }
            window.insert(s[j]);
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};