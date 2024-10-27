#pragma once
#include <vector>
using namespace std;

/*
4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。
*/

/*
思路分析：二分查找
见到有序、log时间复杂度，就要联想到二分查找；
i/j分别表示nums1/nums2在红线左边的元素个数；i/j是联动的，i + j = (m+n+1)/2;
用折半查找法确定i的值即可；
本题的难点在于如何确定i是偏大，还是偏小；
正确的红线划分要满足2个交叉比较条件：
nums1[i-1] < nums2[j]; i太大会破坏这一条
nums2[j-1] < nums1[i]; i太小会破坏这一条
要会分析i偏大/偏小会分别破坏哪一条规则，从而可以决定折半查找区间的哪一个边界内收。（核心难点）
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1); // 确保短数组在前
        }
        // 画一条红线，nums1有i个元素在红线左边，nums2有j个元素在红线左边；且左边所有元素小于右边；
        // 约定红线左边元素个数和右边相等（总长度为偶数），或者比右边多一个（总长度为奇数）
        // i + j = (m+n+1)/2，可统一处理数组总长度为奇数或偶数的情况
        // 用折半查找确定i的值
        int left = 0, right = m; // 折半查找的初始边界
        while (left <= right) {
            int i = left + (right - left) / 2; // 防止left+right溢出的小技巧
            int j = (m + n + 1) / 2 - i;
            // 要满足红线左边所有元素小于右边，要同时满足2个交叉比较：
            // nums1[i-1] < nums2[j]; i太大会破坏这一条
            // nums2[j-1] < nums1[i]; i太小会破坏这一条
            if (i > 0 && nums1[i - 1] > nums2[j]) {
                // i太大，向左走；右边界内收
                right = i - 1;
            } else if (i < m && nums2[j - 1] > nums1[i]) {
                // i太小，向右走；左边界内收
                // 思维难点：结合（红线左边数量和右边数量相等或多一个）的条件，(i<m)一定可以推导出(j>0)
                // 但反之，(j>0)并不能推导出(i<m)
                left = i + 1;
            } else {
                // i不大也不小，刚刚好
                int maxLeft = max((i == 0) ? INT_MIN : nums1[i - 1], (j == 0) ? INT_MIN : nums2[j - 1]);
                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }
                int minRight = min((i == m) ? INT_MAX : nums1[i], (j == n) ? INT_MAX : nums2[j]);
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0; // 如果没有找到中位数，返回0（正常情况下不会到达这里）
    }
};
