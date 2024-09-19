#pragma once
#include <string>
#include <vector>
using namespace std;

/*
* 17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

/*
思路分析：回溯
收集搜索树的每一条搜索路径，从根节点到达叶子节点。这是一种典型的回溯。

使用path来收集每一条搜索路径，很显然，可以用path的size来标记和控制搜索的深度；
把path的每一个卡槽填满，就到达了叶子节点，开始回溯。

第一维度（for循环）：键盘上的数字对应的字母取值范围。比方说第一个数字为2，那么第一维度就要遍历 'a', 'b', 'c' 三个字母；
第二维度（递归函数）：用path的size来标记和控制搜索的深度；用digits[path.size()]可以取得当前深度对应的digit；
*/
class Solution {
public:
    vector<string> key { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        vector<string> ans;
        string path;
        backtrack(digits, path, ans);
        return ans;
    }

    void backtrack(string& digits, string& path, vector<string>& ans)
    {
        if (path.size() == digits.size()) { // 卡槽填满，表示到达叶子节点。
            ans.emplace_back(path);
            return;
        }

        for (char c : key[digits[path.size()] - '0']) { // 第一维度的取值范围
            path.push_back(c);
            backtrack(digits, path, ans); // 第二维度，用path的size控制深度。
            path.pop_back();
        }
    }
};
