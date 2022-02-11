package reverse

import (
	. "leetcomm"
	"testing"
)

func TestReverseList(t *testing.T) {
	testdata := []struct {
		in  []int
		out []int
	}{
		{[]int{1, 2, 3}, []int{3, 2, 1}},
		{[]int{1}, []int{1}},
	}

	for i := range testdata {
		el := testdata[i]
		actual := reverseList(GetList(el.in))
		if !EqualList(actual, GetList(el.out)) {
			t.Errorf("Case #%d\tactual: %v, expected: %v\n", i, actual, el.out)
		}
	}
}
