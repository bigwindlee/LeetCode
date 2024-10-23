#pragma once
#include "TreeNode.h"
#include <climits>
using namespace std;

/*
98. 验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：
  ● 节点的左子树只包含 小于 当前节点的数。
  ● 节点的右子树只包含 大于 当前节点的数。
  ● 所有左子树和右子树自身必须也是二叉搜索树。
*/

/*
思路分析：中序遍历
BST中序遍历必须满足升序
*/
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        if (!root) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (root->val <= last) { // BST中序遍历为升序
            return false; // 打破升序
        }
        last = root->val; // 迭代last
        if (!isValidBST(root->right)) {
            return false;
        }
        return true;
    }

private:
    long last = LONG_MIN;
};