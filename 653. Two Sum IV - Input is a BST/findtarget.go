package find2sum

import (
	"fmt"
	. "leetcomm"
)

func findTarget(root *TreeNode, k int) bool {
	nums := make([]int, 0)
	return dfs(root, k, &nums)
}

func dfs(root *TreeNode, k int, nums *[]int) bool {
	if root == nil {
		return false
	}
	lfound := dfs(root.Left, k, nums)
	fmt.Printf("curr: %d, nums: %v, k: %d\n", root.Val, *nums, k)
	if binarysearch(*nums, k-root.Val) {
		return true
	}
	*nums = append(*nums, root.Val)
	return lfound || dfs(root.Right, k, nums)
}

func binarysearch(nums []int, target int) bool {
	l := len(nums)
	left, right := 0, l-1
	for left <= right {
		mid := (left + right) / 2
		if nums[mid] == target {
			return true
		} else if nums[mid] > target {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return false
}
