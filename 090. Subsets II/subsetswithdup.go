package subset2

import (
	"sort"
)

func subsetsWithDup(nums []int) [][]int {
	var res [][]int
	backtrack(nums, 0, []int{}, &res)
	return res
}

func backtrack(nums []int, depth int, path []int, res *[][]int) {
	if depth == len(nums) {
		if !IntSlice2dContains(*res, path) {
			*res = append(*res, append([]int{}, path...))
		}
		return
	}
	for i := 0; i < 2; i++ {
		if i == 1 {
			path = append(path, nums[depth])
		}
		backtrack(nums, depth+1, path, res)
		if i == 1 {
			path = path[:len(path)-1]
		}
	}
}

func IntSlice2dContains(s2d [][]int, sd []int) bool {
	for i := range s2d {
		if len(s2d[i]) == len(sd) {
			dup_s2d := append([]int{}, s2d[i]...)
			dup_sd := append([]int{}, sd...)
			sort.Ints(dup_s2d)
			sort.Ints(dup_sd)
			equal := true
			for j := range dup_sd {
				if dup_s2d[j] != dup_sd[j] {
					equal = false
					break
				}
			}
			if equal == true {
				return true
			}
		}
	}
	return false
}
