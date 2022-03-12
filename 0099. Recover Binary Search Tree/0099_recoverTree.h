#pragma once
#include "TreeNode.h"
#include <algorithm>
#include <vector>
using namespace std;

/*
BST中序遍历得到递增的数列。两个节点被错误交换则递增的顺序被打破。
错误有两种：
错误1：出现了两对不满足前小后大，需要交换第一对的第一个元素与第二对的第二个元素。
错误2：只出现一对不满足前小后大，交换这一对元素即可。
技巧：把打破递增的成对元素记录下来，无论是一对还是两对，结果都是把第一个元素和最后一个元素交换！
因此不必关心是一对还是两对，统统记录到vector中，然后把第一个元素的值和最后一个元素的值进行交换。
*/

class Solution_0099 {
public:
    void inorder(TreeNode* root, TreeNode*& prev, vector<TreeNode*>& errs)
    {
        if (root->left)
            inorder(root->left, prev, errs);

        if (prev) {
            if (prev->val > root->val) {
                errs.emplace_back(prev);
                errs.emplace_back(root);
            }
        }
        prev = root;

        if (root->right)
            inorder(root->right, prev, errs);
    }

    void recoverTree(TreeNode* root)
    {
        vector<TreeNode*> errs;
        TreeNode* prev = nullptr;

        inorder(root, prev, errs);

        int n = (int)errs.size();
        swap(errs[0]->val, errs[n - 1]->val);
    }
};