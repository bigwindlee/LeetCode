#pragma once
#include <vector>
using namespace std;

/*
419. 棋盘上的战舰
给你一个大小为 m x n 的矩阵 board 表示棋盘，其中，每个单元格可以是一艘战舰 'X' 或者是一个空位 '.' ，返回在棋盘 board 上放置的 舰队 的数量。
舰队 只能水平或者垂直放置在 board 上。换句话说，舰队只能按 1 x k（1 行，k 列）或 k x 1（k 行，1 列）的形状放置，其中 k 可以是任意大小。
两个舰队之间至少有一个水平或垂直的空格分隔 （即没有相邻的舰队）。
*/

/*
思路分析：枚举左上顶点
题目中给定的两艘战舰之间至少有一个水平或垂直的空位分隔，任意两个战舰之间是不相邻的，因此我们可以通过枚举每个战舰的左上顶点即可统计战舰的个数。
强调：题目规定两个舰队之间至少有一个水平或垂直的空格分隔，所以不必考虑不合法的case；例如[["X","X","X","X"],[".",".",".","X"],[".",".",".","X"]]
*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board)
    {
        int ans = 0;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X') { // 左边没有'X'，上边也没有'X'
                    if (i > 0 && board[i - 1][j] == 'X') {
                        continue;
                    }
                    if (j > 0 && board[i][j - 1] == 'X') {
                        continue;
                    }
                    ++ans; // 当前节点是一个舰队的左上顶点
                }
            }
        }
        return ans;
    }
};