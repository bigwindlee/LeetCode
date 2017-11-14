package combinesum

func combinationSum(candidates []int, target int) [][]int {
	options := []func(candidates []int, target int) [][]int{combinationSum_0, combinationSum_1}
	return options[1](candidates, target)
}

/*----------------------------------------------------------------------------*/
func combinationSum_1(candidates []int, target int) [][]int {
	res := make([][]int, 0)
	comb := make([]int, 0)
	backtrack1(&res, &comb, candidates, target)
	return res
}

func backtrack1(res *[][]int, comb *[]int, candidates []int, target int) {
	if target < 0 {
		return
	}
	if target == 0 {
		newcomb := make([]int, len(*comb))
		copy(newcomb, *comb)
		*res = append(*res, newcomb)
		return
	}
	for _, v := range candidates {
		if len(*comb) == 0 || v >= (*comb)[len(*comb)-1] {
			*comb = append(*comb, v)
			backtrack1(res, comb, candidates, target-v)
			*comb = (*comb)[:len(*comb)-1]
		}
	}
}

/*----------------------------------------------------------------------------*/
func combinationSum_0(candidates []int, target int) [][]int {
	res := make([][]int, 0)
	comb := make([]int, 0)
	backtrack0(&res, &comb, candidates, target)
	return res
}

func backtrack0(res *[][]int, comb *[]int, candidates []int, target int) {
	sum := 0
	for _, v := range *comb {
		sum += v
	}
	if sum > target {
		return
	}
	if sum == target {
		newcomb := make([]int, len(*comb))
		copy(newcomb, *comb)
		*res = append(*res, newcomb)
		return
	}
	for _, v := range candidates {
		if len(*comb) == 0 || v >= (*comb)[len(*comb)-1] {
			*comb = append(*comb, v)
			backtrack0(res, comb, candidates, target)
			*comb = (*comb)[:len(*comb)-1]
		}
	}
}
