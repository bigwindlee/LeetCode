package combinesum

import (
	"sort"
	"testing"
)

func TestCombinationSum(t *testing.T) {
	testdata := []struct {
		candidates []int
		target     int
		expected   [][]int
	}{
		{[]int{2, 3, 6, 7}, 7, [][]int{[]int{2, 2, 3}, []int{7}}},
		{[]int{2, 3, 6, 7}, 7, [][]int{[]int{7}, []int{2, 2, 3}}},
	}

	for i := range testdata {
		el := testdata[i]
		actual := combinationSum(el.candidates, el.target)
		if IntSlice2DCompareIgnoreOrder(actual, el.expected) != 0 {
			t.Errorf("Case #%d\tactual: %v, expected: %v\n", i, actual, el.expected)
		}
	}
}

type IntSlice2D [][]int

func (p IntSlice2D) Len() int           { return len(p) }
func (p IntSlice2D) Less(i, j int) bool { return IntSliceCompareIgnoreOrder(p[i], p[j]) == -1 }
func (p IntSlice2D) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }

func (p IntSlice2D) Sort() { sort.Sort(p) }

func IntSlice2DCompareIgnoreOrder(a, b [][]int) int {
	if len(a) < len(b) {
		return -1
	} else if len(a) > len(b) {
		return 1
	} else {
		IntSlice2D(a).Sort()
		IntSlice2D(b).Sort()
		for i := range a {
			n := IntSliceCompareIgnoreOrder(a[i], b[i])
			if n != 0 {
				return n
			}
		}
		return 0
	}
}

func IntSliceCompareIgnoreOrder(a, b []int) int {
	if len(a) < len(b) {
		return -1
	} else if len(a) > len(b) {
		return 1
	} else {
		sort.Ints(a)
		sort.Ints(b)
		for i := 0; i < len(a); i++ {
			if a[i] < b[i] {
				return -1
			} else if a[i] > b[i] {
				return 1
			}
		}
		return 0
	}
}
