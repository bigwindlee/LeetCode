package longestup

import (
	. "leetcomm"
)

/* 687. Longest Univalue Path
https://leetcode.com/problems/longest-univalue-path/description/

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
*/

func longestUnivaluePath(root *TreeNode) int {
	lup := 0
	dfs(root, &lup)
	return lup
}

/* Returns the length of single direction Longest-Univalue-Path start from root */
func dfs(root *TreeNode, lup *int) int {
	if root == nil {
		return 0
	}
	// l is the length of single direction Longest-Univalue-Path start from left-child,
	// r is the length of single direction Longest-Univalue-Path start from right-child,
	l, r := 0, 0
	if root.Left != nil {
		l = dfs(root.Left, lup)
	}
	if root.Right != nil {
		r = dfs(root.Right, lup)
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
	*lup = Max(*lup, resl+resr) // Longest-Univalue-Path
	return Max(resl, resr)
}
