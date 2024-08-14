#pragma once
#include <unordered_set>
#include <vector>
using namespace std;

/*
2367. 算术（等差）三元组的数目
给你一个下标从 0 开始、严格递增 的整数数组 nums 和一个正整数 diff 。如果满足下述全部条件，则三元组 (i, j, k) 就是一个 算术三元组 ：
i < j < k ，
nums[j] - nums[i] == diff 且
nums[k] - nums[j] == diff
返回不同 算术三元组 的数目。

思路分析1：
最直观的解法是三重循环暴力枚举；很显然，没有利用“严格递增”的条件！

思路分析2：
充分利用“严格递增”，一边遍历数组，一边在哈希表中查找“队友”是否在里面，一边把自己加入哈希表。和“1. 两数之和”的思路完全一样。
注意 i < j < k ，因为严格递增，那么 nums[i] < nums[j] < nums[k] ；
遍历到nums[i]时，nums[j] 和 nums[k] 肯定是不在哈希表里面。
所以在遍历过程中，要询问“更小的队友”在不在，因为小值先入表！

与其穷举所有可能的三元组再计算其差值，不如直接用差值计算出队友的值，并用哈希表判断队友是不是存在！
*/
class Solution_2367_01 { // 三重循环暴力枚举
public:
    int arithmeticTriplets(vector<int>& nums, int diff)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if ((nums[j] - nums[i] == diff) && (nums[k] - nums[j] == diff)) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution_2367_02 { // 哈希表
public:
    int arithmeticTriplets(vector<int>& nums, int diff)
    {
        int ans = 0;
        unordered_set<int> hash;
        for (int i : nums) {
            if (hash.count(i - diff) && hash.count(i - 2 * diff)) { // 询问“更小”的队友在不在？小值先入表！
                ++ans;
            }
            hash.insert(i); // 自己加入哈希表
        }

        return ans;
    }
};