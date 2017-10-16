package closestval

import (
	. "leetcomm"
)

/*
270. Closest Binary Search Tree Value

Total Accepted: 1815 Total Submissions: 6418 Difficulty: Easy

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

/**
 * type TreeNode struct {
 * 	Val   int
 * 	Left  *TreeNode
 * 	Right *TreeNode
 * }
 */

func closestValue(root *TreeNode, target float64) int {
	p := root
	diff := abs(float64(root.Val), target)
	ans := root.Val
	for p != nil {
		curr := float64(p.Val)
		if abs(curr, target) < diff {
			diff = abs(curr, target)
			ans = p.Val
		}
		if target > curr {
			p = p.Right
		} else if target < curr {
			p = p.Left
		} else {
			return p.Val
		}
	}
	return ans
}

func abs(a, b float64) float64 {
	if a > b {
		return a - b
	}
	return b - a
}
