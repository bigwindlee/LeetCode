package addtwonumbers

/**
 * Definition for singly-linked list.
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummyHead := &ListNode{0, nil}
	curr := dummyHead
	pl1 := l1
	pl2 := l2
	carry := 0

	for pl1 != nil || pl2 != nil {
		sum := 0
		if pl1 == nil {
			sum = pl2.Val + carry
		} else if pl2 == nil {
			sum = pl1.Val + carry
		} else {
			sum = pl1.Val + pl2.Val + carry
		}

		carry = sum / 10
		curr.Next = &ListNode{sum % 10, nil}
		curr = curr.Next

		if pl1 != nil {
			pl1 = pl1.Next
		}
		if pl2 != nil {
			pl2 = pl2.Next
		}
	}

	if carry == 1 {
		curr.Next = &ListNode{1, nil}
		curr = curr.Next
	}

	return dummyHead.Next
}
