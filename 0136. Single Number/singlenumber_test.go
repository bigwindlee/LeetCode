package single

import (
	"testing"
)

func TestSingleNumber(t *testing.T) {
	testdata := []struct {
		nums     []int
		expected int
	}{
		{[]int{1, 2, 2, 3, 5, 3, 1}, 5},
		{[]int{9, 1, 1, 2, 3, 2, 3}, 9},
		{[]int{1, 1, 2, 2, 3, 3, 8}, 8},
	}

	for i := range testdata {
		actual := singleNumber(testdata[i].nums)
		if actual != testdata[i].expected {
			t.Errorf("Single number in %v is %d, expected: %d\n",
				testdata[i].nums, actual, testdata[i].expected)
		}
	}
}
