#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
回溯法

注意理解题目要求：
    求“全排列”，但是“不重复”的全排列，因为nums中可能包含重复的数字。

解题思路：
    求“全排列”的for循环中，i的范围是[0, nums.size()-1]，但是怎么“去重”呢？
    把nums排序，让相同的数字聚拢。对于相同的数字序列，只有首个数字可以牵头建立一条搜索路径；
    也就是说，一条搜索路径可以走下去（不剪枝）的条件是：
        1）!used[i]，这个数字没被使用；
        2）i == 0，首个数字
        3）如果不是首个数字，nums[i] != nums[i-1]，不处于相同数字序列
        4）处于相同序列的非首个数字，则要求：used[i - 1] == true，前个数字已被使用，当前数字不牵头

    以上条件是理解本题的关键！

*/
class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<bool> used(nums.size());

        sort(nums.begin(), nums.end()); // 排序让相同数字序列聚拢到一起，方便“去重”。
        backtrack(nums, used);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<bool>& used)
    {
        if (path.size() == nums.size()) {
            ans.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // 以下if语句是理解本题的关键（核心要点）：重复数字不牵头！
            if (!used[i] && (i == 0 || nums[i] != nums[i - 1] || used[i - 1])) {
                used[i] = true;
                path.emplace_back(nums[i]);
                backtrack(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};