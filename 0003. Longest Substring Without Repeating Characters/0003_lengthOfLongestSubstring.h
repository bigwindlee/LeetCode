#pragma once
#include <string>
#include <unordered_set>
using namespace std;

/*
3. 无重复字符的最长子串
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

思路分析：（滑动窗口）
见到最长（短）子数组，就要联想到滑动窗口！
用2个指针(i/j)来表示滑动窗口的边界。

难点：
1. 用整形数组`int hash[128]`代替unordered_set，大大提高速度，减少内存占用；
2. i和j都要尽可能连续滑动；
*/

class Solution_0003 {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        // 此处的整形数组其实是在模拟unordered_set，用于判断重复字符；
        // 因为string中的元素类型为char，占一个字节，取值范围[0, 127]，用`int hash[128]`表示足够了。
        // 这个整形数组比用unordered_set速度快，内存占用少！
        int hash[128] = { 0 };
        int i = 0, j = 0, ans = 0; // i/j分别是滑动窗口的左右边界
        while (i < n) {
            // 右边界j连续向右滑动，直到越界，或者指向重复字符。
            while (j < n && hash[s[j]] == 0) {
                ++hash[s[j++]]; // 计入set集合
            }
            // 当前j可能溢出，也可能指向重复字符，[i, j)之间的字符就是一个备选不重复子串。
            ans = max(ans, j - i);
            // j到头了，循环没必要再继续了，后面再产生的不重复子串长度不会超过当前的j-i
            if (j == n) {
                break;
            }

            // 此时j必然指向重复字符；左边界i连续向右滑动，直到把重复的字符删掉。
            do {
                --hash[s[i++]]; // 从set集合中挨个删除
            } while (s[i - 1] != s[j]);
        }
        return ans;
    }
};

// 用`unordered_set<char>`实现
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        unordered_set<char> us; // 用于判断重复字符
        int i = 0, j = 0, ans = 0; // i/j分别是滑动窗口的左右边界
        while (i < n) {
            // 右边界j连续向右滑动，直到越界，或者指向重复字符。
            while (j < n && us.count(s[j]) == 0) {
                us.insert(s[j++]);
            }
            // j到头了，循环没必要再继续了，后面再产生的不重复子串长度不会超过当前的j-i
            if (j == n) {
                return max(ans, j - i);
            }
            // 当前j必指向重复字符，[i, j)之间的字符就是一个备选不重复子串。
            ans = max(ans, j - i);

            // 左边界i连续向右滑动，直到把重复的字符删掉。
            do {
                us.erase(s[i++]);
            } while (s[i - 1] != s[j]);
        }
        return ans;
    }
};