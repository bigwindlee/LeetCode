package combine

func combine(n int, k int) [][]int {
	var res [][]int
	backtrack(n, k, []int{}, &res)
	return res
}

func backtrack(n, k int, path []int, res *[][]int) {
	if k == 0 {
		*res = append(*res, append([]int{}, path...))
		return
	}
	for i := 1; i <= n; i++ {
		if len(path) == 0 || i > path[len(path)-1] {
			path = append(path, i)
			backtrack(n, k-1, path, res)
			path = path[:len(path)-1]
		}
	}
}
