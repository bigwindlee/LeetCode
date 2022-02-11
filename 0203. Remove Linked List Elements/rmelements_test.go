package rmelements

import (
	. "leetintlist"
	"testing"
)

func TestRemoveElements(t *testing.T) {
	testdata := []struct {
		in       []int
		val      int // remove the value
		expected []int
	}{
		{[]int{1, 2, 6, 3, 4, 5, 6}, 6, []int{1, 2, 3, 4, 5}},
		{[]int{6, 2, 6, 3, 4, 5, 6}, 6, []int{2, 3, 4, 5}},
	}

	for i := range testdata {
		actual := removeElements(GetList(testdata[i].in), testdata[i].val)
		if !EqualList(actual, GetList(testdata[i].expected)) {
			t.Errorf("Removing %d in %v get: %v expected: %v\n",
				testdata[i].val,
				testdata[i].in,
				actual,
				testdata[i].expected)
		}
	}
}
