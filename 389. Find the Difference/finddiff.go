package finddiff

/* Score: 69.57 */
func findTheDifference(s string, t string) byte {
	var xor rune
	for _, char := range s {
		xor ^= char
	}
	for _, char := range t {
		xor ^= char
	}
	return byte(xor)
}
