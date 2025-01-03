﻿#pragma once
#include "TreeNode.h"
#include <climits>
#include <functional>
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
    
要点：怎么解决卡边界值的问题？有2种方法：
    1）使用LONG_MIN
    2）使用节点指针记录上一个节点；
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
    // 测试用例会卡边界值，例如BST中最小的值就是INT_MIN；有2种解决方案：
    // 1）使用long类型的最小值；
    // 2）使用节点指针，为空时不指向任何节点；
    long last = LONG_MIN;
};

class Solution_0098_02 {
public:
    bool isValidBST(TreeNode* root)
    {
        TreeNode* last = nullptr;
        bool ans = true;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            if (last && root->val <= last->val) { // 升序被打破
                ans = false;
                return;
            }
            last = root;
            dfs(root->right);
        };

        dfs(root);
        return ans;
    }
};