#pragma once
#include <string>
using namespace std;

/*
345. 反转字符串中的元音字母
给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。

思路分析：
见到“反转字符串”，就要联想到一头一尾的双指针相向运动并交换数据。
*/
class Solution_0345 {
public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isVowel(s[i])) {
                ++i; // 非元音，则跳过
            } else if (!isVowel(s[j])) {
                --j; // 非元音，则跳过
            } else {
                // i, j同时指向元音
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};