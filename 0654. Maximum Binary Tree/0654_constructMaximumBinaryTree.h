#pragma once
#include "TreeNode.h"
#include <algorithm>
#include <vector>
using namespace std;

/*
654. 最大二叉树
给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
    1）创建一个根节点，其值为 nums 中的最大值。
    2）递归地在最大值 左边 的 子数组前缀上 构建左子树。
    3）递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。
*/

/*
思路分析：二叉树DFS
本题是非常典型的用DFS算法递归的构造二叉树；

核心要点：
    用迭代器表示数组区间，而不是把那一段复制出来！
*/
class Solution {
public:
    typedef vector<int>::iterator vt;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return dfs(nums.begin(), nums.end());
    }

    TreeNode* dfs(vt begin, vt end) // 迭代器表示数组区间
    {
        if (begin >= end) {
            return nullptr;
        }
        auto it = max_element(begin, end);
        TreeNode* root = new TreeNode(*it);
        root->left = dfs(begin, it);
        root->right = dfs(it + 1, end);
        return root;
    }
};