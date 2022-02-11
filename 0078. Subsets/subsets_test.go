package subsets

import (
	"fmt"
	"testing"
)

func TestSubsets(t *testing.T) {
	testdata := []struct {
		in []int
	}{
		{[]int{1, 2, 3}},
	}

	for i := range testdata {
		fmt.Printf("%v\n", subsets(testdata[i].in))
	}
}
