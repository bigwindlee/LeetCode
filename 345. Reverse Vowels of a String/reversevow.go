package reversevow

func reverseVowels(s string) string {
	sb := []byte(s)
	vi := make([]int, 0, 16) // array of vowels index
	for i, char := range s {
		if char == 'a' || char == 'e' || char == 'i' || char == 'o' || char == 'u' ||
			char == 'A' || char == 'E' || char == 'I' || char == 'O' || char == 'U' {
			vi = append(vi, i)
		}
	}
	for i := 0; i < len(vi)/2; i++ {
		sb[vi[i]], sb[vi[len(vi)-1-i]] = sb[vi[len(vi)-1-i]], sb[vi[i]]
	}
	return string(sb)
}
