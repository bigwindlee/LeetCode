package lowestcommonancestor

import (
	. "leetcomm"
	"math"
	"testing"
)

func TestLowertCommonAncestor(t *testing.T) {
	testdata := []struct {
		in  []int
		p   int
		q   int
		lca int // lowest common ancestor
	}{
		/* Case 0 */ {[]int{6, 2, 8, 0, 4, 7, 9, math.MinInt32, math.MinInt32, 3, 5}, 3, 5, 4},
	}

	for i := range testdata {
		el := testdata[i]
		actual := lowestCommonAncestor(NewTree(el.in), el.p, el.q)
		if actual != el.lca {
			t.Errorf("Case%d\tp: %d, q: %d, actual: %d, expected: %d\n", i, el.p, el.q, actual, el.lca)
		}
	}
}
