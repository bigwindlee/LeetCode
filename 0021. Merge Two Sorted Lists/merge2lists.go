package merge2lists

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	dummyHead := &ListNode{0, nil}
	cr := dummyHead
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			cr.Next = l1
			l1 = l1.Next
		} else {
			cr.Next = l2
			l2 = l2.Next
		}
		cr = cr.Next
	}
	if l1 != nil {
		cr.Next = l1
	} else {
		cr.Next = l2
	}
	return dummyHead.Next
}
