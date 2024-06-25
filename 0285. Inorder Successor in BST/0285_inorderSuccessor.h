#pragma once
#include <iostream>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

/*
本题的关键是，充分利用二叉搜索树（Binary Search Tree，简称BST）的特点，从root节点开始，往左/右走进行搜索；

中序后继：就是所有比给定值大的里面，最小的一个；也就是最接近给定值的那个；

节点 p 的后继是值比 p.val 大的节点中键值最小的节点；那么所有比 p.val 大的节点都有可能是解；
一种通用的技巧是，把第一个符合条件的解赋值给successor，并用`更`符合条件的解对successor进行刷新；最后得到的successor就是解；
*/
class Solution_0285 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        TreeNode* successor = NULL;
        while (root) {
            if (p->val < root->val) {
                successor = root; // 所有符合条件的节点都有可能是解，而沿着BST进行搜索正好可以寻找`更`符合条件的解；
                root = root->left; // 往左走，看看有没有更小一点的、但又比p.val大的节点；
            } else {
                root = root->right; // 往右走，因为当前节点不大于p.val，不是潜在的解；
            }
        }
        return successor;
    }
};

// 辅助函数：插入新节点到二叉搜索树
TreeNode* insert(TreeNode* root, int val)
{
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// 辅助函数：查找节点
TreeNode* search(TreeNode* root, int val)
{
    if (root == NULL || root->val == val) {
        return root;
    }
    if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}
