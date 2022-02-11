package maxprofit

import (
	"testing"
)

func TestMaxProfit(t *testing.T) {
	testdata := []struct {
		in     []int
		expect int
	}{
		{[]int{7, 1, 5, 3, 6, 4}, 7},
	}

	for i := range testdata {
		el := testdata[i]
		actual := maxProfit(el.in)
		expect := el.expect

		if actual != expect {
			t.Errorf("in: %v, actual: %d, expect: %d\n", el.in, actual, expect)
		}
	}
}
