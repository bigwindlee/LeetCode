#pragma once
#include <vector>
using namespace std;

/*
528. 按权重随机选择
给你一个 下标从 0 开始 的正整数数组 w ，其中 w[i] 代表第 i 个下标的权重。
请你实现一个函数 pickIndex ，它可以 随机地 从范围 [0, w.length - 1] 内（含 0 和 w.length - 1）选出并返回一个下标。选取下标 i 的 概率 为 w[i] / sum(w) 。
例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。

思路分析：前缀和 + 二分查找
*/
class Solution {
public:
    Solution(vector<int>& w) { this->w = w; }

    int pickIndex()
    {
        int n = w.size();
        vector<int> preSum(n); // 前缀和数组
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += w[i];
            preSum[i] = sum;
        }
        int r = rand() % sum + 1; // 随机数，分布区间：[1, sum]
        // 折半查找，为r找到合适的房间（其房间号就是要返回的下标）
        // r所在的房间i满足条件：preSum[i-1] < r && r <= preSum[i]
        // 如果i-1存在的话。
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (r > preSum[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    vector<int> w;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */