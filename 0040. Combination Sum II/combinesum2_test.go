package combine2

import (
	. "leetcomm"
	"testing"
)

func TestCombinationSum2(t *testing.T) {
	testdata := []struct {
		candidates []int
		target     int
		expected   [][]int
	}{
		{[]int{10, 1, 2, 7, 6, 1, 5}, 8, [][]int{[]int{1, 7}, []int{1, 2, 5}, []int{2, 6}, []int{1, 1, 6}}},
	}

	for i := range testdata {
		el := testdata[i]
		actual := combinationSum2(el.candidates, el.target)
		if IntSlice2DCompareIgnoreOrder(actual, el.expected) != 0 {
			t.Errorf("Case #%d\tactual: %v, expected: %v\n", i, actual, el.expected)
		}
	}
}
