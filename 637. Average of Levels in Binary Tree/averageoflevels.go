package averageoflevels

import (
	. "leetcomm"
)

func averageOfLevels(root *TreeNode) []float64 {
	ret := make([]float64, 0)
	if root == nil {
		return []float64{0}
	}
	q := make([]*TreeNode, 0) // queue, use "append" to do enqueue.
	q = append(q, root)
	for len(q) > 0 {
		lq := len(q)
		var sum float64
		for i := 0; i < lq; i++ {
			deq := q[i]
			sum += float64(deq.Val)
			if deq.Left != nil {
				q = append(q, deq.Left)
			}
			if deq.Right != nil {
				q = append(q, deq.Right)
			}
		}
		q = q[lq:] // dequeue
		ret = append(ret, sum/float64(lq))
	}

	return ret
}
