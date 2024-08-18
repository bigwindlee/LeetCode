#pragma once
#include <vector>
using namespace std;

/*
200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

思路分析：
岛屿问题是经典的dfs，它的特点是，每条搜索路径都有独立的起点。

难点：
  - 对二维数组执行dfs，每条搜索路径都是有独立起点的。对有效的起点进行计数，就是岛屿的数量。

知识点： 
  - 怎样初始化一个二维vector数组？

优化思路：
  - 空间优化：利用grid本身做标记，这样就不需要visited数组了。把已经访问过的'1'元素设置为'X'。
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 每条搜索路径有独立的起点，计算有效起点的个数。
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, m, n, i, j, visited);
                    ++ans;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j, vector<vector<bool>>& visited)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        // 4个搜索方向（上下左右）
        dfs(grid, m, n, i - 1, j, visited);
        dfs(grid, m, n, i + 1, j, visited);
        dfs(grid, m, n, i, j - 1, visited);
        dfs(grid, m, n, i, j + 1, visited);
    }
};