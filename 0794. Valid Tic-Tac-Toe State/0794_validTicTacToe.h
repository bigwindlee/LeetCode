﻿#pragma once
#include <string>
#include <vector>
using namespace std;

/* -------------------------------------------------------------------------------------------------------------------------
794. 有效的井字游戏
给你一个字符串数组 board 表示井字游戏的棋盘。当且仅当在井字游戏过程中，棋盘有可能达到 board 所显示的状态时，才返回 true 。
井字游戏的棋盘是一个 3 x 3 数组，由字符 ' '，'X' 和 'O' 组成。字符 ' ' 代表一个空位。

以下是井字游戏的规则：
  ● 玩家轮流将字符放入空位（' '）中。
  ● 玩家 1 总是放字符 'X' ，而玩家 2 总是放字符 'O' 。
  ● 'X' 和 'O' 只允许放置在空位中，不允许对已放有字符的位置进行填充。
  ● 当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
  ● 当所有位置非空时，也算为游戏结束。
  ● 如果游戏结束，玩家不允许再放置字符。  
*/

/* -------------------------------------------------------------------------------------------------------------------------
思路分析：穷举
题意要求判断盘面是否是对弈过程中有效的状态。
解读一下有效状态的含义：
    1）不能有2个胜利者；
    2）X先手，所以`X`的数量要么和`O`相同，要么多一个；
    3）X先手胜，则`X`的数量比`O`多一个；
    4）O后手胜，则`X`的数量和`O`相同；    

疑问：是否应该加一条规则：盘面不能出现某个player胜利2次的情况？
答案：不用加。
    1）首先，胜利2次的情况可以出现在对角线：["XOX","OXO","XOX"]，中间的`X`是最后一步棋，造成2条对角线都连接上了。
    2）其次，如果是在三横三纵中出现胜利2次，那么棋子的数目对不上，胜者6颗，败者3颗，判断无效的第一个条件就是检查棋子数目；所以这种情况已经排除了。

要点：
  ● 穷举`有效`或`无效`的情况都可以；穷举`有效`的情况更容易理解；
*/
class Solution {
public:
    bool validTicTacToe(vector<string>& board)
    {
        int countX = 0, countO = 0;
        // 统计棋子数量
        for (string& row : board) {
            for (char c : row) {
                countX += (c == 'X') ? 1 : 0;
                countO += (c == 'O') ? 1 : 0;
            }
        }

        // 穷举有效的情况（更容易理解）
        if (win(board, 'X') && win(board, 'O')) {
            return false;
        }
        if (win(board, 'X')) {
            return countX == countO + 1;
        }
        if (win(board, 'O')) {
            return countX == countO;
        }
        return countX == countO || countX == countO + 1;

        // 穷举`无效`的情况也是可以的
        // bool invalid = (countX != countO && countX != countO + 1) ||
        //                (win(board, 'X') && countX != countO + 1) ||
        //                (win(board, 'O') && countX != countO);
        // return !invalid;
    }

    // 穷举所有胜利的情况：三横三纵 + 两条对角线
    bool win(vector<string>& board, char p)
    {
        // 三横三纵
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == p && board[i][1] == p && board[i][2] == p) || (board[0][i] == p && board[1][i] == p && board[2][i] == p)) {
                return true;
            }
        }

        // 两条对角线
        return ((board[0][0] == p && board[1][1] == p && board[2][2] == p) || (board[0][2] == p && board[1][1] == p && board[2][0] == p));
    }
};