#pragma once
#include <string>
#include <vector>

/*
443. 压缩字符串
给你一个字符数组 chars ，请使用下述算法压缩：
从一个空字符串 s 开始。对于 chars 中的每组 连续重复字符 ：
  ● 如果这一组长度为 1 ，则将字符追加到 s 中。
  ● 否则，需要向 s 追加字符，后跟这一组的长度。

压缩后得到的字符串 s 不应该直接返回 ，需要转储到字符数组 chars 中。需要注意的是，如果组长度为 10 或 10 以上，则在 chars 数组中会被拆分为多个字符。
请在 修改完输入数组后 ，返回该数组的新长度。
你必须设计并实现一个只使用常量额外空间的算法来解决此问题。
*/

/*
思路分析：双指针
题目要求只使用常量额外空间，并把压缩后的字符串原地回填。
使用2个指针：
  ● left指向一串重复字符的首个字符；
  ● right指向下一串重复字符的首个字符；
  ● 另有w指针，指示待写入的位置（原地回填）
*/
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars)
    {
        int n = chars.size();
        int left = 0, w = 0; // w指示待写入的位置
        while (left < n) {
            int right = left + 1; // 从left开始往右搜索首个不同于left的字符
            while (right < n && chars[right] == chars[left]) {
                ++right;
            }
            chars[w++] = chars[left];
            if (right - left > 1) {
                for (char c : to_string(right - left)) {
                    chars[w++] = c;
                }
            }
            left = right; // 迭代left指针
        }
        return w;
    }
};