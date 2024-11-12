#pragma once
#include <vector>
using namespace std;

/*
2321. 拼接数组的最大分数
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，长度都是 n 。
你可以选择两个整数 left 和 right ，其中 0 <= left <= right < n ，接着 交换 两个子数组 nums1[left...right] 和 nums2[left...right] 。
例如，设 nums1 = [1,2,3,4,5] 和 nums2 = [11,12,13,14,15] ，整数选择 left = 1 和 right = 2，那么 nums1 会变为 [1,12,13,4,5] 而 nums2 会变为 [11,2,3,14,15] 。
你可以选择执行上述操作 一次 或不执行任何操作。
数组的 分数 取 sum(nums1) 和 sum(nums2) 中的最大值，其中 sum(arr) 是数组 arr 中所有元素之和。
返回 可能的最大分数 。
子数组 是数组中连续的一个元素序列。arr[left...right] 表示子数组包含 nums 中下标 left 和 right 之间的元素（含 下标 left 和 right 对应元素）。
*/

/*
思路分析：一维DP
本题有一点绕：差额数组的最大连续子数组的和，就是区间对换所能带来的最大收益！
*/
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size(), sum1 = 0, sum2 = 0;
        vector<int> diff1(n), diff2(n); // 差额数组
        for (int i = 0; i < n; ++i) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            // 填充差额数组
            diff1[i] = nums2[i] - nums1[i];
            diff2[i] = -diff1[i];
        }
        return max(sum1 + maxSubArray(diff1), sum2 + maxSubArray(diff2));
    }

private:
    int maxSubArray(vector<int>& nums)
    {
        int ans = INT_MIN, sum = 0;
        for (int num : nums) {
            sum = num + max(0, sum);
            ans = max(ans, sum);
        }
        return ans;
    }
};