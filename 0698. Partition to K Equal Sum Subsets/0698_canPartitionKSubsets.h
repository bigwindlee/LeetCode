#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

/*
698. 划分为k个相等的子集
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

思路分析：
集合划分问题，将一个集合划分为多个满足条件的子集，是回溯法的经典应用。
集合中每个元素都要尝试着进入每一个子集（桶），每一个桶都是一条搜索方向。
搜索过程中，出现下列情况需要剪枝：
1）如果入桶会造成溢出，剪枝；
2）相同的搜索路径且以证明失败，剪枝；
*/
class Solution_0698 {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) {
            return false;
        }
        vector<int> bucket(k);
        sort(nums.rbegin(), nums.rend()); // 降序排列，减少分支数
        return backtrack(nums, bucket, k, 0, totalSum / k);
    }

    bool backtrack(vector<int>& nums, vector<int>& bucket, int k, int idx, int targetSum)
    {
        if (idx == nums.size()) {
            // 走到这儿，说明每个idx都入桶了，而且每个桶都没溢出，那么只有一种可能：每个桶的和都是targetSum。
            return true;
        }
        // 每一个桶都是一条搜索路径；nums[idx]要尝试着进入每一个桶，失败则回溯。
        for (int i = 0; i < k; ++i) {
            // (i > 0 && bucket[i - 1] == bucket[i]) 是一个重要的剪枝技巧！
            // 因为按照遍历解空间的顺序，nums[idx]如果能进入bucket[i]，且满足(i > 0 && bucket[i - 1] == bucket[i])，
            // 这意味着nums[idx]进入bucket[i]和进入bucket[i-1]是一条相同的搜索路径，而且前一次已经证明这是一条失败的路径（否则早就返回true了）。
            if (bucket[i] + nums[idx] > targetSum || (i > 0 && bucket[i - 1] == bucket[i])) {
                continue;
            }
            bucket[i] += nums[idx];
            if (backtrack(nums, bucket, k, idx + 1, targetSum)) {
                return true;
            }
            bucket[i] -= nums[idx];
        }
        // 必须在穷尽所有的搜索路径之后，实在找不到合法的解，才会返回false；
        // 不能发现一条搜索路径失败，就返回false！
        return false;
    }
};