package closestval

import (
	. "leetcomm"
	"math"
	"testing"
)

func TestClosestValue(t *testing.T) {
	testdata := []struct {
		in       []int
		target   float64
		expected int
	}{
		{[]int{5, 3, 6, 2, 4, math.MinInt32}, 2.9, 3},
		{[]int{5, 3, 6, 2, 4, math.MinInt32}, 6.9, 6},
		{[]int{5}, 10.0, 5},
		{[]int{5, 3, 6, 2, 4, math.MinInt32}, 3, 3},
		{[]int{5, 3, 6, 2, 4, math.MinInt32}, -10.1, 2},
	}

	for i := range testdata {
		el := testdata[i]
		actual := closestValue(NewTree(el.in), el.target)
		if actual != el.expected {
			t.Errorf("Case %d, target: %g, actual:%d, expected: %d\n", i, el.target, actual, el.expected)
		}
	}
}
