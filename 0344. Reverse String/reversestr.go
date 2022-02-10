package reversestr

func reverseString(s string) string {
	ba := []byte(s)
	for i := 0; i < len(ba)/2; i++ {
		ba[i], ba[len(ba)-1-i] = ba[len(ba)-1-i], ba[i]
	}
	return string(ba)
}
