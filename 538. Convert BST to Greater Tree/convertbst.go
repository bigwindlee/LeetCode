package togreater

import (
	. "leetcomm"
)

func convertBST(root *TreeNode) *TreeNode {
	options := []func(root *TreeNode) *TreeNode{convertBST0, convertBST1}
	return options[1](root)
}

func convertBST1(root *TreeNode) *TreeNode {
	dfs1(root, 0)
	return root
}

func dfs1(root *TreeNode, sum int) int {
	if root == nil {
		return sum
	} else {
		root.Val += dfs1(root.Right, sum)
		return dfs1(root.Left, root.Val)
	}
}

func convertBST0(root *TreeNode) *TreeNode {
	sum := 0
	dfs0(root, &sum)
	return root
}

func dfs0(root *TreeNode, sum *int) {
	if root == nil {
		return
	}
	dfs0(root.Right, sum)
	*sum += root.Val
	root.Val = *sum
	dfs0(root.Left, sum)
}
