package merge

import (
	. "leetcomm"
	"testing"
)

func TestMerge(t *testing.T) {
	nums1 := make([]int, 3, 5)
	nums1[0], nums1[1], nums1[2] = 1, 3, 5
	nums2 := make([]int, 2)
	nums2[0], nums2[1] = 2, 4

	merge(nums1, len(nums1), nums2, len(nums2))
	expected := []int{1, 2, 3, 4, 5}
	if !IntSliceEqual(nums1[:5], expected) {
		t.Errorf("actual: %v, expected: %v\n", nums1, expected)
	}
}
