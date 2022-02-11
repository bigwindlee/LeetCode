#include "MinPathSum.h"

/*
64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

/*
* ����һ���Ƚϼ򵥡�ֱ�׵Ķ�̬�滮�⡣
* dp[i][j] �Ķ����ǵ�����������С·���ͣ������ƶ�������������һ�����Ȼ��[i-1, j] ���� [i, j-1]��
* ��ô�������ҵ�״̬ת�Ʒ��̣�dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])
* ״̬ת�Ʒ��������ڵ�ǰ��������һ����ϱ�һ�㣬��� dp �����к�������Ϊ�߽�������������Ҳ���� i==0 ���� j == 0 �������
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
                // ״̬ת�Ʒ���
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m - 1][n - 1];
}