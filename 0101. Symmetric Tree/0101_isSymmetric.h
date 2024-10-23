#pragma once
#include "TreeNode.h"

/*
 思路分析：二叉树DFS，但有技巧！
 如果左树的左孩子与右树的右孩子对称，左树的右孩子与右树的左孩子对称，那么这个左树和右树就对称。
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        // 树中节点数目在范围 [1, 1000] 内，root不为空
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* left, TreeNode* right)
    {
        if (!left || !right) {
            return left == right;
        }
        return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};