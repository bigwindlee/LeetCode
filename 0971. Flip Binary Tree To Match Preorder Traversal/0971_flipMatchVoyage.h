#pragma once
#include "TreeNode.h"
#include <vector>
using namespace std;

/*
971. 翻转二叉树以匹配先序遍历
给你一棵二叉树的根节点 root ，树中有 n 个节点，每个节点都有一个不同于其他节点且处于 1 到 n 之间的值。
另给你一个由 n 个值组成的行程序列 voyage ，表示 预期 的二叉树 先序遍历 结果。
通过交换节点的左右子树，可以 翻转 该二叉树中的任意节点。
请翻转 最少 的树中节点，使二叉树的 先序遍历 与预期的遍历行程 voyage 相匹配 。 
如果可以，则返回 翻转的 所有节点的值的列表。你可以按任何顺序返回答案。如果不能，则返回列表 [-1]。

思路分析：
二叉树的先序遍历，也就是先根遍历，一般是“根-左-右”的顺序。本题的核心是在某些条件下换成“根-右-左”的顺序！
要求遍历的顺序与给定的数组相匹配，那么就要判断什么时候换成“根-右-左”的顺序！

技巧：
1. 深度优先搜索，dfs的返回类型定义为bool，这样可以判断遍历的过程中，是否和给定的数组相匹配！
2. 注意换成“根-右-左”的顺序要满足的条件：
    1）左节点不为空，因为左节点为空的话，不需要交换左右节点，就达到“根-右”的顺序；
    2）右节点不为空，且值与 voyage 相匹配，此时需要交换左右节点，才能使“先序遍历”与预期的遍历行程 voyage 相匹配；
3. 不要在dfs外部判断左节点值是否匹配，而是放到dfs内部。这样的逻辑也符合根节点；
4. 需要一个全局指针对“给定的数组”进行扫描。

*/
class Solution_0971 {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage)
    {
        if (!root) {
            return { -1 };
        }
        i = 0; // 全局指针扫描voyage
        vector<int> ans;
        if (dfs(root, voyage, ans)) {
            return ans;
        } else {
            return { -1 };
        }
    }

    bool dfs(TreeNode* root, vector<int>& voyage, vector<int>& ans)
    {
        if (!root) { // 能够避开节点值不匹配的情况，顺利触底。
            return true;
        }
        if (root->val != voyage[i++]) { // 判断节点值是否匹配，同样适合根节点！
            return false;
        }
        // 左节点不为空时，才需要交换左右节点。
        if (root->left && root->right && root->right->val == voyage[i]) {
            ans.push_back(root->val);
            return dfs(root->right, voyage, ans) && dfs(root->left, voyage, ans);
        }
        // 不要在dfs外部判断左节点值是否匹配，而是放到dfs内部。这样的逻辑也符合根节点；
        // 避免根节点的单独处理。
        return dfs(root->left, voyage, ans) && dfs(root->right, voyage, ans);
    }
    int i;
};
