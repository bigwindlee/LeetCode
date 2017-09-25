package ishappy

func isHappy(n int) bool {
	slow := n
	fast := n
	for {
		slow = digitSqualSum(slow)
		if slow == 1 {
			return true
		}
		fast = digitSqualSum(digitSqualSum(fast))
		if fast == 1 {
			return true
		}
		if slow == fast { // repeat before convergence to 1
			return false
		}
	}
}

func digitSqualSum(n int) int {
	sum := 0
	for n > 0 {
		sum += (n % 10) * (n % 10)
		n /= 10
	}
	return sum
}
