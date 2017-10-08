package maxsub

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
func maxSubArray(nums []int) int {
	options := []func(nums []int) int{maxSubArray_0, maxSubArray_1}
	return options[1](nums)
}

func maxSubArray_1(nums []int) int {
	ans := nums[0]
	sum := 0

	for i := 0; i < len(nums); i++ {
		sum += nums[i]
		ans = max(sum, ans)
		sum = max(sum, 0)
	}
	return ans
}

/*
200 / 202 test cases passed.
Status: Time Limit Exceeded
*/
func maxSubArray_0(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	maxsub := nums[0]
	l := len(nums)
	for ws := 1; ws <= l; ws++ { // window size
		for i := 0; i < l-ws+1; i++ { // range of index
			sum := 0
			for j := i; j < i+ws; j++ { // sum in the window
				sum += nums[j]
			}
			if sum > maxsub {
				maxsub = sum
			}
		}
	}
	return maxsub
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
