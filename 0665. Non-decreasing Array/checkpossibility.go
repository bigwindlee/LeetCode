package checkpossibility

/* 665. Non-decreasing Array

Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first
4
 to
1
 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].
*/

func checkPossibility(nums []int) bool {
	count := 0
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] > nums[i+1] {
			if count == 1 {
				return false
			}
			count++
			if (i > 0 && nums[i-1] > nums[i+1]) && (i < len(nums)-2 && nums[i] > nums[i+2]) {
				// Jump nums[i] or nums[i+1], neither is ok, so...
				return false
			}
		}
	}
	return true
}
