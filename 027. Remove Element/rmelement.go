package rmelement

func removeElement(nums []int, val int) int {
	count := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == val {
			count++
		} else {
			nums[i-count] = nums[i]
		}
	}
	return len(nums) - count
}
