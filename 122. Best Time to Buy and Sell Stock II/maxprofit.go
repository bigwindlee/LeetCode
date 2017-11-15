package maxprofit

func maxProfit(prices []int) int {
	maxprofit := 0
	for i := 1; i < len(prices); i++ {
		maxprofit += max(prices[i]-prices[i-1], 0)
	}
	return maxprofit
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
