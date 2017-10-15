package diameter

import (
	. "leetcomm"
)

func diameterOfBinaryTree(root *TreeNode) int {
	first, _ := dfs(root)
	return first

}

func dfs(root *TreeNode) (int, int) { // return diameter and height
	if root == nil {
		return 0, 0
	}
	ld, lh := dfs(root.Left)
	rd, rh := dfs(root.Right)

	// Remember the maximum diameter
	return Max(ld, rd, lh+rh), 1 + Max(lh, rh)
}
