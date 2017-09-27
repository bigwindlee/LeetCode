package minwindow

/* Not a valid solution. Time Limit Exceeded !!! */
func minWindow(s string, t string) string {
	if len(s) < len(t) {
		return ""
	}
	var saved string
	for wz := len(s); wz >= len(t); wz-- {
		var i int
		for i = 0; i < len(s)-wz+1; i++ {
			if isSubset(s[i:i+wz], t) {
				saved = s[i : i+wz]
				break
			}
		}
		if i == len(s)-wz+1 {
			return saved
		}
	}
	return saved
}

func isSubset(super string, sub string) bool {
	flags := make([]int, 128, 128)
	for _, char := range super {
		flags[char]++
	}
	for _, char := range sub {
		flags[char]--
		if flags[char] < 0 {
			return false
		}
	}
	return true
}
