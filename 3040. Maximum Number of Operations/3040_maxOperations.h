#pragma once
#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;

/*
3040. 相同分数的最大操作数目 II
给你一个整数数组 nums ，如果 nums 至少 包含 2 个元素，你可以执行以下操作中的 任意 一个：
  ● 选择 nums 中最前面两个元素并且删除它们。
  ● 选择 nums 中最后两个元素并且删除它们。
  ● 选择 nums 中第一个和最后一个元素并且删除它们。

一次操作的 分数 是被删除元素的和。
在确保 所有操作分数相同 的前提下，请你求出 最多 能进行多少次操作。
请你返回按照上述要求 最多 可以进行的操作次数。
*/

/*
思路分析：记忆化DFS （常规DFS会超时）
见到“你可以执行以下操作中的 任意 一个”，就要联想到DFS，每一种操作都是一条搜索路径；
本题的难点在于常规DFS会超时，会有大量重复的搜索，因此需要把搜索结果存储起来，避免重复；
使用最高效的原生数组作为cache，使用哈希表unordered_map会超时！

要点：
    1）常规DFS超时，记忆化DFS，采用原生二维数组做cache最高效；
    2）使用function模板定义递归的lambda表达式；
*/
class Solution {
public:
    int maxOperations(vector<int>& nums)
    {
        unordered_map<string, int> cache;
        int memo[2001][2001]; // 已知：2 <= nums.length <= 2000
        memset(memo, -1, sizeof(memo)); // 已知：1 <= nums[i] <= 1000

        // 使用function定义递归lambda的例子
        function<int(int, int, int)> dfs = [&](int left, int right, int score) {
            if (right <= left) {
                return 0;
            }
            if (memo[left][right] != -1) {
                return memo[left][right];
            }
            int ans = 0;
            if (nums[left] + nums[left + 1] == score) {
                ans = max(ans, 1 + dfs(left + 2, right, score));
            }
            if (nums[left] + nums[right] == score) {
                ans = max(ans, 1 + dfs(left + 1, right - 1, score));
            }
            if (nums[right - 1] + nums[right] == score) {
                ans = max(ans, 1 + dfs(left, right - 2, score));
            }
            return memo[left][right] = ans;
        };

        int n = nums.size();
        return 1 + max({ dfs(2, n - 1, nums[0] + nums[1]), dfs(0, n - 3, nums[n - 2] + nums[n - 1]), dfs(1, n - 2, nums[0] + nums[n - 1]) });
    }
};