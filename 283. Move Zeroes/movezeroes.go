package movezeroes

func moveZeroes(nums []int) {
	count := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			count++
		} else {
			nums[i-count] = nums[i]
		}
	}
	for j := len(nums) - count; j < len(nums); j++ {
		nums[j] = 0
	}
}
