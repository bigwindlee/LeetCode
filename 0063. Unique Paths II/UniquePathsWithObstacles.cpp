#include "UniquePathsWithObstacles.h"

int UniquePathsWithObstacles::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // dp[i][j] 表示到达对应坐标点一共有多少条独立的路径；
    // vector<int> 默认初始化为 0 值。
    vector<vector<int>> dp(m, vector<int>(n));

    // 首行和首列必须手动的初始化，用作 DP 的边界条件。
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1)
            break; // 首行遇到障碍，之后都无法到达。
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (obstacleGrid[0][i] == 1)
            break; // 首列遇到障碍，之后都无法到达。
        dp[0][i] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1)
                continue;

            // 状态转移方程
            // 无需单独考虑上一个状态可能为 obstacle 的情况，因为 dp 已经默认初始化为 0 。
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}