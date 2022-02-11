package rmdup

import (
	"leetcomm"
	"testing"
)

func TestRemoveDuplicates(t *testing.T) {
	testdata := [][2][]int{
		{[]int{1, 1, 2, 3}, []int{1, 2, 3}},
	}

	for i := range testdata {
		ori := testdata[i][0][:]
		leng := removeDuplicates(testdata[i][0])
		got := testdata[i][0][:leng]
		if !leetcomm.IntSliceEqual(got, testdata[i][1]) {
			t.Errorf("Origin: %v, get %v, expected: %v\n", ori, got, testdata[i][1])
		}
	}
}
