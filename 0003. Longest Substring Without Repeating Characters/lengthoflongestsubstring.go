package lengthoflongestsubstring

/*
The reason is that if s[j] have a duplicate in the range [i, j) with index j',
we don't need to increase i little by little. We can skip all the elements
in the range [i, j'] and let i to be j' + 1 directly.
*/
func lengthOfLongestSubstring(s string) int {
	index := make([]int, 256, 256)
	var ans, i int
	for j := 0; j < len(s); j++ {
		if i < index[s[j]] {
			i = index[s[j]] // skip all the elements in the range [i, j']
		}
		//fmt.Printf("j=%d, index[%q]=%d, i=%d, %q", j, s[j], index[s[j]], i, s[i:j+1])
		if len(s)-i <= ans {
			return ans
		}
		if ans < j-i+1 {
			ans = j - i + 1
		}
		index[s[j]] = j + 1 // remember the index next to the current character
		//fmt.Printf(" index[%q]=%d\n", s[j], index[s[j]])
	}

	return ans
}
