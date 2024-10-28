#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
15. 三数之和
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
*/

/*
思路分析：双指针
枚举i值，对i右边的区间，使用双指针进行夹逼。
预先排序很关键；这样当sum<0的时候，left指针进行区间内收（右移）；当sum>0时，right指针进行区间内收（左移）；
注意要跳过相同的数字；
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end()); // 预先排序很关键
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) { // 当前nums[i]是一个重复的数字，跳过
                continue;
            }

            int left = i + 1, right = n - 1; // 当前nums[i]右边的区间边界
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    while (++left < right && nums[left] == nums[left - 1]); // left右移并跳过相同数字
                } else if (sum > 0) {
                    while (left < --right && nums[right] == nums[right + 1]); // right左移并跳过相同数字
                } else {
                    ans.push_back({ nums[i], nums[left], nums[right] });
                    while (++left < right && nums[left] == nums[left - 1]);
                    while (left < --right && nums[right] == nums[right + 1]);
                }
            }
        }
        return ans;
    }
};