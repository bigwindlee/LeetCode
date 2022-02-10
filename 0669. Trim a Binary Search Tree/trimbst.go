package trimbst

import (
	. "leetcomm"
)

func trimBST(root *TreeNode, L int, R int) *TreeNode {
	if root == nil {
		return nil
	}
	l := trimBST(root.Left, L, R)
	r := trimBST(root.Right, L, R)
	if root.Val < L {
		root = r
	} else if root.Val > R {
		root = l
	} else {
		root.Left = l
		root.Right = r
	}

	return root
}
