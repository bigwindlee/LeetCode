#pragma once
#include <vector>
using namespace std;

/*
* 33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

思路分析：二分查找的变种

本题的关键在于，以mid为界对数组进行划分成左、右2个区间；
只有2种可能性：1）左区间有序，右区间部分有序；2）左区间部分有序，右区间有序；

如果 nums[left] <= nums[mid]，则左区间 left ~ mid 为递增的有序区间；
    1）如果target落在这个有序区间，则右区间可以排除掉，right边界内收；
    2）如果没落入，则左区间可以排除掉，left边界内收；

如果 nums[left] > nums[mid]，则右区间 mid ~ right 为递增的有序区间；
    1）如果target落入这个有序区间，则左区间可以排除掉，left边界内收；
    2）如果没落入，则右区间可以排除掉，right边界内收。

旋转数组的本质：
把数组分成2半，一定有一半是有序的。根据target是否落入这个有序的区间，对left/right边界进行内收，逐渐逼近target。
其实只需要一半区间有序就能完成折半！
*/
class Solution_0033 {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + right >> 1;
            if (nums[mid] == target)
                return mid;

            if (nums[left] <= nums[mid]) { // 左区间是有序区间
                if (nums[left] <= target && target < nums[mid]) {
                    // 落入有序区间，right边界内收
                    right = mid - 1;
                } else {
                    // 没落入，排除左区间，left边界内收
                    left = mid + 1;
                }
            } else { // 右区间是有序区间
                if (nums[mid] < target && target <= nums[right]) {
                    // 落入有序区间，left边界内收
                    left = mid + 1;
                } else {
                    // 没落入，排除右区间，right边界内收
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};