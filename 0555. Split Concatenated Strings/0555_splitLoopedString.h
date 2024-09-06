#pragma once
#include <string>
#include <vector>
using namespace std;

/*
555. 分割连接字符串
给定一个字符串列表 strs，你可以将这些字符串连接成一个循环字符串，对于每个字符串，你可以选择是否翻转它。在所有可能的循环字符串中，你需要分割循环字符串（这将使循环字符串变成一个常规的字符串），然后找到字典序最大的字符串。
具体来说，要找到字典序最大的字符串，你需要经历两个阶段：
  1. 将所有字符串连接成一个循环字符串，你可以选择是否翻转某些字符串，并按照给定的顺序连接它们。
  2. 在循环字符串的某个位置分割它，这将使循环字符串从分割点变成一个常规的字符串。
你的工作是在所有可能的常规字符串中找到字典序最大的一个。

思路分析：
  1. 选择每个字符串的最优形式：对于给定的字符串列表 strs，可以选择保留每个字符串的原始形式或其翻转形式。为了得到字典序最大的结果，首先需要比较每个字符串及其翻转形式，选择字典序较大的那个作为该字符串的最优形式。
  2. 连接字符串：将所有字符串（经过选择最优形式后）按顺序连接起来，形成一个循环字符串。这个循环字符串可以从任意位置切分，切分后形成一个新的常规字符串。
  3. 尝试所有切割位置：对于循环字符串中的每个位置，将其视作分割点。需要分别尝试每个字符串的正序和反序形式，从不同的位置切割，形成新的字符串，并比较其字典序。
  4. 维护最大字典序字符串：在所有可能的切割方式中，维护字典序最大的那个字符串，最终返回该结果。

*/
class Solution_0555 {
public:
    string splitLoopedString(vector<string>& strs)
    {
        int n = strs.size();

        // 原字符串和反转字符串，选取字典序更大的，原地修改；
        // 除了要被剪开的字符串，剩下的字符串肯定是字典序更大的更好；
        for (auto& s : strs) {
            string rev(s.rbegin(), s.rend());
            if (rev > s) {
                s = rev;
            }
        }

        string ans;
        for (int i = 0; i < n; i++) {
            string rest;
            for (int j = i + 1; j < n; j++) {
                rest += strs[j]; // i 之后的字符串连接在一起
            }
            for (int j = 0; j < i; j++) {
                rest += strs[j]; // i 之前的字符串连接在一起
            }

            // i 字符串要被剪开，i 字符串本身并不确定保留大字典序效果更好，所以要都试试；
            auto begin = strs[i].begin(), end = strs[i].end(); // 试试不反转 i 字符串
            for (auto it = begin; it != end; ++it) {
                string tmp = string(it, end) + rest + string(begin, it);
                ans = max(ans, tmp);
            }
            auto rbegin = strs[i].rbegin(), rend = strs[i].rend(); // 试试反转 i 字符串
            for (auto it = rbegin; it != rend; ++it) {
                string tmp = string(it, rend) + rest + string(rbegin, it);
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};