package reversewords

func reverseWords(s string) string {
	l := len(s)
	ba := make([]byte, 0, l)
	i := 0
	for i < l {
		j := i + 1
		for j < l && s[j] != ' ' { // advance j to the space
			j++
		}
		for k := j - 1; k >= i; k-- { // reverse the word
			ba = append(ba, s[k])
		}
		if j == l { // to the end
			return string(ba)
		} else {
			ba = append(ba, ' ')
			i = j + 1
		}
	}
	return ""
}
