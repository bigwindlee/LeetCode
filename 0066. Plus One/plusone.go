package plus1

func plusOne(digits []int) []int {
	l := len(digits)
	res := make([]int, len(digits)+1)
	carry := 0
	res[l] = (digits[l-1] + 1) % 10
	carry = (digits[l-1] + 1) / 10
	for i := l - 2; i >= 0; i-- {
		res[i+1] = (digits[i] + carry) % 10
		carry = (digits[i] + carry) / 10
	}
	if carry == 1 {
		res[0] = 1
		return res
	}
	return res[1:]
}
