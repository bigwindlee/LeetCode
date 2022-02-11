package robber

import (
	"testing"
)

func TestRob(t *testing.T) {
	testdata := []struct {
		arr []int
		sum int
	}{
		{[]int{1, 2, 3}, 4},
		{[]int{1}, 1},
		{[]int{1, 9}, 9},
		{[]int{1, 9, 8, 2, 3, 5}, 16},
	}

	for i := range testdata {
		actual := rob(testdata[i].arr)
		expected := testdata[i].sum
		if actual != expected {
			t.Errorf("rob(%v) get: %d expected: %d\n", testdata[i].arr, actual, expected)
		}
	}
}
