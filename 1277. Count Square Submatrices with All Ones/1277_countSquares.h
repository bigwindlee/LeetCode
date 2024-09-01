#pragma once
#include <vector>
using namespace std;

/*
1277. 统计全为 1 的正方形子矩阵
给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。

思路分析：
思路1：（暴力破解）
考虑以(x, y)为左上角的正方形，边长从1开始，向右下角逐渐延展；
每次只需要检查正方形的“最下的横条”和“最右的竖条”，一旦发现有0，则全1正方形不成立，中止向右下角的延展！

思路2：（二维动态规划）
我们用 dp[i][j] 表示以 (i, j) 为右下角的全1正方形的最大边长，那么除此定义之外，dp[i][j] = x 也表示以 (i, j) 为右下角的正方形的数目为 x（即边长为 1, 2, ..., x 的正方形各一个）。
在计算出所有的 dp[i][j] 后，我们将它们进行累加，就可以得到矩阵中正方形的数目。

为什么是“以 (i, j) 为右下角”？因为只有这样，dp[i][j]才能和邻近的dp[i-1][j]、dp[i][j-1]、dp[i-1][j-1]发生联系，建立递归公式！
假如dp[i-1][j]、dp[i][j-1]、dp[i-1][j-1]的最小值为2，那么画图就会发现，正好可以把以(i, j)为右下角、边长为3的正方形涂上颜色。
所以递推公式建立：dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
*/
class Solution_1277 {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n)); // 二维DP
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j]; // 边界上的小正方形，以它为右下角的正方形只有1个；是否全1取决于它自己。
                } else if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1; // 递推公式
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

// 暴力破解
class Solution_1277_01 {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += allOnes(matrix, m, n, i, j);
            }
        }
        return ans;
    }

    // 以(x, y)为左上角的全1正方形的个数；同时也是边长length可以延展的最大有效数字。
    int allOnes(vector<vector<int>>& mat, int m, int n, int x, int y)
    {
        int length = 1; // 以(x, y)为左上角的正方形，边长从1开始，向右下角逐渐延展；
        do {
            bool find0 = false;
            // 只需要检查正方形的最下的横条和最右的竖条，一旦发现有0，则全1正方形不成立，中止向右下角的延展！
            for (int i = 0; i < length; ++i) {
                if (mat[x + length - 1][y + i] == 0) {
                    find0 = true;
                    break;
                }
                if (mat[x + i][y + length - 1] == 0) {
                    find0 = true;
                    break;
                }
            }
            if (find0) {
                break;
            }
            ++length; // 边长递增，向右下角延展。
        } while (x + length - 1 < m && y + length - 1 < n);
        return length - 1; // 到达此处的边长length是无效的，所有要减1.
    }
};