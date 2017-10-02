package reversestr

func reverseStr(s string, k int) string {
	l := len(s)
	ba := make([]byte, 0, l)
	for i := k; i-k < l; i += k {
		if (i/k)%2 == 1 {
			for p := min(i, l) - 1; p >= i-k; p-- {
				ba = append(ba, s[p])
			}
		} else {
			ba = append(ba, s[i-k:min(i, l)]...)
		}
	}

	return string(ba)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
