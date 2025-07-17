#pragma once
#include <unordered_map>
using namespace std;

/*
面试题 01.04. 回文排列
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
回文串不一定是字典当中的单词。

思路分析：字符频率统计
但凡涉及到频率统计，首先考虑使用哈希表；
如果限定了全小写字母，可使用状态压缩（位运算），把每个小写字母映射成[0, 25]之间的整数（相对'a'的offset）；然后再映射成一个int整型的比特位索引；

本题没有限定是全小写字母，因此必须使用哈希表；
回文排列中，字符出现的频率必须是偶数，最多只能有一个是奇数；
*/
class Solution_01_04 {
public:
    bool canPermutePalindrome(string s)
    {
        unordered_map<char, int> m;
        for (char c : s) {
            ++m[c]; // 频率统计
        }
        bool odd = false;
        for (auto [_, v] : m) { // 遍历哈希表
            if (v % 2) {
                if (odd) {
                    return false; // 最多只能有一个是奇数
                }
                odd = true;
            }
        }
        return true;
    }
};