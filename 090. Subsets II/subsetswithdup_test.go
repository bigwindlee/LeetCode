package subset2

import (
	"fmt"
	. "leetcomm"
	"sort"
	"testing"
)

func TestSubsetsWithDup(t *testing.T) {
	res := subsetsWithDup([]int{9, 7, 5, 3, 0})
	fmt.Printf("%v\n", IntSlice2D2StringSortedWithNewLine(res))
}
