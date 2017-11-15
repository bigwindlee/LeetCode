package findtilt

import (
	. "leetcomm"
)

func findTilt(root *TreeNode) int {
	if root == nil {
		return 0
	}
	first, _ := dfs(root)
	return first
}

func dfs(root *TreeNode) (int, int) { // return tilt and sum of root
	if root == nil {
		return 0, 0
	}
	lt, ls := dfs(root.Left)  // left tilt, left sum
	rt, rs := dfs(root.Right) // right tilt, right sum
	return lt + rt + abs(ls, rs), root.Val + ls + rs
}

func abs(a, b int) int {
	if a > b {
		return a - b
	}
	return b - a
}
