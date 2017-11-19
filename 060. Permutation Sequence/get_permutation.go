package getpermute

func getPermutation(n int, k int) string {
	var res []byte
	count := 0
	visit := make([]bool, n+1)

	backtrack(n, k, 0, &count, visit, []byte{}, &res)
	return string(res)
}

func backtrack(n, k, depth int, count *int, visit []bool, path []byte, res *[]byte) bool {
	if depth == n {
		*count++
		if *count == k {
			*res = path
			return true
		}
		return false
	}
	for i := 1; i <= n; i++ {
		if !visit[i] {
			visit[i] = true
			path = append(path, '0'+byte(i))
			if backtrack(n, k, depth+1, count, visit, path, res) {
				return true
			}
			path = path[:len(path)-1]
			visit[i] = false
		}
	}
	return false
}
