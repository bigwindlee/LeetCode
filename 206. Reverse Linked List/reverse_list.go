package reverse

import (
	. "leetcomm"
)

func reverseList(head *ListNode) *ListNode {
	options := []func(head *ListNode) *ListNode{reverseList_0, reverseList_1, reverseList_2}
	return options[2](head)
}

/*------------------------------------------------------------------------------*/
/* Recursive solution */
func reverseList_2(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	newHead, _ := recursive(head)
	return newHead
}

func recursive(head *ListNode) (newHead, newTail *ListNode) {
	if head.Next == nil {
		return head, head
	}
	child_h, child_t := recursive(head.Next)
	child_t.Next = head
	head.Next = nil
	return child_h, head
}

/*------------------------------------------------------------------------------*/
/* In-place iterative solution */
func reverseList_1(head *ListNode) *ListNode {
	var newHead *ListNode
	for head != nil {
		next := head.Next // Cache the head.Next because it will change to point to the previous node.
		head.Next = newHead

		// Two pointers move forward
		newHead = head
		head = next // Restore the cached node
	}
	return newHead
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/*------------------------------------------------------------------------------*/
/* Using dummy head */
func reverseList_0(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return head
	}
	dummy := ListNode{0, head}
	p := &dummy
	q := head
	for q != nil {
		tmp := q.Next
		if p == &dummy {
			q.Next = nil
		} else {
			q.Next = p
		}
		p, q = q, tmp
	}
	return p
}
