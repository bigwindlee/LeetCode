package missing

import (
	"testing"
)

func TestMissingNumber(t *testing.T) {
	testdata := []struct {
		nums    []int
		missing int
	}{
		{[]int{0}, 1},
		{[]int{0, 1}, 2},
		{[]int{0, 1, 3}, 2},
	}

	for i := range testdata {
		actual := missingNumber(testdata[i].nums)
		if actual != testdata[i].missing {
			t.Errorf("Missing number in %v is %d, expected: %d\n",
				testdata[i].nums, actual, testdata[i].missing)
		}
	}
}
