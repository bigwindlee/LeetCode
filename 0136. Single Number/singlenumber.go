package single

func singleNumber(nums []int) int {
	r := nums[0]
	for i := 1; i < len(nums); i++ {
		r ^= nums[i]
	}
	return r
}
