﻿#pragma once
#include <vector>
using namespace std;

/*
174. 地下城游戏
恶魔们抓住了公主并将她关在了地下城 dungeon 的 右下角 。地下城是由 m x n 个房间组成的二维网格。我们英勇的骑士最初被安置在 左上角 的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。
骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。
为了尽快解救公主，骑士决定每次只 向右 或 向下 移动一步。
返回确保骑士能够拯救到公主所需的最低初始健康点数。
注意：任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。
*/

/*
思路分析：二维DP + 逆向推导
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = dp[m - 1][n] = 1; // 公主坐标继续往下/往左的坐标，因为要逆推回去。

        // 从右下角逆向填表
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // 下一步的血量（取最小值） - 当前方格的数字 = 进入当前方格时的血量
                // 这也是为什么dp矩阵初始化为INT_MAX：小值才是有效值
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = max(dp[i][j], 1); // 至少一滴血，必须活着。
            }
        }
        return dp[0][0];
    }
};
