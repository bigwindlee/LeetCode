package findmode

import (
	. "leetcomm"
	"math"
	"testing"
)

func TestFindMode(t *testing.T) {
	testdata := []struct {
		tree     []int
		expected []int
	}{
		{[]int{1, math.MinInt32, 2, 2}, []int{2}},
		{[]int{3, 2, 4, 1, 3, 4, 5}, []int{3, 4}},
	}

	for i := range testdata {
		el := testdata[i]
		actual := findMode(NewTree(el.tree))
		if !IntSliceEqualIgnoreOrder(actual, el.expected) {
			t.Errorf("Case %d\tactual: %v, expected: %v\n", i, actual, el.expected)
		}
	}
}
