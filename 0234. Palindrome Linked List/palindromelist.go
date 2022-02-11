package palindrome

import (
	. "leetcomm"
)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

/*
 Given a singly linked list, determine if it is a palindrome.

 Follow up:
 Could you do it in O(n) time and O(1) space?
*/
func isPalindrome(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}
	p := head
	q := head.Next
	for q.Next != nil {
		p = p.Next
		q = q.Next
	}

	if head.Val != q.Val {
		return false
	} else {
		p.Next = nil  // get rid of the head and tail node
		return isPalindrome(head.Next)
	}
}
