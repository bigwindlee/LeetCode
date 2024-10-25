#pragma once
#include <vector>
using namespace std;

/*
26. 删除有序数组中的重复项
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
  ● 更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
  ● 返回 k 。
*/

/*
思路分析：双指针
既然数组是有序的，那么只需要找到所有不同于左边的数字，从数组头部依次回填就好了。
i: 指示回填的下标，连续增长；
j: 寻找所有不同于左边的数字，按照i的指示进行回填；
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i = 0; // 回填指示
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[j - 1]) { // 不同于左边
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};