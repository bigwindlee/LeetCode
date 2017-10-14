package findsecmin

import (
	. "leetcomm"
)

func findSecondMinimumValue(root *TreeNode) int {
	if root == nil {
		return -1
	}
	first, second := root.Val, -1
	dfs(root, first, &second)
	return second
}

func dfs(root *TreeNode, first int, second *int) {
	if root == nil {
		return
	}
	//refresh the second min
	if root.Val != first && (root.Val < *second || *second == -1) {
		*second = root.Val
	}
	dfs(root.Left, first, second)
	dfs(root.Right, first, second)
}
