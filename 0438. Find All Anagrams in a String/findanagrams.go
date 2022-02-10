package findanagrams

func findAnagrams(s string, p string) []int {
	if len(s) < len(p) {
		return nil
	}
	l := len(s) - len(p) + 1
	r := make([]int, 0, l)
	for i := 0; i < l; i++ {
		if isAnagram(s[i:i+len(p)], p) {
			r = append(r, i)
		}
	}
	return r
}

func isAnagram(s string, t string) bool {
	var xor, squaresum1, squaresum2 rune
	for _, char := range s {
		xor ^= char
		squaresum1 += char * char
	}
	for _, char := range t {
		xor ^= char
		squaresum2 += char * char
	}
	return xor == 0 && squaresum1 == squaresum2
}
