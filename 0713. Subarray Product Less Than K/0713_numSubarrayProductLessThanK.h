#pragma once
#include <vector>
using namespace std;

/*
713. 乘积小于 K 的子数组
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。

思路分析：
见到“连续子数组”，就要联想到滑动窗口。
注意“滑动窗口”的编程模板：一般都是枚举右边界，计算累计值，比较累计值是否突破限定条件，滑动左边界，缩小区间。

难点：
    每一轮for循环枚举j，计算以j结尾的连续子数组的个数，转化为求闭区间[i, j]中元素的个数！
*/
class Solution_0713 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        // 1 <= nums[i] <= 1000
        if (k <= 1) {
            return 0;
        }

        int ans = 0;
        int product = 1;
        int i = 0;
        // 滑动窗口：枚举右边界，连续滑动左边界。
        for (int j = 0; j < nums.size(); ++j) {
            product *= nums[j];
            // 如果乘积超出，则连续滑动左边界，缩小区间。
            while (product >= k) {
                product /= nums[i++];
            }
            // 跳出while循环时，闭区间[i, j]乘积小于k；
            // 难点：[i, j]闭区间的元素个数是(j-i+1)，而以j结尾的连续子数组个数也是(j-i+1)。
            // 为什么是以j结尾呢？因为for循环枚举j值，统计以j结尾的连续子数组可以避免重复统计。
            // 想象以j为起点的箭头向左逐渐延伸，箭头正好逐一指向区间每个元素。
            ans += j - i + 1;
        }
        return ans;
    }
};
