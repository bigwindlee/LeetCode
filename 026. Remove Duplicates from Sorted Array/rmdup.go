package rmdup

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

func removeDuplicates(nums []int) int { // Score: 83.33  :)
	duplicates := 0
	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1] {
			duplicates++
		} else {
			nums[i-duplicates] = nums[i]
		}
	}
	return len(nums) - duplicates
}

/* Ugly version */
/*
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
*/
