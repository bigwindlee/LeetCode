#pragma once
#include <vector>
using namespace std;

/*
* 
* 31. 下一个排列
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。

例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
给你一个整数数组 nums ，找出 nums 的下一个排列。

必须 原地 修改，只允许使用额外常数空间。

* 算法过程
标准的“下一个排列”算法可以描述为：

从后向前查找第一个相邻升序的元素对 (i,i+1)，满足 A[i] < A[i+1]。此时 [i+1,end) 必然是降序
在 [i+1,end) 从后向前查找第一个满足 A[i] < A[k] 的 k。A[i]、A[k] 分别就是上文所说的「小数」、「大数」
将 A[i] 与 A[k] 交换
可以断定这时 [i+1,end) 必然是降序，逆置 [i+1,end)，使其升序
如果在步骤 1 找不到符合的相邻元素对，说明当前 [begin,end) 为一个降序顺序，则直接跳到步骤 4

算法可视化：
https://github.com/bigwindlee/LeetCode/blob/master/0031.%20Next%20Permutation/README.md
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        // 从后向前查找第一个相邻升序的元素对 (i,i+1)，满足 A[i] < A[i+1]，对应图中的数字[5, 7]
        int i = n - 1;
        while (--i >= 0 && nums[i] >= nums[i + 1]);
        // 如果没有找到满足 A[i] < A[i+1]，退出循环是i为-1.

        if (i >= 0) {
            // 找到了相邻升序，在 [i+1,end) 从后向前查找第一个满足 A[i] < A[k] 的 k。
            // 也就是从末尾往左，寻找首个大于5的数字，对应图中的6.
            int j = n;
            while (nums[--j] <= nums[i]);
            swap(nums[i], nums[j]); // 交换图中的数字5和6
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
