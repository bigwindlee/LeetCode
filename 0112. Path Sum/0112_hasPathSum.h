#pragma once
#include "TreeNode.h"

/*
112. 路径总和
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。
*/

/*
思路分析：二叉树DFS
要点：在叶子节点处拦截，不要继续深入到叶子节点的null子节点；否则，到了null子节点后无法判断父节点是否叶子节点；
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (!root) {
            return false;
        }
        targetSum -= root->val; // 扣除本节点的值，剩余的下发
        if (!root->left && !root->right) { // 在叶子节点处拦截，不要继续深入到叶子节点的null子节点；否则，到了null子节点后无法判断父节点是否叶子节点；
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};