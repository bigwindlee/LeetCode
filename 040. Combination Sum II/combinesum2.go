package combine2

import (
	. "leetcomm"
)

func combinationSum2(candidates []int, target int) [][]int {
	res := make([][]int, 0)
	comb := make([]int, 0)
	status := make([]bool, len(candidates))
	backtrack(&res, &comb, candidates, status, target)
	return res
}

func backtrack(res *[][]int, comb *[]int, candidates []int, status []bool, target int) {
	if target < 0 {
		return
	}
	if target == 0 {
		dup := DupSlice(*comb)
		if !IntSlice2DContainsIgnoreOrder(*res, dup) {
			*res = append(*res, DupSlice(*comb))
		}
		return
	}
	for i, v := range candidates {
		if !status[i] {
			status[i] = true
			*comb = append(*comb, v)
			backtrack(res, comb, candidates, status, target-v)
			*comb = (*comb)[:len(*comb)-1]
			status[i] = false
		}
	}
}
