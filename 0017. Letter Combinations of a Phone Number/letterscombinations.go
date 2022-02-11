package letterscombine

func letterCombinations(digits string) []string {
	res := make([]string, 0)
	comb := make([]byte, 0)
	backtrack(&res, &comb, digits, 0)
	return res
}

var keys = []string{" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}

func backtrack(res *[]string, comb *[]byte, digits string, depth int) {
	if len(digits) == 0 {
		return
	}
	if depth == len(digits) {
		*res = append(*res, string(*comb))
		return
	}
	str := keys[digits[depth]-'0']
	for i := 0; i < len(str); i++ {
		*comb = append(*comb, str[i])
		backtrack(res, comb, digits, depth+1)
		*comb = (*comb)[:len(*comb)-1] // backtracking
	}
}
