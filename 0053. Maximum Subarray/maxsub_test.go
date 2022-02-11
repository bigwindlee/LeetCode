package maxsub

import (
	"testing"
)

func TestMaxSubArray(t *testing.T) {
	testdata := []struct {
		in     []int
		expect int
	}{
		{[]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
		{[]int{-9}, -9},
	}

	for i := range testdata {
		el := testdata[i]
		actual := maxSubArray(el.in)
		expect := el.expect

		if actual != expect {
			t.Errorf("in: %v, out: %d, expected: %d\n", el.in, actual, expect)
		}
	}
}
