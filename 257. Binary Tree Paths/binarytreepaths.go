package binarytreepaths

import (
	. "leetcomm"
)

func binaryTreePaths(root *TreeNode) []string {
	paths := make([][]int, 0)
	path := make([]int, 0)
	dfs(root, path, &paths)

	ret := make([]string, 0)
	for i := range paths {
		bs := make([]byte, 0)
		bs = append(bs, itoa(paths[i][0])...)
		for j := 1; j < len(paths[i]); j++ {
			bs = append(bs, []byte("->")...)
			bs = append(bs, itoa(paths[i][j])...)
		}
		ret = append(ret, string(bs))
	}
	return ret
}

func itoa(a int) []byte {
	ret := make([]byte, 0)
	neg := false
	if a < 0 {
		neg = true
		a *= -1
	}
	if a < 10 {
		ret = append(ret, '0'+byte(a))
	} else {
		for a > 0 {
			ret = append(ret, '0'+byte(a%10))
			a /= 10
		}
	}
	for i := 0; i < len(ret)/2; i++ {
		ret[i], ret[len(ret)-1-i] = ret[len(ret)-1-i], ret[i]
	}

	if neg {
		return append([]byte{'-'}, ret...)
	} else {
		return ret
	}
}

func dfs(root *TreeNode, path []int, paths *[][]int) {
	if root == nil {
		return
	}
	path = append(path, root.Val)
	if root.Left == nil && root.Right == nil {
		*paths = append(*paths, DupSlice(path))
	}
	dfs(root.Left, path, paths)
	dfs(root.Right, path, paths)
}
