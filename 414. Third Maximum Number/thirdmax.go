package thirdmax

/* 414. Third Maximum Number

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

func thirdMax(nums []int) int {
	options := []func(nums []int) int{thirdMax0, thirdMax1}
	return options[1](nums)
}

func thirdMax1(nums []int) int {
	var max1, max2, max3 *int
	for i := 0; i < len(nums); i++ {
		if equal(nums[i], max1) || equal(nums[i], max2) || equal(nums[i], max3) {
			continue
		}
		if max1 == nil || nums[i] > *max1 {
			max3 = max2
			max2 = max1
			max1 = &nums[i]
		} else if max2 == nil || nums[i] > *max2 {
			max3 = max2
			max2 = &nums[i]
		} else if max3 == nil || nums[i] > *max3 {
			max3 = &nums[i]
		}
	}

	if max3 != nil {
		return *max3
	}
	return *max1
}

func equal(a int, b *int) bool {
	return b != nil && *b == a
}

func thirdMax0(nums []int) int {
	max1, max2, max3 := nums[0], nums[0], nums[0] // non-empty array
	for i := 1; i < len(nums); i++ {
		val := nums[i]
		if val > max1 {
			max3 = max2
			max2 = max1
			max1 = val
		} else if val != max1 && (max2 == max1 || val > max2) {
			max3 = max2
			max2 = val
		} else if val != max1 && val != max2 && (max3 == max1 || max3 == max2 || val > max3) {
			max3 = val
		}
	}
	if max1 > max2 && max2 > max3 {
		return max3
	}
	return max1
}
