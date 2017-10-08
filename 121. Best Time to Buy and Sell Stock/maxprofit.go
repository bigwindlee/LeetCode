package maxprofit

/*
Dynamic Programming
Score: 68.29
*/
func maxProfit(prices []int) int {
	options := []func(prices []int) int{maxProfit_0, maxProfit_1}
	return options[1](prices)
}

func maxProfit_1(prices []int) int {
	if len(prices) < 2 {
		return 0
	}
	minprice := prices[0]
	maxprofit := 0
	for _, val := range prices {
		maxprofit = max(maxprofit, val-minprice)
		minprice = min(minprice, val)
	}
	return maxprofit
}

/*
brute-force
Score: 17.07
*/
func maxProfit_0(prices []int) int {
	ans := 0
	for i := 0; i < len(prices)-1; i++ {
		for j := i + 1; j < len(prices); j++ {
			if prices[j]-prices[i] > ans {
				ans = prices[j] - prices[i]
			}
		}
	}

	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
