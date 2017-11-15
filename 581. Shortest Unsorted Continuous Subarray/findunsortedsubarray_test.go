package fundunsorted

import (
	"testing"
)

func TestFindUnsortedSubarray(t *testing.T) {
	testdata := []struct {
		in       []int
		expected int
	}{
		{[]int{2, 6, 4, 8, 10, 9, 15}, 5},
	}

	for i := range testdata {
		el := testdata[i]
		actual := findUnsortedSubarray(el.in)
		if actual != el.expected {
			t.Errorf("in: %v, actual: %d, expected: %d\n", el.in, actual, el.expected)
		}
	}
}
