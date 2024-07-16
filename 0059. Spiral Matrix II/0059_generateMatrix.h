#pragma once
#include <vector>
using namespace std;

/*
59. 螺旋矩阵 II
给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

思路分析：
观察矩阵中元素按顺时针旋转的运动规律，用二维数组定义出4个方向。矩阵的原点在左上角，向右是列增长(y+1)，向下是行增长(x+1)。
转向的技巧：di = (++di) % 4;

知识点：
1. 二维动态数组的定义：vector<vector<int>> ans(n, vector<int>(n, 0));
2. 二维静态数组的定义：int direct[][2]
3. 转向的技巧：di = (++di) % 4;
*/
class Solution_0059 {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0)); // 定义动态二维数组
        int direct[][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; // 定义静态二维数组不用vector
        int di = 0; // direction index，表示当前方向。
        int i = 0, x = 0, y = 0; // i是用来填充的数字，最大到n*n。(x, y)是要填充的坐标。
        while (++i <= n * n) {
            ans[x][y] = i;
            // 看看沿着原方向前进的坐标是否有效
            int x1 = x + direct[di][0];
            int y1 = y + direct[di][1];
            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || ans[x1][y1] != 0) {
                di = (++di) % 4; // 坐标溢出，或者碰到已经填充过的，则发生转向！
            }
            x += direct[di][0];
            y += direct[di][1];
        }
        return ans;
    }
};