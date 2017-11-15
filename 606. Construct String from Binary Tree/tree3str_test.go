package tree2s

import (
	. "leetcomm"
	"math"
	"testing"
)

func TestTree2str(t *testing.T) {
	testdata := []struct {
		in       []int
		expected string
	}{
		{[]int{1, 2, 3, 4}, "1(2(4))(3)"},
		{[]int{1, 2, 3, math.MinInt32, 4}, "1(2()(4))(3)"},
	}

	for i := range testdata {
		el := testdata[i]
		actual := tree2str(NewTree(el.in))
		if actual != el.expected {
			t.Errorf("Case %d\tactual: %q, expected: %q\n", i, actual, el.expected)
		}
	}
}
