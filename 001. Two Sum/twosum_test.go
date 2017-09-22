package twosum

import (
	"reflect"
	"testing"
)

func TestTwoSum(t *testing.T) {
	testarr := []int{1, 2, 3, 4, 5, 6}
	result := map[int][]int{
		3: []int{0, 1},
		4: []int{0, 2},
		7: []int{0, 5},
	}

	for item := range result {
		if !reflect.DeepEqual(twoSum(testarr, item), result[item]) {
			t.Errorf("%v != %v\n", twoSum(testarr, item), result[item])
		}
	}
}
