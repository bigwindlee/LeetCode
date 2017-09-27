package rmdup

import (
	_ "fmt"
	"testing"
)

func TestRemoveDuplicates(t *testing.T) {
	testdata := [][2][]int{
		{[]int{1, 1}, []int{1, 2, 3}},
	}
	_ = testdata

	removeDuplicates(testdata[0][0])
}
