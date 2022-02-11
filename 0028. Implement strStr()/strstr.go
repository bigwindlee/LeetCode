package strstr

/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
func strStr(haystack string, needle string) int {
	options := []func(haystack string, needle string) int{strStr_0, strStr_1}
	return options[1](haystack, needle)
}

/* Score: xx */
func strStr_1(haystack string, needle string) int {
	lh := len(haystack)
	ln := len(needle)
	if lh < ln {
		return -1
	}
	for i := 0; i <= lh-ln; i++ {
		pi := i
		j := 0
		for j < ln && needle[j] == haystack[pi] {
			j++
			pi++
		}
		if j == ln {
			return i
		}
	}
	return -1
}

/* Score: 62.30 */
func strStr_0(haystack string, needle string) int {
	lh := len(haystack)
	ln := len(needle)
	for i := 0; i <= lh-ln; i++ {
		pi := i
		j := 0
		for j < ln {
			if needle[j] != haystack[pi] {
				break
			}
			j++
			pi++
		}
		if j == ln {
			return i
		}
	}
	return -1
}
