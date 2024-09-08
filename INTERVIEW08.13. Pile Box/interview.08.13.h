#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
面试题 08.13. 堆箱子
堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高 hi。箱子不能翻转，将箱子堆起来时，下面箱子的宽度、高度和深度必须大于上面的箱子。实现一种方法，搭出最高的一堆箱子。箱堆的高度为每个箱子高度的总和。
输入使用数组[wi, di, hi]表示每个箱子。
*/

/*
思路分析：（经典DP / 最长递增子序列）
本质上是“最长递增子序列”，解题套路也是一样的。
*/
class Solution {
public:
    int pileBox(vector<vector<int>>& box)
    {
        int n = box.size();
        // 默认按字典序进行排序，无需自定义比较函数。
        sort(box.begin(), box.end());
        vector<int> dp(n); // dp[i] 表示以箱子 i 为底的最大堆叠高度
        for (int i = 0; i < n; ++i) {
            dp[i] = box[i][2]; // 初始高度是当前箱子的高度
            for (int j = 0; j < i; ++j) {
                // 枚举i左边的每一个j，只要box[j]的三个维度都比box[i]小，以box[j]为底的序列就和box[i]连接上，
                // 形成以box[i]为底的新的子序列；用新的堆叠高度挑战dp[i]。
                if (box[j][0] < box[i][0] && box[j][1] < box[i][1] && box[j][2] < box[i][2]) {
                    dp[i] = max(dp[i], box[i][2] + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end()); // 返回集合中最大元素的迭代器，然后`解引用`。
    }
};
