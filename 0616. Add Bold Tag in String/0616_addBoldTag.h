#pragma once
#include <string>
#include <vector>
using namespace std;

/*
* 616. 给字符串添加加粗标签
给定字符串 s 和字符串数组 words。
对于 s 内部的子字符串，若其存在于 words 数组中， 则通过添加闭合的粗体标签 <b> 和 </b> 进行加粗标记。
  ● 如果两个这样的子字符串重叠，你应该仅使用一对闭合的粗体标签将它们包围起来。
  ● 如果被粗体标签包围的两个子字符串是连续的，你应该将它们合并。

返回添加加粗标签后的字符串 s 。
*/

/*
思路分析：区间标记（染色）
和“758. 字符串中的加粗单词”相同。
*/
class Solution {
public:
    string addBoldTag(string s, vector<string>& words)
    {
        int n = s.size();
        vector<bool> bold(n, false);

        for (const string& word : words) {
            int pos = s.find(word);
            while (pos != string::npos) {
                fill(bold.begin() + pos, bold.begin() + pos + word.size(), true);
                pos = s.find(word, pos + 1);
            }
        }

        string ans;
        for (int i = 0; i < n; ++i) {
            if (bold[i] && (i == 0 || !bold[i - 1])) {
                ans += "<b>";
            }
            ans += s[i];
            if (bold[i] && (i == n - 1 || !bold[i + 1])) {
                ans += "</b>";
            }
        }
        return ans;
    }
};