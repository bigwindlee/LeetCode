#pragma once
#include <vector>
using namespace std;

/*
279. 完全平方数
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
*/

/*
思路分析：（经典DP / 硬币找零）
找到最少数量的完全平方数，使其和为n，可以理解为一种特殊的硬币找零问题，其中每个硬币的值是完全平方数。
构建一个数组 dp，其中 dp[i] 表示组成数字 i 需要的最少完全平方数数量。
DP问题需要思考整体与部分的关系。
i由`完全平方数`组成，那么怎么定义`部分`呢？很自然的想法是从 i 中拿掉一个`完全平方数`，
也就是要思考 dp[i] 和 dp[i - j * j] 的关系，从而才能建立递推公式。
j的取值范围是 `(int j = 1; j * j <= i; ++j)`，要遍历所有的 j，寻找最小的dp[i - j*j];
所以递归公式建立：dp[i] = min(dp[i], 1 + dp[i - j * j]);

*/
class Solution_0279 {
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]); // 遍历所有的j值，寻找最小的dp[i - j*j]；
            }
        }
        return dp[n];
    }
};