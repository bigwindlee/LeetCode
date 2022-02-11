package binarytreepaths

import (
	"fmt"
	. "leetcomm"
	"math"
	"testing"
)

func TestBinaryTreePaths(t *testing.T) {
	mytree := NewTree([]int{1, 2, 3, math.MinInt32, 5})

	fmt.Printf("%v\n", binaryTreePaths(mytree))
}
