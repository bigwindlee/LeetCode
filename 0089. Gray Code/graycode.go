package graycode

func grayCode(n int) []int {
	res := []int{0}
	backtrack(n, 0, &res)
	return res
}

func backtrack(n, start int, path *[]int) {
	for i := 0; i < n; i++ {
		next := start ^ (1 << uint(i))
		if isValid(next, *path) {
			*path = append(*path, next)
			backtrack(n, next, path)
		}
	}
}

func isValid(num int, path []int) bool {
	for _, v := range path {
		if v == num {
			return false // already contains
		}
	}
	return true
}
