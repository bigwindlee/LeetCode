package levelorder

import (
	. "leetcomm"
)

/* Breadth First Search */
func levelOrder(root *TreeNode) [][]int {
	ans := make([][]int, 0)
	if root == nil {
		return ans
	}
	q := make([]*TreeNode, 0) // queue, use "append" to do enqueue.
	q = append(q, root)
	for len(q) > 0 {
		lq := len(q)
		level := make([]int, 0)
		for i := 0; i < lq; i++ {
			deq := q[i]
			level = append(level, deq.Val)
			if deq.Left != nil {
				q = append(q, deq.Left)
			}
			if deq.Right != nil {
				q = append(q, deq.Right)
			}
		}
		q = q[lq:] // dequeue
		ans = append(ans, level)
	}
	return ans
}
