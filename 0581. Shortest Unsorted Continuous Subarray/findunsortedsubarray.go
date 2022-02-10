package fundunsorted

import (
	"sort"
)

/* 581. Shortest Unsorted Continuous Subarray

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

func findUnsortedSubarray(nums []int) int {
	options := []func(nums []int) int{findUnsortedSubarray0}
	return options[0](nums)
}

func findUnsortedSubarray0(nums []int) int {
	dup := make([]int, len(nums))
	copy(dup, nums)
	sort.Ints(dup)
	i, j := 0, len(nums)-1
	for ; i < len(nums) && dup[i] == nums[i]; i++ {
	}
	for ; j > i && dup[j] == nums[j]; j-- {
	}
	return j - i + 1
}
