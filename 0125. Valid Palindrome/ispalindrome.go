package ispalindrome

func isPalindrome(s string) bool {
	if len(s) < 2 {
		return true
	}
	i := 0
	j := len(s) - 1

	var front, end byte
	valid := false
	for ; i < len(s); i++ {
		if front, valid = toLower(s[i]); valid {
			break
		}
	}
	if !valid {
		return true
	}
	for ; j >= 0; j-- {
		if end, valid = toLower(s[j]); valid {
			break
		}
	}
	if i == j {
		return true
	}
	return front == end && isPalindrome(s[i+1:j])
}

func toLower(a byte) (byte, bool) {
	if a >= '0' && a <= '9' {
		return a, true
	} else if a >= 'A' && a <= 'Z' {
		return a + 'z' - 'Z', true // to lower case
	} else if a >= 'a' && a <= 'z' {
		return a, true
	} else {
		return a, false
	}
}
