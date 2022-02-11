package isbalanced

import (
	. "leetcomm"
)

func isBalanced(root *TreeNode) bool {
	_, ret := isBalancedHelp(root)
	return ret
}

func isBalancedHelp(root *TreeNode) (int, bool) {
	if root == nil {
		return 0, true
	}
	// l, r : left/right child balanced?
	// lh, rh : height of left/right child
	lh, l := isBalancedHelp(root.Left)
	rh, r := isBalancedHelp(root.Right)
	height := 1 + Max(lh, rh)
	if Abs(lh, rh) >= 2 {
		return height, false
	}
	return height, l && r
}
