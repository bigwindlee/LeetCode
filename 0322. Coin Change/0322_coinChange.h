#pragma once
#include <vector>
using namespace std;

/*
322. 零钱兑换
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。
*/

/*
经典动态规划

dp[i]表示凑成总金额i，最少需要的硬币个数。
不能用INT_MAX来初始化dp数组，否则会出现："runtime error: signed integer overflow"
凑成amount理论上最多使用amount个硬币（使用最小面值1元硬币），
所以可以用 amount + 1 来初始化dp数组。

状态转移方程的建立：
从总金额i中拿掉任一面值的coin: dp[i] = dp[i - coins[j]] + 1
因为追求最少的硬币数，所以要遍历每一种面值的coin，筛选出最小的dp[i]

注意：本题和“279. 完全平方数”的区别在哪里？
完全平方数理论上是可以凑出来的，大不了全部由1凑出来。
而本题的coins面值是不确定的，存在凑不出来的情况；例如面值为[2]，肯定凑不出来3；
所有dp数组的初值不能用 INT_MAX 来初始化；否则 dp[1] 的初始值为 INT_MAX ，而且没有机会改变；
那么在凑3的时候，剪掉面值2，剩下1，这个时候 1 + dp[1] 就会溢出！

考虑到面值为整数，最小为1，那么凑成amount的硬币数最多就是amount（用最小面值1）;
所有用 amount+1 的值来初始化dp数组是合适的；如果某个amount凑不出来，那么dp[amount]的值会大于amount；
*/

class Solution_0322_02 {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        // dp[i]表示凑成总金额i，最少需要的硬币个数
        // 用 amount + 1 来初始化dp数组（不能用INT_MAX，因为存在凑不出来的情况。）
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {

            // 遍历每一种面值的coin，拿掉它，筛选出最小的dp[i]
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // 初始化成 amount + 1，理论上有效的最大值为 amount，
        // 所以大于amount意味着凑不出来。
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
