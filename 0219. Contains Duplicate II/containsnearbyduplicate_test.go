package containsnearby

import (
	"testing"
)

func TestContainsNearbyDuplicate(t *testing.T) {
	testdata := []struct {
		in       []int
		k        int
		expected bool
	}{
		{[]int{1, 3, 7, 1, 4, 6, 5}, 3, true},
		{[]int{1, 3, 7, 1, 4, 6, 5}, 2, false},
		{[]int{1, 3, 7, 2, 4, 6, 5}, 3, false},
		{[]int{-1, -1}, 1, true},
	}

	for i := range testdata {
		el := testdata[i]
		actual := containsNearbyDuplicate(el.in, el.k)
		if actual != el.expected {
			t.Errorf("nums: %v, k: %d, actual: %v, expected: %v\n", el.in, el.k, actual, el.expected)
		}
	}
}
