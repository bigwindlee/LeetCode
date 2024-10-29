#pragma once
#include <vector>
using namespace std;

/*
162. 寻找峰值
峰值元素是指其值严格大于左右相邻值的元素。
给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
你可以假设 nums[-1] = nums[n] = -∞ 。
你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
*/

/*
思路分析：二分查找
见到O(log n)的时间复杂度，就要联想到二分查找！
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2; // 二分查找求中值的标准写法
            if (mid > 0 && nums[mid] < nums[mid - 1]) { // 左边有值且小于左边
                right = mid - 1;
            } else if (mid < n - 1 && nums[mid] < nums[mid + 1]) { // 右边有值且小于右边
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};