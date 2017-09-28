package isvalid

func isValid(s string) bool {
	stack := make([]byte, 128)
	top := 0

	for i := 0; i < len(s); i++ {
		if top >= len(stack) {
			stack = append(stack, stack...)
		}
		if s[i] == '{' {
			stack[top] = '}'
			top++
		} else if s[i] == '[' {
			stack[top] = ']'
			top++
		} else if s[i] == '(' {
			stack[top] = ')'
			top++
		} else {
			top--
			if top < 0 || stack[top] != s[i] {
				return false
			}
		}
	}
	return top == 0
}
