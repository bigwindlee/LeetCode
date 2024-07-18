#pragma once
#include <vector>
using namespace std;

/*
162. 寻找峰值
峰值元素是指其值严格大于左右相邻值的元素。
给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
你可以假设 nums[-1] = nums[n] = -∞ 。
你必须实现时间复杂度为 O(log n) 的算法来解决此问题。

思路分析：
见到时间复杂度为 O(log n)，就要联想到二分查找法。
没错，无序的数组也可以使用二分查找法；因为题目要求返回“任何一个峰值”，只需要和左右的邻居比较即可。
难点：对于left和right的迭代，right要向左多走一步；left要向右多走一步；只有一个多走也行，两个都不多走，会陷入死循环！

优化点：
1. 首先看首末元素是不是峰值，如果蒙到了，就是常数时间复杂度；
*/
class Solution_0162 {
public:
    int findPeakElement(vector<int>& nums)
    {
        size_t n = nums.size();
        // 边界处理：看看首节点是不是峰值
        if (n == 1 || nums[0] > nums[1]) {
            return 0;
        }
        // 边界处理：看看末节点是不是峰值
        if (nums[n - 2] < nums[n - 1]) {
            return n - 1;
        }
        // 折半查找
        size_t left = 1, right = n - 2, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid - 1] > nums[mid]) {
                right = mid - 1; // right向左多走一步
            } else {
                left = mid + 1; // left向右多走一步
            }
        }
        return left; // 此时left/right重合
    }
};