﻿#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
思路分析：双指针(left/right)    
数组排序；固定住i，j；j右边的区间使用双指针相对运动；    
有2个坑：
  - i、j跳过相同数字的判断条件：`i > 0` 和 `j > i + 1` 不能少！否则会跳过不该跳的数字！
  - 用long变量存储四数之和，int相加会返回int，可能溢出，必须前置一个`0L + `！
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> ans;

        // 先对数组进行排序
        std::sort(nums.begin(), nums.end());

        int n = nums.size();

        // 第一层循环，固定第一个数字
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) { // 跳过重复的第一个数字
                continue;
            }

            // 第二层循环，固定第二个数字
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) { // 跳过重复的第二个数字；`j > i + 1`很重要！否则会跳过不该跳的数字！
                    continue;
                }

                // 双指针部分，寻找第三个和第四个数字
                int left = j + 1;
                int right = n - 1;

                long half = 0L + nums[i] + nums[j];
                while (left < right) {
                    long sum = half + nums[left] + nums[right];
                    if (sum == target) {
                        ans.push_back({ nums[i], nums[j], nums[left], nums[right] }); // 找到一个符合条件的四元组
                        while (++left < right && nums[left] == nums[left - 1]); // left右移并跳过相同数字
                        while (left < --right && nums[right] == nums[right + 1]); // right左移并跳过相同数字
                    } else if (sum < target) {
                        while (++left < right && nums[left] == nums[left - 1]); // left右移并跳过相同数字
                    } else {
                        while (--right > left && nums[right] == nums[right + 1]); // right左移并跳过相同数字
                    }
                }
            }
        }

        return ans;
    }
};
