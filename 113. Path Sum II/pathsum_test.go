package pathsum

import (
	"fmt"
	. "leetcomm"
	"math"
	"testing"
)

func TestPathSum(t *testing.T) {
	root := NewTree([]int{5, 4, 8, 11, math.MinInt32, 13, 4, 7, 2, math.MinInt32, math.MinInt32, 5, 1})

	fmt.Printf("%v\n", pathSum(root, 22))
}
