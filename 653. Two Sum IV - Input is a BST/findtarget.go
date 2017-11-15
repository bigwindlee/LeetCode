package find2sum

import (
	. "leetcomm"
)

func findTarget(root *TreeNode, k int) bool {
	options := []func(root *TreeNode, k int) bool{findTarget0, findTarget1}
	return options[1](root, k)
}

/*-----------------------------------------------------
            Method 1
-----------------------------------------------------*/
func findTarget1(root *TreeNode, k int) bool {
	nums := []int{}
	dfs1(root, &nums)
	for i, j := 0, len(nums)-1; i < j; {
		sum := nums[i] + nums[j]
		if sum == k {
			return true
		} else if sum > k {
			j--
		} else {
			i++
		}
	}
	return false
}

func dfs1(root *TreeNode, nums *[]int) {
	if root == nil {
		return
	}
	dfs1(root.Left, nums)
	*nums = append(*nums, root.Val)
	dfs1(root.Right, nums)
}

/*-----------------------------------------------------
            Method 0
-----------------------------------------------------*/
func findTarget0(root *TreeNode, k int) bool {
	nums := make([]int, 0)
	return dfs0(root, k, &nums)
}

func dfs0(root *TreeNode, k int, nums *[]int) bool {
	if root == nil {
		return false
	}
	lfound := dfs0(root.Left, k, nums)
	if binarysearch(*nums, k-root.Val) {
		return true
	}
	*nums = append(*nums, root.Val)
	return lfound || dfs0(root.Right, k, nums)
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
