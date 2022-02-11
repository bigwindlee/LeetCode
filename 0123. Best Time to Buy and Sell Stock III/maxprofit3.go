package maxprofit

import (
	"math"
)

func maxProfit(prices []int) int {
	buy1, sale1, buy2, sale2 := math.MinInt32, 0, math.MinInt32, 0
	for _, val := range prices { //the more money left, the happier you will be
		buy1 = max(buy1, -val)       //left money after buy1
		sale1 = max(sale1, val+buy1) //left money after sale1
		buy2 = max(buy2, sale1-val)  //left money after buy2
		sale2 = max(sale2, val+buy2) //left money after sale2
	}
	return sale2
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
