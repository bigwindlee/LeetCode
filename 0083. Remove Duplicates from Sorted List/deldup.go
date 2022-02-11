package deldup

import (
	. "leetcomm"
)

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func deleteDuplicates(head *ListNode) *ListNode {
	options := []func(head *ListNode) *ListNode{deleteDuplicates_0}
	return options[0](head)
}

/* Just need one pointer */
func deleteDuplicates_1(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	curr := head
	for curr.Next != nil {
		if curr.Val == curr.Next.Val {
			curr.Next = curr.Next.Next
		} else {
			curr = curr.Next
		}
	}
	return head
}

/*
Use 2 pointers p and q, p points to the current node and q is advancing to find
a different node than p.
*/
func deleteDuplicates_0(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	p, q := head, head.Next
	for q != nil {
		for ; q != nil && q.Val == p.Val; q = q.Next {
		}
		p.Next = q
		p = q
		if q != nil {
			q = q.Next
		}
	}

	return head
}
