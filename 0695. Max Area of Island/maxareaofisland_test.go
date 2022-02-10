package maxarea

import (
	"testing"
)

func TestMaxAreaOfIsland(t *testing.T) {
	testdata := []struct {
		island [][]int
		area   int
	}{
		{[][]int{
			[]int{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
			[]int{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
			[]int{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
			[]int{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
			[]int{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
			[]int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
			[]int{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
			[]int{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
		}, 6},
		{[][]int{[]int{0, 0, 0, 0, 0, 0, 0, 0}}, 0},
	}

	for i := range testdata {
		el := testdata[i]
		actual := maxAreaOfIsland(el.island)
		if actual != el.area {
			t.Errorf("Case #%d:\tactual: %d, expected: %d\n", i, actual, el.area)
		}
	}
}
