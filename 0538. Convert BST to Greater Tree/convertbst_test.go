package togreater

import (
	. "leetcomm"
	"testing"
)

func TestConvertBST(t *testing.T) {
	testdata := []struct {
		in  []int
		out []int
	}{
		{[]int{5, 2, 13}, []int{18, 20, 13}},
	}

	for i := range testdata {
		el := testdata[i]
		actual := convertBST(NewTree(el.in))
		expected := NewTree(el.out)

		if !IsSameTree(actual, expected) {
			t.Errorf("Case %d\n", i)
		}
	}
}
