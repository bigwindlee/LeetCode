#pragma once
#include "TreeNode.h"
#include <queue>
#include <vector>
using namespace std;

/**
103. 二叉树的锯齿形层序遍历
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
*/

/*
思路分析：二叉树BFS
二叉树的常规BFS，只不过需要一个反转标志，实现每一层的交替反转，形成锯齿形层序遍历。
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q; // BFS需要把下一层入队列
        q.push(root);
        bool order = false; // 反转标志，首层不反转
        while (!q.empty()) {
            int n = q.size(); // 缓存队列大小，因为队列大小会动态变化
            vector<int> path; // 收集每一层的元素
            while (n--) {
                TreeNode* cur = q.front();
                q.pop();
                path.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (order) reverse(path.begin(), path.end());
            ans.push_back(path);
            order = !order; // 每一层交替反转，锯齿形层序遍历
        }
        return ans;
    }
};