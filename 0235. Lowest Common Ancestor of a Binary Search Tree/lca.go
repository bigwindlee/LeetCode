package lowestcommonancestor

import (
	. "leetcomm"
)

func lowestCommonAncestor(root *TreeNode, p int, q int) int {
	ret := -1
	lowestCommonAncestorHelp(root, p, q, &ret)
	return ret
}

func lowestCommonAncestorHelp(root *TreeNode, p int, q int, ret *int) {
	if root == nil {
		return
	}
	pfound, qfound := false, false
	dfs(root, p, q, &pfound, &qfound)
	if pfound && qfound {
		*ret = root.Val
	}
	lowestCommonAncestorHelp(root.Left, p, q, ret)
	lowestCommonAncestorHelp(root.Right, p, q, ret)
}

func dfs(root *TreeNode, p int, q int, pfound *bool, qfound *bool) {
	if root == nil {
		return
	}
	if *pfound && *qfound {
		return
	}
	if !*pfound && root.Val == p {
		*pfound = true
	}
	if !*qfound && root.Val == q {
		*qfound = true
	}
	dfs(root.Left, p, q, pfound, qfound)
	dfs(root.Right, p, q, pfound, qfound)
}
