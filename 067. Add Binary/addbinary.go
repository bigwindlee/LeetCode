package addbinary

func addBinary(a string, b string) string {
	i, j := len(a)-1, len(b)-1
	var ax, bx, carry, sum byte
	c := make([]byte, 0)
	for i >= 0 || j >= 0 {
		if i < 0 {
			ax = 0
		} else {
			ax = a[i] - '0'
		}
		if j < 0 {
			bx = 0
		} else {
			bx = b[j] - '0'
		}
		sum = ax + bx + carry
		carry = sum >> 1
		c = append(c, '0'+sum&0x1)

		i--
		j--
	}
	if carry == 1 {
		c = append(c, '1')
	}
	for i := 0; i < len(c)/2; i++ { // reverse the slice
		c[i], c[len(c)-1-i] = c[len(c)-1-i], c[i]
	}
	return string(c)
}
