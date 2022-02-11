package permute2

import (
	"fmt"
	"testing"
)

func TestPermuteUnique(t *testing.T) {
	testdata := []int{1, 1, 2}
	fmt.Printf("%v\n", permuteUnique(testdata))
}
