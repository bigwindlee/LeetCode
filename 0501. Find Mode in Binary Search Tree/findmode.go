package findmode

import (
	. "leetcomm"
)

func findMode(root *TreeNode) []int {
	res := []int{}
	modes := map[int]int{}
	dfs(root, &modes)
	freq := 0
	for i, val := range modes {
		if val > freq {
			res = []int{i}
			freq = val
		} else if val == freq {
			res = append(res, i)
		}
	}
	return res
}

func dfs(root *TreeNode, modes *map[int]int) {
	if root == nil {
		return
	}
	dfs(root.Left, modes)
	(*modes)[root.Val]++
	dfs(root.Right, modes)
}
