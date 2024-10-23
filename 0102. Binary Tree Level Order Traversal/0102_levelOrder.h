#pragma once
#include "TreeNode.h"
#include <queue>
#include <vector>
using namespace std;

/*
102. 二叉树的层序遍历
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
*/

/*
思路分析：BFS
BFS算法通常需要一个队列辅助，在访问某一层的节点时，把下一层的节点加入到队列中；
在循环体头部把队列的大小缓存起来（因为它会动态变化），利用这个size来界定某一层的节点；

知识点：
std::queue的常规方法：empty / size / front / back / push / pop
push是从队尾，pop是从队首，这是queue的特点。
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q; // 指针入队列，方便下一层的节点继续入队列。
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int n = q.size();
            // 有一个坑：循环中不能使用i < q.size(); 因为把一下层的节点加入queue后，size会变化。
            for (int i = 0; i < n; ++i) {
                TreeNode* p = q.front();
                q.pop();
                level.push_back(p->val);
                // 下一层节点入队列
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};