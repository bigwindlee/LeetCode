package rmelements

import (
	. "leetintlist" // define ListNode and related methods.
)

func removeElements(head *ListNode, val int) *ListNode {
	dummyHead := &ListNode{0, head}
	guard := dummyHead
	worker := head
	for worker != nil {
		if worker.Val == val {
			guard.Next = worker.Next
		} else {
			guard = guard.Next
		}
		worker = worker.Next
	}
	return dummyHead.Next
}
