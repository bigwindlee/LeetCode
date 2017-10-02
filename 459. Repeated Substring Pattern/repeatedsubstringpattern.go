package repeatedsubstringpattern

/* Score: 65.22 */
func repeatedSubstringPattern(s string) bool {
	l := len(s)
	for i := 1; i <= l/2; i++ { // length of substring
		if l%i == 0 {
			j := 1
			subs := l / i // number of substrings
			for ; j < subs; j++ {
				k := 0
				for k < i && s[k] == s[k+j*i] {
					k++
				}
				if k != i {
					break
				}
			}
			if j == subs {
				return true
			}
		}
	}
	return false
}
