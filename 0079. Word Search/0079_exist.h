#pragma once
#include <string>
#include <vector>
using namespace std;

/*
79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/

/*
思路分析：回溯
标准的回溯，但有很多的细节：
    1）优化1：字符总数超出
    2）优化2：字符频率超出
    3）使用lambda表达式定义回溯函数backtrack，注意lambda含递归的写法；
    4）在回溯函数中标记本节点已被访问（设置为0），这和以前的回溯模板（判断并标记下一个节点）不一样；
    5）这样做好处很多，①可以在主函数的for循环中避免标记/恢复；②避免了visited矩阵的开销；
    6）搜索方向的定义和遍历
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        // 优化1：字符总数超出
        if (word.size() > m * n) {
            return false;
        }

        // 优化2：字符频率超出
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ++freq1[board[i][j]];
            }
        }
        for (char c : word) {
            if (++freq2[c] > freq1[c]) {
                return false;
            }
        }

        // 定义搜索方向
        vector<vector<int>> direct { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

        // 定义回溯函数backtrack，注意这里使用了lambda表达式（含递归）
        // 注意lambda含递归的语法特点
        auto backtrack = [&](auto&& self, int i, int j, int idx) {
            // board 和 word 仅由大小写英文字母组成，已标记为0的节点肯定不相等；节省了visited矩阵的开销；
            if (board[i][j] != word[idx]) {
                return false;
            }
            // 在word的最后一个有效字符处判断，而不要等到更深一层的idx == word.size()；
            // 这是因为到达最后一个节点后，很有可能找不到有效的搜索方向，不能进入下一层。
            if (idx == word.size() - 1) {
                return true;
            }
            board[i][j] = 0; // 标记本节点已访问
            for (int k = 0; k < direct.size(); ++k) { // 遍历4个搜索方向
                int ni = i + direct[k][0];
                int nj = j + direct[k][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) { // 下一步的坐标有效
                    if (self(self, ni, nj, idx + 1)) {
                        return true;
                    }
                }
            }
            board[i][j] = word[idx]; // 本节点恢复现场
            return false;
        };

        // 回溯
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(backtrack, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};