package longestup

import (
	. "leetcomm"
)

func longestUnivaluePath(root *TreeNode) int {
	maxlen := 0
	dfs(root, &maxlen)
	return maxlen
}

/* Returns the length of single direction Longest-Univalue-Path start from root */
func dfs(root *TreeNode, maxlen *int) int {
	if root == nil {
		return 0
	}
	// l is the length of single direction Longest-Univalue-Path start from left-child,
	// r is the length of single direction Longest-Univalue-Path start from right-child,
	l, r := 0, 0
	if root.Left != nil {
		l = dfs(root.Left, maxlen)
	}
	if root.Right != nil {
		r = dfs(root.Right, maxlen)
	}
	// resl is the length of single direction Longest-Univalue-Path start from parent go left,
	// resr is the length of single direction Longest-Univalue-Path start from parent go right.
	resl, resr := 0, 0
	if root.Left != nil && root.Val == root.Left.Val {
		resl = l + 1
	}
	if root.Right != nil && root.Val == root.Right.Val {
		resr = r + 1
	}
	*maxlen = Max(*maxlen, resl+resr)
	return Max(resl, resr)
}
