package pathsum3

import (
	. "leetcomm"
)

func pathSum(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}
	return dfs(root, sum) + pathSum(root.Left, sum) + pathSum(root.Right, sum)
}

func dfs(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}
	sum -= root.Val
	count := 0
	if sum == 0 {
		count++
	}
	return count + dfs(root.Left, sum) + dfs(root.Right, sum)
}
