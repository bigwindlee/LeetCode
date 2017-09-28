package isvalid

func isValid(s string) bool {
	stack := make([]byte, 128, 128)
	top := 0

	for i := 0; i < len(s); i++ {
		if s[i] == '{' || s[i] == '[' || s[i] == '(' {
			if top >= len(stack) {
				stack = append(stack, stack...)
			}
			stack[top] = s[i]
			top++
		} else {
			top--
			if top < 0 || !isMatch(stack[top], s[i]) {
				return false
			}
		}
	}
	return top == 0
}

func isMatch(a, b byte) bool {
	if (a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')') {
		return true
	}
	return false
}
