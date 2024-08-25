#pragma once
#include <numeric>
#include <vector>
using namespace std;

/*
* 724. 寻找数组的中心下标
给你一个整数数组 nums ，请计算数组的 中心下标 。
数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。

思路分析：
方法一：前缀和
记数组的全部元素之和为 total，当遍历到第 i 个元素时，设其左侧元素之和为 sum，则其右侧元素之和为 total - sum - nums[i]
左右侧元素和相等即为：
sum（左）+ nums[i] + sum（右）= total
也就是：
2 * sum + nums[i] = total  // 理解了这一点，就不需要把前缀和存在数组里！

当中心索引左侧或右侧没有元素时，即为零个项相加，这在数学上称作「空和」（empty sum）。在程序设计中我们约定「空和是零」。
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int pre_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (pre_sum * 2 + nums[i] == total) {
                return i;
            }
            pre_sum += nums[i];
        }
        return -1;
    }
};