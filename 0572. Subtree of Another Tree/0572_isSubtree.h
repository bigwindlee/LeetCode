#pragma once
#include "TreeNode.h"

/*
572. 另一棵树的子树
给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

思路分析：
理解二叉树的递归定义。
*/
class Solution_0572 {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root || !subRoot) {
            return root == subRoot;
        }
        return sameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    // 理解二叉树的递归定义
    bool sameTree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root || !subRoot) {
            return root == subRoot;
        }
        return root->val == subRoot->val && sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
    }
};
