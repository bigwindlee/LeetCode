#include "MinPathSum.h"

/*
64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

/*
* 这是一道比较简单、直白的动态规划题。
* dp[i][j] 的定义是到达这个点的最小路径和；根据移动规则，这个点的上一个点必然是[i-1, j] 或者 [i, j-1]；
* 那么很容易找到状态转移方程：dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])
* 状态转移方程依赖于当前坐标的左边一点和上边一点，因此 dp 的首行和首列作为边界条件单独处理，也就是 i==0 或者 j == 0 的情况。
*/
int MinPathSum::minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else if (i == 0) {
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            } else {
                // 状态转移方程
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m - 1][n - 1];
}