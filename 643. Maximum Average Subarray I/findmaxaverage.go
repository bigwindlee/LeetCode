package findmaxaverage

func findMaxAverage(nums []int, k int) float64 {
	options := []func(nums []int, k int) float64{findMaxAverage0, findMaxAverage1}
	return options[1](nums, k)
}

func findMaxAverage1(nums []int, k int) float64 {
	sum := 0
	for i := 0; i < k; i++ {
		sum += nums[i]
	}
	max := sum
	for i := k; i < len(nums); i++ {
		sum += nums[i] - nums[i-k] // sliding: one in one out
		if sum > max {
			max = sum
		}
	}
	return float64(max) / float64(k)
}

func findMaxAverage0(nums []int, k int) float64 {
	var res float64
	for i := 0; i <= len(nums)-k; i++ {
		sum := 0
		for j := i; j < i+k; j++ { // calculate the sum in sliding window
			sum += nums[j]
		}
		average := float64(sum) / float64(k)
		if i == 0 {
			res = average
		} else if average > res {
			res = average
		}
	}
	return res
}
