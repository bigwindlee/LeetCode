package generate022

func generateParenthesis(n int) []string {
	var res []string
	var path []byte
	status := []bool{true, false}
	backtrack(n*2, &path, status, 0, &res)
	return res
}

func backtrack(length int, path *[]byte, status []bool, depth int, res *[]string) {
	if depth == length {
		if isValid(*path) {
			*res = append(*res, string(*path))
		}
		return
	}
	for _, val := range status {
		if val {
			*path = append(*path, '(')
		} else {
			*path = append(*path, ')')
		}
		backtrack(length, path, status, depth+1, res)
		*path = (*path)[:len(*path)-1]
	}
}

func isValid(path []byte) bool {
	count := 0
	for _, v := range path {
		if v == '(' {
			count++
		} else {
			count--
		}
		if count < 0 {
			return false
		}
	}
	return count == 0
}
