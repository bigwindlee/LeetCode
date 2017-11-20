package combine3

import (
	. "leetcomm"
	"testing"
)

func TestCombinationSum3(t *testing.T) {
	testdata := []struct {
		k        int
		n        int
		expected [][]int
	}{
		{3, 7, [][]int{[]int{1, 2, 4}}},
		{3, 9, [][]int{[]int{1, 2, 6}, []int{1, 3, 5}, []int{2, 3, 4}}},
	}

	for i := range testdata {
		el := testdata[i]
		actual := combinationSum3(el.k, el.n)
		if IntSlice2DCompareIgnoreOrder(actual, el.expected) != 0 {
			t.Errorf("Case #%d\texpected: %v, actual: %v\n", i, el.expected, actual)
		}
	}
}
