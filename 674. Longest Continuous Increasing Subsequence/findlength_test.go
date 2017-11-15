package findlength

import (
	"testing"
)

func TestFindLengthOfLCIS(t *testing.T) {
	testdata := []struct {
		in       []int
		expected int
	}{
		{[]int{1, 3, 5, 4, 7}, 3},
		{[]int{2, 2, 2, 2, 2}, 1},
		{[]int{1, 3, 5, 7}, 4},
	}

	for i := range testdata {
		el := testdata[i]
		actual := findLengthOfLCIS(el.in)
		if actual != el.expected {
			t.Errorf("Case %d\tnums: %v, actual: %d, expected: %d\n", i, el.in, actual, el.expected)
		}
	}
}
