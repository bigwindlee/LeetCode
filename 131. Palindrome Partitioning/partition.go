package partition

func partition(s string) [][]string {
	var res [][]string
	backtrack(s, []string{}, &res)
	return res
}

func backtrack(s string, path []string, res *[][]string) {
	if len(s) == 0 {
		tmp := make([]string, len(path))
		copy(tmp, path)
		*res = append(*res, tmp)
		return
	}
	for i := 1; i <= len(s); i++ {
		if isValid(s[:i]) {
			path = append(path, s[:i])
			backtrack(s[i:], path, res)
			path = (path)[:len(path)-1]
		}
	}
}

func isValid(sub string) bool {
	L := len(sub)
	for i := 0; i < L/2; i++ {
		if sub[i] != sub[L-1-i] {
			return false
		}
	}
	return true
}
