package thirdmax

import (
	"testing"
)

func TestThirdMax(t *testing.T) {
	testdata := []struct {
		in       []int
		expected int
	}{
		{[]int{3, 2, 1}, 1},
		{[]int{1, 2}, 2},
		{[]int{2, 2, 3, 1}, 1},
		{[]int{1, 2, -2147483648}, -2147483648},
	}
	// fmt.Printf("%v\n", math.MinInt32)
	for i := range testdata {
		el := testdata[i]
		actual := thirdMax(el.in)
		if actual != el.expected {
			t.Errorf("Case %d\tin: %v, actual: %d, expected: %d\n", i, el.in, actual, el.expected)
		}
	}
}
