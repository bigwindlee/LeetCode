package find2sum

import (
	. "leetcomm"
	"math"
	"testing"
)

func TestFindTarget(t *testing.T) {
	testdata := []struct {
		in       []int
		k        int
		expected bool
	}{
		{[]int{5, 3, 6, 2, 4, math.MinInt32, 7}, 13, true},
		{[]int{5, 3, 6, 2, 4, math.MinInt32, 7}, 14, false},
	}

	for i := range testdata {
		el := testdata[i]
		actual := findTarget(NewTree(el.in), el.k)

		if actual != el.expected {
			t.Errorf("Case %d\n", i)
		}
	}
}
