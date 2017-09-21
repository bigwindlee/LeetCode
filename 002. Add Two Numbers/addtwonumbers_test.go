package addtwonumbers

import (
	"fmt"
	"testing"
)

func GetList(l []int) *ListNode {
	var ret, last *ListNode
	for _, value := range l {
		if ret == nil {
			last = &ListNode{value, nil}
			ret = last
		} else {
			last.Next = &ListNode{value, nil}
			last = last.Next
		}
	}
	return ret
}

func EqualList(a, b *ListNode) bool {
	pa := a
	pb := b
	for pa != nil && pb != nil {
		if pa.Val != pb.Val {
			return false
		}
		pa = pa.Next
		pb = pb.Next
	}
	if pa == nil && pb == nil {
		return true
	} else {
		return false
	}
}

func (pl *ListNode) String() string {
	var ret []int
	for p := pl; p != nil; p = p.Next {
		ret = append(ret, p.Val)
		fmt.Printf("append: %d\n", p.Val)
	}
	return fmt.Sprintf("%v", ret)
}

func TestAddTwoNumbers(t *testing.T) {

	testdata := [][3]*ListNode{
		{GetList([]int{1, 2, 3}),
			GetList([]int{4, 5, 6}),
			GetList([]int{5, 7, 9}),
		},

		{GetList([]int{7, 8, 9}),
			GetList([]int{1, 1, 1}),
			GetList([]int{8, 9, 0, 1}),
		},

		{GetList([]int{0}),
			GetList([]int{3, 2, 1}),
			GetList([]int{3, 2, 1}),
		},

		{GetList([]int{7, 8, 9}),
			GetList([]int{0}),
			GetList([]int{7, 8, 9}),
		},
	}

	for i := range testdata {
		if !EqualList(addTwoNumbers(testdata[i][0], testdata[i][1]), testdata[i][2]) {
			t.Errorf("%v + %v = %v, Expected: %v", testdata[i][0], testdata[i][1], addTwoNumbers(testdata[i][0], testdata[i][1]), testdata[i][2])
		}
	}
}
