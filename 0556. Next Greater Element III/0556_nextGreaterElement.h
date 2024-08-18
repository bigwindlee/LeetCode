#pragma once
#include <string>
using namespace std;

/*
556. 下一个更大元素 III
给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。如果不存在这样的正整数，则返回 -1 。
注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。

思路分析：
下一个排列/字典序。和“31. 下一个排列”的思路完全一样。

算法可视化：
https://github.com/bigwindlee/LeetCode/blob/master/0031.%20Next%20Permutation/README.md
*/
class Solution_0556 {
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);

        // 寻找从右往左的第一次下降，也就是s[i] < s[i+1]，对应“可视化”图中的数字5；
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            --i;
        }
        // 注意这里是和“31. 下一个排列”不一样的地方；它并没有要求，不存在下一个排列时返回字典序的第一个排列；而是返回-1；
        if (i < 0) {
            return -1;
        }
        // 从末尾开始往左寻找首个比s[i]的数，与s[i]交换后，不改变[i+1, end)的降序；
        int j = s.size() - 1;
        while (s[j] <= s[i]) {
            --j;
        }
        swap(s[i], s[j]);

        // [i+1, end)区间降序变升序；这是能组成的最小的字典序；
        // 有时候题目会要求，找不到下一个排列，则返回字典序的第一个排列（此时i的值是-1），下面的语句可以统一的解决这个问题。
        reverse(s.begin() + i + 1, s.end());
        long ans = stol(s);
        return ans > INT_MAX ? -1 : ans;
    }
};