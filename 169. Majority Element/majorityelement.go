package majorityelement

/* 169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

func majorityElement(nums []int) int {
	options := []func(nums []int) int{majorityElement0, majorityElement1}
	return options[1](nums)
}

/*
Boyer-Moore Majority Vote Algorithm
http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
*/
func majorityElement1(nums []int) int {
	candidate := nums[0]
	count := 1
	for i := 1; i < len(nums); i++ {
		if count == 0 {
			candidate = nums[i] // change candidate
			count = 1           // count again
		} else if candidate == nums[i] {
			count++
		} else {
			count--
		}
	}
	return candidate
}

func majorityElement0(nums []int) int {
	f := map[int]int{}
	for i := 0; i < len(nums); i++ {
		f[nums[i]]++
		if f[nums[i]] > len(nums)/2 {
			return nums[i]
		}
	}
	panic("unreachable") // assume the majority element always exist in the array.
}
