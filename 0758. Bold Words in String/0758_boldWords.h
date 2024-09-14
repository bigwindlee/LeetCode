#pragma once
#include <string>
#include <vector>
using namespace std;

/*
758. 字符串中的加粗单词
给定一个关键词集合 words 和一个字符串 s，将所有 s 中出现的关键词 words[i] 加粗。所有在标签 <b> 和 <b> 中的字母都会加粗。
加粗后返回 s 。返回的字符串需要使用尽可能少的标签，当然标签应形成有效的组合。
*/

/*
思路分析：区间标记
可以把这个算法理解为`区间染色`的方式。具体来说，算法通过一个布尔数组 bold 对字符串 s 的每个字符进行标记，类似于对字符串的某些区间进行染色。
  ● 初始化：创建一个布尔数组 bold，长度和字符串 s 相同，初始值为 false，表示默认情况下没有字符需要加粗。
  ● 查找匹配的子串并染色：对于每一个在 words 中的子串，使用 find 查找该子串在 s 中出现的位置，并将该位置到子串结束的位置对应的 bold 数组的元素设为 true，即染色这个区间。
  ● 合并连续的染色区间：在输出时，如果遇到连续的 true，我们用 <b> 和 </b> 标签包裹它们，就像你处理“染色块”一样。
*/
class Solution_0758 {
public:
    string boldWords(vector<string>& words, string s)
    {
        int n = s.size();
        vector<bool> bold(n, false);

        // 标记需要加粗的字符
        for (const string& word : words) {
            int pos = s.find(word);
            while (pos != string::npos) {
                fill(bold.begin() + pos, bold.begin() + pos + word.size(), true); // 染色
                pos = s.find(word, pos + 1);
            }
        }

        // 构建结果字符串
        string ans;
        for (int i = 0; i < n; ++i) {
            if (bold[i] && (i == 0 || !bold[i - 1])) { // 被染色区间的左边界
                ans += "<b>";
            }
            ans += s[i];
            if (bold[i] && (i == n - 1 || !bold[i + 1])) { // 被染色区间的右边界
                ans += "</b>";
            }
        }

        return ans;
    }
};