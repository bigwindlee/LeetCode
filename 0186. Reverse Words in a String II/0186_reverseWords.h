#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
186. 反转字符串中的单词 II
给你一个字符数组 s ，反转其中 单词 的顺序。
单词 的定义为：单词是一个由非空格字符组成的序列。s 中的单词将会由单个空格分隔。
必须设计并实现 原地 解法来解决此问题，即不分配额外的空间。
*/

/*
思路分析：首尾交换
见到反转（颠倒）字符序列，就要联想到首尾交换；
本题要求以单词为单位反转，并不反转单词本身，那么可以通过2次反转解决；
首先整体反转，然后利用空格界定单词，分别对每个单词进行反转（恢复单词的字符序列）；
*/

class Solution {
public:
    void reverseWords(vector<char>& s)
    {
        int n = s.size();
        reveseRange(s, 0, n - 1);
        int left = 0;
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                reveseRange(s, left, i - 1);
                left = i + 1;
            }
        }
    }

    void reveseRange(vector<char>& s, int i, int j)
    {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
};