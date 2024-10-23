#pragma once
#include "TreeNode.h"
#include "algorithm"
using namespace std;

/*
* 124. 二叉树中的最大路径和
二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其 最大路径和 。

思路分析：（二叉树dfs）
把dfs的返回值定义为：当前节点能向父节点提供的最大收益。
当前节点（以当前节点为根节点的树）有2种选择：
1）在当前节点内部构成一条完整的路径和：root->val + dfs(root->left) + dfs(root->right)，这种情况“路径”不能向父节点延伸；
2）能向父节点提供收益，那么左右子树最多只能取一个。

难点：
分开处理`最大路径能否向父节点延伸的情况`。用一个全局变量记录
*/
class Solution {
private:
    int ans = INT_MIN;

public:
    int maxPathSum(TreeNode* root)
    {
        dfs(root);
        // 最上层dfs的返回值不能要，因为dfs是可以舍弃整棵树的。
        return ans;
    }

    // dfs 通过返回值向父节点提供收益；父节点不接受负收益，否则不如舍弃这个节点。
    int dfs(TreeNode* root)
    {
        if (!root)
            return 0;

        int L = dfs(root->left); // 左子树能提供的最大收益（舍弃负收益）
        int R = dfs(root->right); // 右子树能提供的最大收益（舍弃负收益）

        // 单独处理不向父节点延伸的情况：当前节点的“内部路径和”挑战“最大路径和”
        // 难点：为什么必须包含当前节点？因为L和R都可以为空（舍弃负收益），不允许空路径存在（至少必须包含一个节点）。
        // 不包含当前节点的情况，在下一级节点的递归中处理。例如：假如L就是最终的解，那么递归到L作为根节点的时候会处理。
        ans = max(ans, L + root->val + R);

        // “路径”要向父节点延伸，左右子树最多只能取一个。
        // 向父节点提供收益：有4种可能性：
        // 1）不要当前节点（因为是负收益）
        // 2）只要当前节点
        // 3）要当前节点 + 左右子树二选一
        return max({ 0, root->val, root->val + L, root->val + R });
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
