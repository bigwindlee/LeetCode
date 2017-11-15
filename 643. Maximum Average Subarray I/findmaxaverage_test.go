package findmaxaverage

import (
	"testing"
)

func TestFindMaxAverage(t *testing.T) {
	testdata := []struct {
		in       []int
		k        int
		expected float64
	}{
		{[]int{1, 12, -5, -6, 50, 3}, 4, 12.75000},
	}

	for i := range testdata {
		el := testdata[i]
		actual := findMaxAverage(el.in, el.k)
		if actual != el.expected {
			t.Errorf("Case %d\tnums: %v, k: %d, actual: %g, expected: %g\n", i, el.in, el.k, actual, el.expected)
		}
	}
}
