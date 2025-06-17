#pragma once
#include <vector>
using namespace std;

/*
经典动规 / 0-1背包 （重量受限，价值最大！）
在花费（budget）受限的情况下，求可能的最大收益。
每一支股票，只有2种可能性：在、或者不在最终的最佳组合里；
dp[j]表示花费为j时对应的最大收益dp[j]；
那么枚举每一支股票present[i]，它只有2种可能性，在、或者不在dp[j]中；
如果在，那么可以把它的收益(future[i] - present[i])单独拿出来，剩下的收益就是dp[j - present[i]]；
递推公式建立：dp[j] = max(dp[j], dp[j - present[i]] + future[i] - present[i]);
*/
class Solution_2291 {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget)
    {
        vector<int> dp(budget + 1); // dp[j]表示花费为j时对应的最大收益dp[j]；用受限条件做下标！
        for (int i = 0; i < present.size(); ++i) { // 枚举每一支股票
            int cost = present[i], profit = future[i] - present[i];
            for (int j = budget; j >= cost && profit > 0; --j) {
                dp[j] = max(dp[j], dp[j - cost] + profit); // 0-1背包递推公式！
            }
        }
        return dp[budget];
    }
};
