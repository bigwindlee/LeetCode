package issymmetric

import (
	. "leetcomm"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isSymmetricHelp(root.Left, root.Right)
}

func isSymmetricHelp(left, right *TreeNode) bool {
	if left == nil || right == nil {
		return left == right
	}
	return left.Val == right.Val && isSymmetricHelp(left.Left, right.Right) && isSymmetricHelp(left.Right, right.Left)
}
