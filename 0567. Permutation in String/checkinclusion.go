package checkinclusion

/* Score: 100.00 */
func checkInclusion(s1 string, s2 string) bool {
	if len(s1) > len(s2) {
		return false
	}
	for i := 0; i < len(s2)-len(s1)+1; i++ {
		if isAnagram(s2[i:i+len(s1)], s1) {
			return true
		}
	}
	return false
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
