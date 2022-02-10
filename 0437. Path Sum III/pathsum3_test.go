package pathsum3

import (
	. "leetcomm"
	"math"
	"testing"
)

func TestPathSum(t *testing.T) {
	testdata := []struct {
		t        *TreeNode
		sum      int
		expected int
	}{
		{NewTree([]int{10, 5, -3, 3, 2, math.MinInt32, 11, 3, -2, math.MinInt32, 1}), 8, 3},
	}

	for i := range testdata {
		el := testdata[i]
		actual := pathSum(el.t, el.sum)
		expected := el.expected
		if actual != expected {
			t.Errorf("actual: %d, expected: %d\n", actual, expected)
		}
	}
}
