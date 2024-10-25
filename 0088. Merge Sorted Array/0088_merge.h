#pragma once
#include <vector>
using namespace std;

/*
88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，
其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
*/

/*
思路分析：三指针逆向扫描/填充
本题需要一点逆向思维。既然2个数组都有序，那么一个很自然的想法从分别从2个数组头部取出元素进行比较，较小的进入第3个数组（用于收集结果）；
但是如果要求不使用额外空间，那么是否可以用nums1来收集结果呢？
如果是从数组头部取出元素并比较，那么回填到nums1的时候会覆盖掉nums1本来的元素！
考虑到nums1的后半部分是空的，那么逆向思维一下，从2个数组的有效数据尾部开始扫描并比较，取出较大的，从nums1容量的尾部逆向填充，
这样就不会覆盖nums1的有效元素了！
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        // 三指针逆向扫描/填充
        // idx：nums1容量的末尾字符，逆向填充的起点；
        // i1: nums1有效数据的末尾字符
        // i2: nums2有效数据的末尾字符
        int idx = m + n - 1, i1 = m - 1, i2 = n - 1;
        while (i1 >= 0 || i2 >= 0) {
            if (i1 < 0) {
                nums1[idx--] = nums2[i2--];
            } else if (i2 < 0) {
                nums1[idx--] = nums1[i1--];
            } else if (nums1[i1] > nums2[i2]) {
                nums1[idx--] = nums1[i1--];
            } else {
                nums1[idx--] = nums2[i2--];
            }
        }
    }
};