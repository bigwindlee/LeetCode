package merge

import (
	. "leetcomm"
	"testing"
)

func TestMerge(t *testing.T) {
	testdata := []struct {
		nums1    []int
		m        int
		nums2    []int
		n        int
		expected []int
	}{
		{[]int{1, 3, 5, 0, 0}, 3, []int{2, 4}, 2, []int{1, 2, 3, 4, 5}},
	}

	for i := range testdata {
		el := testdata[i]
		merge(el.nums1, el.m, el.nums2, el.n)
		actual := el.nums1[:el.m+el.n]
		if !IntSliceEqual(actual, el.expected) {
			t.Errorf("actual: %v, expected: %v\n", actual, el.expected)
		}
	}
}
