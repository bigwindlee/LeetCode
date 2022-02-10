package checkpossibility

import (
	"testing"
)

func TestCheckPossibility(t *testing.T) {
	testdata := []struct {
		in       []int
		expected bool
	}{
		{[]int{4, 2, 3}, true},
		{[]int{4, 2, 1}, false},
		{[]int{1, 2, 3, 100, 5, 6, 7}, true},
		{[]int{1, 2, 3, 0, 5, 6, 7}, true},
		{[]int{1, 2, 3, 0, 1, 6, 7}, false},
		{[]int{1, 2, 5, 100, 4, 6, 7}, false},
	}

	for i := range testdata {
		el := testdata[i]
		actual := checkPossibility(el.in)
		if actual != el.expected {
			t.Errorf("Case %v -- nums: %v, actual: %v, expected: %v\n", i, el.in, actual, el.expected)
		}
	}
}
