package sortedlisttobst

import (
	. "leetcomm"
)

func sortedListToBST(head *ListNode) *TreeNode {
	nums := make([]int, 0)
	for p := head; p != nil; p = p.Next {
		nums = append(nums, p.Val)
	}
	return sortedArrayToBST(nums)
}

func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	m := len(nums) / 2
	return &TreeNode{nums[m], sortedArrayToBST(nums[:m]), sortedArrayToBST(nums[m+1:])}
}
