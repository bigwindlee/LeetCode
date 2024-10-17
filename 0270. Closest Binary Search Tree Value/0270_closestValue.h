#pragma once
#include "TreeNode.h"
#include <cstdlib>
using namespace std;

/*
270. 最接近的二叉搜索树值
给你二叉搜索树的根节点 root 和一个目标值 target ，请在该二叉搜索树中找到最接近目标值 target 的数值。如果有多个答案，返回最小的那个。
*/

/*
思路分析：二叉搜索树
二叉搜索树的特征非常明显：大了往右找，小了往左找；
*/
class Solution {
public:
    int closestValue(TreeNode* root, double target)
    {
        int ans = root->val;
        double bias = abs(target - ans);

        TreeNode* p = root;
        while (p) {
            double nb = target - p->val; // new bias
            if (abs(nb) < bias) { // 偏移更小，更接近；
                bias = abs(nb);
                ans = p->val;
            } else if (abs(nb) == bias && p->val < ans) { // 多个答案，返回最小的
                ans = p->val;
            }
            p = (nb > 0) ? p->right : p->left; // 大了往右找，小了往左找
        }
        return ans;
    }
};