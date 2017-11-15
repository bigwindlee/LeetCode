package findmax

import (
	"testing"
)

func TestFindMaxConsecutiveOnes(t *testing.T) {
	testdata := []struct {
		in       []int
		expected int
	}{
		{[]int{1}, 1},
		{[]int{1, 0, 1, 1, 0, 1}, 2},
	}

	for i := range testdata {
		el := testdata[i]
		actual := findMaxConsecutiveOnes(el.in)
		if actual != el.expected {
			t.Errorf("%v, actual: %d, expected: %d\n", el.in, actual, el.expected)
		}
	}
}
