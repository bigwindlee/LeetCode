#pragma once
#include <string>
using namespace std;

/*
1328. 破坏回文串
给你一个由小写英文字母组成的回文字符串 palindrome ，请你将其中 一个 字符用任意小写英文字母替换，使得结果字符串的 字典序最小 ，且 不是 回文串。
请你返回结果字符串。如果无法做到，则返回一个 空串 。

思路分析：
要求以`最小字典序`的方式对回文串进行破坏，那么要考虑以下几种情况：
1）长度为1的字符串始终都是回文，没法破坏，直接返回空串；
2）若长度为奇数，那么中间位置的字符无论怎么修改，都不能破坏回文，因此在循环中要跳过；
3）参数给定了是回文，那么参数的右半边是不需要处理的。也就是循环的范围限定左半边即可。

优化点：
假设参数长度为n，当n为偶数时，n/2是右半边字符串index的起点；当n是奇数时，n/2恰好是中间位置字符的index（修改中间位置字符无法破坏回文）；
因此设定循环的范围 i < n/2 是合适的！


*/
class Solution_1328 {
public:
    string breakPalindrome(string palindrome)
    {
        size_t n = palindrome.length();
        if (n < 2) // 长度<2的字符串，无法破坏回文！
            return "";

        // 循环的范围：只要处理回文的左半边即可；
        // 找到首个非'a'字符，将它修改为'a'，就得到答案！
        for (size_t i = 0; i < n / 2; ++i) {
            if (palindrome[i] > 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        // 回文左半边全是'a'，那么右半边必然也是全'a'，此时破坏回文的最小字典序是把最后一个字符修改为'b'。
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};