﻿#pragma once
#include <string>
using namespace std;

/*
* 392. 判断子序列
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
*/

/*
思路分析：
字符串扫描
*/
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j++]) ++i;
        }
        return i == s.size();
    }
};