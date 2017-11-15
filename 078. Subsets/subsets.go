package subsets

func subsets(nums []int) [][]int {
	options := []func(nums []int) [][]int{subsets0, subsets1}
	return options[1](nums)
}

///////////////////////////////////////////////////////////////////////////////

func subsets1(nums []int) [][]int {
	res := make([][]int, 0)
	status := make([]bool, len(nums))
	backtrack(&res, status, 0, nums)
	return res
}

var inSubset = []bool{false, true}

func backtrack(res *[][]int, status []bool, deep int, nums []int) {
	if deep == len(nums) {
		tmp := make([]int, 0)
		for i, val := range status {
			if val {
				tmp = append(tmp, nums[i])
			}
		}
		*res = append(*res, tmp)
		return
	}

	for _, val := range inSubset {
		status[deep] = val
		backtrack(res, status, deep+1, nums)
	}
}

///////////////////////////////////////////////////////////////////////////////

/* bit manipulation */
func subsets0(nums []int) [][]int {
	res := make([][]int, 0)
	for i := 0; i < (1 << uint32(len(nums))); i++ {
		sub := make([]int, 0)
		k := 0
		for j := i; j > 0; j >>= 1 {
			if j&1 == 1 {
				sub = append(sub, nums[k])
			}
			k++
		}
		res = append(res, sub)
	}

	return res
}
