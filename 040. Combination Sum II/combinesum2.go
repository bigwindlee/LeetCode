package combine2

import (
	"sort"
)

func combinationDfs2(candidates []int, idx int, target int, buf *[]int, out *[][]int) {
	if target < 0 {
		return
	}
	if target == 0 {
		found := make([]int, len(*buf))
		copy(found, *buf)
		*out = append(*out, found)
		return
	}
	for j := idx; j < len(candidates); j++ {
		if j == idx || candidates[j] != candidates[j-1] {
			d := candidates[j]
			*buf = append(*buf, d) /* push d */
			combinationDfs2(candidates, j+1, target-d, buf, out)
			*buf = (*buf)[:len(*buf)-1] /* pod */
		}
	}
}

func combinationSum2(candidates []int, target int) [][]int {
	var buf []int
	var out [][]int

	sort.Ints(candidates)
	combinationDfs2(candidates, 0, target, &buf, &out)

	return out
}
