#pragma once
#include <vector>
using namespace std;

/*
200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
*/

/*
思路分析：
典型的dfs；在搜索的过程中将小岛翻转，避免visited矩阵的开销；

要点：
    1）定义搜索方向；遍历搜索方向；
    2）递归lambda；显示指定返回类型；
    3）对二维数组执行dfs，每条搜索路径都是有独立起点的。对有效的起点进行计数，就是岛屿的数量。
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size(), n = grid[0].size();

        // 定义搜索方向
        vector<pair<int, int>> direct { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

        // 用递归lambda定义dfs
        // 无法推导出lambda表达式的返回类型的时候，必须明确指定；
        // 万能引用 auto&& self：允许 lambda 表达式递归地引用自己。
        auto dfs = [&](auto&& self, int i, int j) -> void {
            grid[i][j] = '0'; // 标记为已访问，本题无需回溯（恢复状态）
            for (auto [dx, dy] : direct) { // 遍历搜索方向
                int ni = i + dx;
                int nj = j + dy;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                    self(self, ni, nj);
                }
            }
        };

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(dfs, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};