#pragma once
#include "TreeNode.h"

/*
513. 找树左下角的值
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。
*/

/*
思路分析：二叉树DFS
采用常规的先序遍历，把深度depth通过参数向下传递；
记住并刷新depth递增时的第一个节点。
*/
class Solution {
public:
    int last = 0, ans;
    int findBottomLeftValue(TreeNode* root)
    {
        dfs(root, 1);
        return ans;
    }

    void dfs(TreeNode* root, int depth)
    {
        if (depth > last) { // 深度递增
            last = depth;
            ans = root->val;
        }
        if (root->left)
            dfs(root->left, depth + 1);
        if (root->right)
            dfs(root->right, depth + 1);
    }
};