#pragma once
#include "TreeNode.h"

/*
236. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
*/

/*
思路分析：LCA（Lowest Common Ancestor）算法
这个算法通常被称为二叉树中的最近公共祖先问题的递归解法，或者简称为LCA（Lowest Common Ancestor）算法。这是一个经典的递归算法，用于查找二叉树中两个节点的最近公共祖先。
该方法充分利用了二叉树的递归结构，通过自顶向下地遍历树，逐层判断当前节点是否是两个目标节点的祖先。

使用DFS搜索p/q节点中的任何一个，搜索到则立刻回溯；
如果左右子树都不为空，说明p/q分居当前节点的左右子树，则将当前节点上浮；否则上浮非空的子节点。
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // DFS搜索p/q节点中的任何一个，搜索到则立刻回溯；
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // 递归查找左子树和右子树
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 如果左右子树均不为空，说明p/q分居当前节点的左右子树，说明当前节点是最近公共祖先。
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // 否则返回非空子树的结果
        return left != nullptr ? left : right;
    }
};
