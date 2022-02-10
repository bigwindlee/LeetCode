package longestup

import (
	. "leetcomm"
	"math"
	"testing"
)

func TestLongestUnivaluePath(t *testing.T) {
	testdata := []struct {
		tree     *TreeNode
		expected int
	}{
		{NewTree([]int{5, 4, 5, 1, 1, math.MinInt32, 5}), 2},
	}

	for i := range testdata {
		el := testdata[i]
		actual := longestUnivaluePath(el.tree)
		expected := el.expected
		if actual != expected {
			t.Errorf("actual: %d, expected: %d\n", actual, expected)
		}
	}
}
