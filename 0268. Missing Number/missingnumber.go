package missing

/*
[0, ..., n] missing one number, length=n, index is 0 ~ n-1.
To convert the problem to "finding the single number", XOR all the numbers in
array and all the numbers in 0 ~ n.
*/
func missingNumber(nums []int) int {
	xor := 0
	i := 0
	for ; i < len(nums); i++ {
		// XOR all the numbers in array and all the numbers in 0 ~ (n-1).
		xor ^= i ^ nums[i]
	}
	return xor ^ i // Continue to XOR n.
}

/* Score: 41.51 */
/* Use extra space of a slice.
func missingNumber(nums []int) int {
    l := len(nums)
    arr := make([]int, l+1, l+1)
    for i := range nums {
        arr[nums[i]] = 1
    }
    for j := range arr {
        if arr[j] == 0 {
            return j
        }
    }
    panic("unreachable")
}
*/
