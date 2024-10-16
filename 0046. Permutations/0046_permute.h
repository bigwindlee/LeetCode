#pragma once
#include <vector>
using namespace std;

/*
LCR 083. 全排列
给定一个不含重复数字的整数数组 nums ，返回其 所有可能的全排列 。可以 按任意顺序 返回答案。
*/

/*
思路分析：回溯
全排列是最经典的回溯。
在循环中递归，遍历所有解空间。
第一维度（for循环）：path的每一个卡槽，都有n种可能。（严格的说，只能在剩下的球中任选一个，所以需要used标记数组。）
第二维度（递归函数）：要把path的每个卡槽都填满；很显然，递归的深度为n；
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size());
        backtrack(nums, used, path, ans);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& ans)
    {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                backtrack(nums, used, path, ans);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};
