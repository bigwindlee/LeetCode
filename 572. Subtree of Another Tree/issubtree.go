package issubtree

import (
	. "leetcomm"
)

func isSubtree(s *TreeNode, t *TreeNode) bool {
	if t == nil {
		return true
	}
	if s == nil {
		return false
	}
	q := make([]*TreeNode, 0)
	q = append(q, s)
	for len(q) > 0 {
		deq := q[0]
		if isSameTree(deq, t) {
			return true
		}
		q = q[1:]
		if deq.Left != nil {
			q = append(q, deq.Left)
		}
		if deq.Right != nil {
			q = append(q, deq.Right)
		}
	}
	return false
}

func isSameTree(p, q *TreeNode) bool {
	if p == nil || q == nil {
		return p == q
	}
	return p.Val == q.Val && isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}
