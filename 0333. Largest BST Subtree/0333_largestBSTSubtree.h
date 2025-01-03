﻿#pragma once
#include "TreeNode.h"
#include <algorithm>
#include <climits>
#include <functional>
using namespace std;

/* -------------------------------------------------------------------------------------------
333. 最大二叉搜索子树
给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，并返回该`子树`的大小。其中，最大指的是子树节点数最多的。

二叉搜索树（BST）中的所有节点都具备以下属性：
    1）左子树的值小于其父（根）节点的值。
    2）右子树的值大于其父（根）节点的值。

注意：子树必须包含其所有后代。
*/

/* -------------------------------------------------------------------------------------------
思路分析：二叉树DFS
    本题演示了使用DFS遍历二叉树，在回溯时把信息逐级上报并归拢的过程（dfs返回一个struct）。
*/

/* -------------------------------------------------------------------------------------------
Node: 从下往上逐级上报的信息。 
    l,r表示当前节点为根的二叉搜索树里的值的范围[l,r]，
    sz为这棵树的节点数，如果不是BST,则sz=-1，还未递归前l=r=root->val

左右子树在回溯的时候，把信息带到父节点。
*/
class Solution {
public:
    int largestBSTSubtree(TreeNode* root)
    {
        if (!root) {
            return 0;
        }

        int ans = 1;
        function<Node(TreeNode*)> dfs = [&](TreeNode* root) {
            // 起初的范围是[root->val,root->val]，再根据左右子树更新范围
            int l = root->val, r = root->val, count = 1;
            // DFS触达叶子节点，递归出口。
            if (!root->left && !root->right) { // 叶子节点肯定是BST
                return Node { l, r, count };
            }

            bool valid = true;
            if (root->left) {
                Node L = dfs(root->left);
                if (L.count > 0 && l > L.r) { // 注意是和左子树的右边界比较
                    l = L.l; // 刷新左边界
                    count += L.count; // 刷新节点数量
                } else {
                    valid = false;
                }
            }
            if (root->right) {
                Node R = dfs(root->right);
                if (R.count > 0 && r < R.l) { // 注意是和右子树的左边界比较
                    r = R.r; // 刷新右边界
                    count += R.count; // 刷新节点数量
                } else {
                    valid = false;
                }
            }

            if (valid) {
                ans = max(ans, count);
                return Node { l, r, count };
            }
            return Node { -1, -1, -1 }; // count设为-1标记不是BST
        };

        dfs(root);
        return ans;
    }

private:
    struct Node {
        int l, r, count; // count设置为-1表示以当前节点为根的子树不是BST，此时忽略掉l/r；
    };
};

/*
思路分析2：枚举（低效）
直观的想法就是我枚举每一个节点，去检查这个节点为根的子树是不是一棵二叉搜索树，如果是的话就统计一下这个子树的节点数并更新答案，
否则就继续递归到左右子树去找有没有符合条件的二叉搜索树。
那么先考虑如何判断一棵树是不是二叉搜索树，根据二叉搜索树的性质，我们可以从上往下递归判断。

缺点：
    思路2简单的将一个问题割裂成了若干个判断子树是不是二叉搜索树的问题，并没有复用已有的信息。
*/
class Solution_0333_02 {
public:
    bool valid(TreeNode* root, int l, int r)
    {
        if (!root)
            return true;
        if (root->val <= l || root->val >= r)
            return false;
        return valid(root->left, l, root->val) && valid(root->right, root->val, r);
    }

    int cnt(TreeNode* root)
    {
        return root ? cnt(root->left) + cnt(root->right) + 1 : 0;
    }

    int largestBSTSubtree(TreeNode* root)
    {
        if (!root)
            return 0;
        if (valid(root, INT_MIN, INT_MAX))
            return cnt(root);
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};
