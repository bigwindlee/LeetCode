#pragma once
#include <vector>
using namespace std;

/*
651. 四个键的键盘
假设你有一个特殊的键盘包含下面的按键：
  ● A：在屏幕上打印一个 'A'。
  ● Ctrl-A：选中整个屏幕。
  ● Ctrl-C：复制选中区域到缓冲区。
  ● Ctrl-V：将缓冲区内容输出到上次输入的结束位置，并显示在屏幕上。

现在，你可以 最多 按键 n 次（使用上述四种按键），返回屏幕上最多可以显示 'A' 的个数 。
*/

/*
思路分析：动态规划
定义 dp[i] 为按键 i 次能得到的最多的A的个数
遍历所有的j值，从dp[j]开始复制，选出最大的dp[i]；
*/
class Solution {
public:
    int maxA(int n)
    {
        vector<int> dp(n + 1); // 定义 dp[i] 为按键 i 次能得到的最多的A的个数
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1; // 按A
            for (int j = 1; j < i - 2; ++j) { // dp[j]是要被复制的内容，留2次操作按"Ctrl-A"/"Ctrl-C"
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }
        return dp[n];
    }
};