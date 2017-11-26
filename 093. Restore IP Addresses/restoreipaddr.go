package restoreip

import (
	"strconv"
	"strings"
)

func restoreIpAddresses(s string) []string {
	var res []string
	backtrack(s, 0, []string{}, &res)
	return res
}

func backtrack(sub string, depth int, path []string, res *[]string) {
	if depth == 3 {
		if isValid(sub) {
			path = append(path, sub)
			*res = append(*res, strings.Join(path, "."))
		}
		return
	}
	for i := 1; i <= 3 && i <= len(sub); i++ {
		if isValid(sub[:i]) {
			path = append(path, sub[:i])
			backtrack(sub[i:], depth+1, path, res)
			path = path[:len(path)-1]
		}
	}
}

func isValid(sub string) bool {
	if len(sub) == 0 || len(sub) > 3 {
		return false
	}
	if len(sub) > 1 && strings.HasPrefix(sub, "0") {
		return false
	}
	n, _ := strconv.Atoi(sub)
	return n <= 255
}
