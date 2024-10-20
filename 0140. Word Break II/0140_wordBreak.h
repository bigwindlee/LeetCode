#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
140. 单词拆分 II
给定一个字符串 s 和一个字符串字典 wordDict ，在字符串 s 中增加空格来构建一个句子，使得句子中所有的单词都在词典中。以任意顺序 返回所有这些可能的句子。
注意：词典中的同一个单词可能在分段中被重复使用多次。
*/

/*
思路分析：记忆化DFS + 回溯

*/
class Solution {
private:
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordSet;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        wordSet = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return ans[0];
    }

    void backtrack(const string& s, int idx)
    {
        if (ans.count(idx) > 0) {
            return;
        }
        if (idx == s.size()) {
            // 重要：回溯填充ans的起点！
            // 必须正确触达叶子节点，ans才能获得回溯填充的起爆点！
            // 否则ans[idx]为一个空的vector<string>，导致"for (const string& succ : ans[end])"不能进入循环，也就不会填充ans[idx]；
            ans[idx] = { "" };
            return;
        }
        for (int end = idx + 1; end <= s.size(); ++end) {
            string word = s.substr(idx, end - idx);
            if (wordSet.count(word)) { // 搜索路径上的所有word都出现在字典里，才能正确触达叶子节点，从而获得ans填充的起爆点！
                backtrack(s, end);
                // 在回溯阶段填充ans；依赖于ans[end]填充ans[idx]；从尾部向头部的逆向填充；
                for (const string& succ : ans[end]) {
                    ans[idx].push_back(succ.empty() ? word : word + " " + succ);
                }
            }
        }
    }
};
