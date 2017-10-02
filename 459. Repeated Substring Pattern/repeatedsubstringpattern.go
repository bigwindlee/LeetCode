package repeatedsubstringpattern

func repeatedSubstringPattern(s string) bool {
	l := len(s)
	var i int // length of substring
	for i = 1; i <= l/2; i++ {
		if l%i == 0 {
			j := 1
			for ; j < l/i; j++ { // number of substrings
				k := 0
				for k < i && s[k] == s[k+j*i] {
					k++
				}
				if k != i {
					break
				}
			}
			if j == l/i {
				return true
			}
		}
	}
	return false
}
