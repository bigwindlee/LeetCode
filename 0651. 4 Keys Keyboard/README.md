

```cpp
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
```