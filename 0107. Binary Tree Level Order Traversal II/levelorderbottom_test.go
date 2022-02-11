package levelorderbottom

import (
	. "leetcomm"
	"testing"
)

func TestLevelOrderBottom(t *testing.T) {
	root := &TreeNode{3, nil, nil}
	root.Left = &TreeNode{9, nil, nil}
	root.Right = &TreeNode{20, nil, nil}
	root.Right.Left = &TreeNode{15, nil, nil}
	root.Right.Right = &TreeNode{7, nil, nil}

	expected := [][]int{[]int{15, 7}, []int{9, 20}, []int{3}}

	if !Int2DSliceEqual(levelOrderBottom(root), expected) {
		t.Errorf("expected: %v\n", expected)
	}
}
