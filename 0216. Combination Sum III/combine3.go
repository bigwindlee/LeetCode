package combine3

func combinationSum3(k int, n int) [][]int {
	options := []func(k int, n int) [][]int{combinationSum3_0, combinationSum3_1}
	return options[1](k, n)
}

/*------------------------------------------------------------------------------*/

func combinationSum3_1(k int, n int) [][]int {
	var res [][]int
	backtrack_1(k, n, 1, []int{}, &res)
	return res
}

func backtrack_1(k, n, start int, path []int, res *[][]int) {
	if k == 0 {
		if n == 0 {
			*res = append(*res, append([]int{}, path...)) // optimize duplicating (*path) slice
		}
		return
	}
	for i := start; i < 10; i++ {
		if n >= i {
			path = append(path, i)
			backtrack_1(k-1, n-i, i+1, path, res)
			path = path[:len(path)-1]
		}
	}
}

/*------------------------------------------------------------------------------*/

func combinationSum3_0(k int, n int) [][]int {
	var res [][]int
	var path []int
	visit := make([]bool, 10)

	backtrack_0(k, n, 0, visit, &path, &res)
	return res
}

func backtrack_0(k int, n int, depth int, visit []bool, path *[]int, res *[][]int) {
	if k == depth {
		if n == 0 {
			dup := make([]int, len(*path))
			copy(dup, *path)
			*res = append(*res, dup)
		}
		return
	}
	for i := 1; i < 10; i++ {
		if !visit[i] && n >= i && (len(*path) == 0 || i > (*path)[len(*path)-1]) {
			visit[i] = true
			*path = append(*path, i)
			backtrack_0(k, n-i, depth+1, visit, path, res)
			*path = (*path)[:len(*path)-1]
			visit[i] = false
		}
	}
}
