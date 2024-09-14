#pragma once
#include <vector>
#include <numeric>
using namespace std;

/*
410. 分割数组的最大值
给定一个非负整数数组 nums 和一个整数 k ，你需要将这个数组分成 k 个非空的连续子数组。
设计一个算法使得这 k 个子数组各自和的最大值最小。
*/

/*
思路分析：二分查找
把数组切成k段，每一段（非空）放入一个桶里。求桶容量的最小值。
桶容量的下限，至少要保证可以把单个的最大值装下；
桶容量的上限，假设数组全部元素进入一个桶；
这种“极小化最大值”的问题非常适合使用二分查找：
  ● 通过确定区间的上下限，问题自然转换为一个`查找问题`，而不是单纯的构造问题。
*/
class Solution_0410 {
public:
	int splitArray(vector<int>& nums, int k) {
		int left = *max_element(nums.begin(), nums.end());  // 最小值是数组中的最大元素
		int right = accumulate(nums.begin(), nums.end(), 0);  // 最大值是数组的总和

		// 二分查找
		while (left < right) {
			int mid = left + (right - left) / 2; // 求中间值的通用写法，可避免潜在的溢出。

			// 检查是否可以将数组分割为 k 段，且每段的和不超过 mid
			if (canSplit(nums, mid, k)) {
				right = mid;  // 桶容量mid够用，收紧右边界
			}
			else {
				left = mid + 1;  // 桶容量mid不够用，mid是个无效值，可舍弃，所以 + 1；
			}
		}

		return left;  // 最终 left == right，就是我们要求的最小的最大值
	}

	// 辅助函数，用于判断在桶容量为 maxSum 的情况下，能否将数组分成 k 段
	bool canSplit(const vector<int>& nums, int maxSum, int k) {
		int currentSum = 0;  // 当前某个桶已占用的容量
		int count = 1; // 记录子数组的数量，初始时为 1

		for (int num : nums) {
			// 如果当前子数组的和加上当前元素不超过 maxSum
			if (currentSum + num <= maxSum) {
				currentSum += num;
			}
			else {
				// 否则，我们需要装入一个新桶；
				count++;
				currentSum = num;

				// 如果子数组的数量超过 k，说明当前的桶容量maxSum不够用。
				if (count > k) {
					return false;
				}
			}
		}

		return true;
	}
};
