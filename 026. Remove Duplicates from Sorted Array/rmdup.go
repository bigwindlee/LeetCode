package rmdup

/* Ugly version */
func removeDuplicates(nums []int) int {
	var i, w int
	length := len(nums)
	first_dup := false
	j := 1
	for j < length {
		if nums[i] == nums[j] {
			if !first_dup {
				first_dup = true
				w = j
			}
			if j == length-1 {
				length = i + 1
			}
			j++
		} else {
			if first_dup {
				copy(nums[w:w+length-j], nums[j:length])
				length -= j - i - 1
				w++
				first_dup = false
			}
			i++
			j = i + 1
		}
	}
	nums = nums[:length]
	return length
}
