#pragma once
#include <string>
#include <vector>
using namespace std;

/*
14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

提示：
    ● 1 <= strs.length <= 200
    ● 0 <= strs[i].length <= 200
    ● strs[i] 仅由小写英文字母组成
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        // 最长公共前缀必然是strs[0]的子集
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};