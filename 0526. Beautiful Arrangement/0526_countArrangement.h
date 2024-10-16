#pragma once
#include <vector>
using namespace std;

/*
526. 优美的排列
假设有从 1 到 n 的 n 个整数。用这些整数构造一个数组 perm（下标从 1 开始），只要满足下述条件 之一 ，该数组就是一个 优美的排列 ：
perm[i] 能够被 i 整除
i 能够被 perm[i] 整除
给你一个整数 n ，返回可以构造的 优美排列 的 数量 。
*/

/*
思路分析：经典回溯 + 全排列 + 剪枝
backtrack返回值累加
*/
class Solution {
public:
    int countArrangement(int n)
    {
        vector<bool> used(n); // 默认值为false
        return backtrack(n, used, 1);
    }

    int backtrack(int n, vector<bool>& used, int depth)
    {
        if (depth > n) {
            return 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && ((i + 1) % depth == 0 || depth % (i + 1) == 0)) { // 剪枝
                used[i] = true;
                cnt += backtrack(n, used, depth + 1); // backtrack返回值累加
                used[i] = false;
            }
        }
        return cnt;
    }
};