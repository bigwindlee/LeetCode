package containsnearby

import (
	. "leetcomm"
)

/* 219. Contains Duplicate II
Given an array of integers and an integer k, find out whether there are two
distinct indices i and j in the array such that nums[i] = nums[j] and the
absolute difference between i and j is at most k.
*/

func containsNearbyDuplicate(nums []int, k int) bool {
	options := []func(nums []int, k int) bool{containsNearbyDuplicate0, containsNearbyDuplicate1, containsNearbyDuplicate2}
	return options[2](nums, k)
}

/* sliding window */
func containsNearbyDuplicate2(nums []int, k int) bool {
	m := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		if i > k {
			delete(m, nums[i-k-1])
		}
		m[nums[i]]++
		if m[nums[i]] > 1 {
			return true
		}
	}
	return false
}

/* map */
func containsNearbyDuplicate1(nums []int, k int) bool {
	m := make(map[int]int)
	for i, j := range nums {
		if val, found := m[j]; found {
			if Abs(val, i) <= k {
				return true
			}
		}
		m[j] = i
	}

	return false
}

/* brute-force */
func containsNearbyDuplicate0(nums []int, k int) bool {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i] == nums[j] && j-i <= k {
				return true
			}
		}
	}
	return false
}
