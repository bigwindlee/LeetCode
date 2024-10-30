#pragma once
#include <string>
#include <vector>
using namespace std;

/*
212. 单词搜索 II （困难）

给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words， 返回所有二维网格上的单词 。
单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母在一个单词中不允许被重复使用。
*/

/*
思路分析：回溯 + 前缀树
见到二维矩阵搜索单词，就要联想到回溯；见到多个单词的匹配问题，就要联想到前缀树；

要点：
    1）多个单词的搜索匹配，使用前缀树；在末字符节点保存整个单词，便于收集答案；收集之后清空，避免重复；
    2）标记当前节点已访问/回溯时恢复状态；这样可以节省visited矩阵的开销；
*/
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        int m = board.size(), n = board[0].size();
        vector<string> ans;

        // 使用words构造前缀树
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            TrieNode* cur = root; // 重要：处理每个word之前把cur恢复到root
            for (char c : word) {
                if (!cur->children[c - 'a']) {
                    cur->children[c - 'a'] = new TrieNode();
                }
                cur = cur->children[c - 'a']; // cur指针下移
            }
            cur->word = word; // cur指向末字符节点，将word保存在末字符节点。
        }

        // 使用lambda定义回溯函数
        auto backtrack = [&](auto&& self, TrieNode* cur, int i, int j) {
            char c = board[i][j];
            cur = cur->children[c - 'a']; // root 下移
            if (!cur) {
                return;
            }
            if (!cur->word.empty()) {
                ans.push_back(cur->word);
                cur->word.clear(); // 避免重复的收集这个单词
            }

            // 定义搜索方向
            vector<pair<int, int>> direct = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
            board[i][j] = 0; // 标记当前节点已访问
            for (auto& [dx, dy] : direct) { // 遍历搜索方向
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y]) {
                    self(self, cur, x, y);
                }
            }
            board[i][j] = c; // 回溯恢复状态
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                backtrack(backtrack, root, i, j);
            }
        }
        return ans;
    }

private:
    // 定义前缀树节点
    struct TrieNode {
        vector<TrieNode*> children; // 小写英文字母，26个卡槽；
        string word; // 在单词的末字符节点保存整个单词
        TrieNode()
            : children(26, nullptr) {}; // words[i] 由小写英文字母组成
    };
};