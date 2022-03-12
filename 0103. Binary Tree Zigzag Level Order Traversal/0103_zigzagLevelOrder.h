#pragma once
#include "TreeNode.h"
#include <queue>
#include <vector>
using namespace std;

/*
二叉树的层次遍历，使用bfs算法，需要一个队列辅助。
锯齿形层序遍历：一点小花样，每隔一层reverse一下。
*/
class Solution_0103 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if (!root)
            return {};

        vector<vector<int>> ans;
        bool flag = false; // 标志，每隔一层reverse一下。
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> layer;
            int n = q.size(); // 这一层的size固定下来，因为之后处理每个节点时其左右子节点会入队列，改变队列大小。
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // 锯齿形层序遍历：先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行
                if (flag)
                    layer.insert(layer.begin(), node->val);
                else
                    layer.emplace_back(node->val);

                // 子节点入队列
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            flag = !flag;
            ans.emplace_back(layer);
        }
        return ans;
    }
};