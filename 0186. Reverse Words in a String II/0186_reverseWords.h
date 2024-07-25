#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
186. 反转字符串中的单词 II
给你一个字符数组 s ，反转其中 单词 的顺序。
单词 的定义为：单词是一个由非空格字符组成的序列。s 中的单词将会由单个空格分隔。
必须设计并实现 原地 解法来解决此问题，即不分配额外的空间。

思路分析：
见到反转字符串，就要联想到逆向扫描；以单词为单位进行反转，就要进行2次反转：
1次是对整句的反转，这样单词内部也被反转了；第2次针对每个单词进行反转，这样就把单词原地调整为正序了。

难点：
用left/right指针界定每个单词。
*/
class Solution {
public:
    void reverseWords(vector<char>& s)
    {
        int n = s.size();
        int right = n - 1;
        int p = 0, q = right; // p/q是用于反转的双指针
        // 第一次反转：对整句以char为单位进行倒序；
        while (p < q) {
            swap(s[p], s[q]);
            ++p;
            --q;
        }
        // 第二次反转：用left/right界定每个单词，对每个单词原地反转；
        while (right >= 0) {
            while (right >= 0 && s[right] == ' ') {
                --right;
            }
            if (right < 0) {
                return;
            }
            int left = right; // left从right开始向左扫描寻找空格字符，2个指针合作界定一个单词。
            while (left >= 0 && s[left] != ' ') {
                --left;
            }
            p = left + 1, q = right;
            while (p < q) { // 对每个单词原地反转
                swap(s[p], s[q]);
                ++p;
                --q;
            }
            right = left; // 迭代寻找下一个单词并进行反转
        }
    }
};