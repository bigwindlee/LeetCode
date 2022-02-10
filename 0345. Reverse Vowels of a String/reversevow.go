package reversevow

func reverseVowels(s string) string {
	options := []func(s string) string{reverseVowels_0, reverseVowels_1}
	return options[1](s)
}

/* Score: 93.10 */
/* Use 2 pointers to scan the string from START and END, swap them if both are vowels. */
func reverseVowels_1(s string) string {
	sb := []byte(s)
	l := len(sb)
	i := 0
	j := l - 1
	for {
		for i < j && !isVowel(sb[i]) {
			i++
		}
		for i < j && !isVowel(sb[j]) {
			j--
		}
		if i < j {
			sb[i], sb[j] = sb[j], sb[i]
			i++
			j--
		} else {
			return string(sb)
		}
	}
}

/* Score: 68.97 */
/* Collect the indexes of vowels into an array and reverse the vowels based on the array */
func reverseVowels_0(s string) string {
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

func isVowel(char byte) bool {
	return char == 'a' || char == 'e' || char == 'i' || char == 'o' || char == 'u' ||
		char == 'A' || char == 'E' || char == 'I' || char == 'O' || char == 'U'
}
