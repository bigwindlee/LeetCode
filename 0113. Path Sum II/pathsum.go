package pathsum

import (
	. "leetcomm"
)

func pathSum(root *TreeNode, sum int) [][]int {
	ret := make([][]int, 0)
	pathlist := make([]int, 0)
	pathSumHelp(root, sum, pathlist, &ret)
	return ret
}

func pathSumHelp(root *TreeNode, sum int, pathlist []int, pathsum *[][]int) {
	if root == nil {
		return
	}
	pathlist = append(pathlist, root.Val)
	sum -= root.Val
	if root.Left == nil && root.Right == nil && sum == 0 {
		*pathsum = append(*pathsum, DupSlice(pathlist))
	}

	pathSumHelp(root.Left, sum, pathlist, pathsum)
	pathSumHelp(root.Right, sum, pathlist, pathsum)
}
