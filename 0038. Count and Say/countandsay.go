package countsay

func countAndSay(n int) string {
	if n == 1 {
		return "1"
	}
	prev := countAndSay(n - 1)
	lenp := len(prev)
	var count byte
	curr := make([]byte, 0, 64)
	for i := 0; i < lenp; i++ {
		if i == lenp-1 {
			curr = append(curr, '1'+count)
			curr = append(curr, prev[i])
			break
		}
		if prev[i] == prev[i+1] {
			count++
		} else {
			curr = append(curr, '1'+count)
			curr = append(curr, prev[i])
			count = 0
		}
	}

	return string(curr)
}

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
