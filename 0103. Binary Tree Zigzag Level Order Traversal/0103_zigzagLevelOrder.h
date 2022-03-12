#pragma once
#include "TreeNode.h"
#include <queue>
#include <vector>
using namespace std;

/*
�������Ĳ�α�����ʹ��bfs�㷨����Ҫһ�����и�����
����β��������һ��С������ÿ��һ��reverseһ�¡�
*/
class Solution_0103 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if (!root)
            return {};

        vector<vector<int>> ans;
        bool flag = false; // ��־��ÿ��һ��reverseһ�¡�
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> layer;
            int n = q.size(); // ��һ���size�̶���������Ϊ֮����ÿ���ڵ�ʱ�������ӽڵ������У��ı���д�С��
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // ����β���������ȴ������ң��ٴ������������һ��������Դ����ƣ������֮�佻�����
                if (flag)
                    layer.insert(layer.begin(), node->val);
                else
                    layer.emplace_back(node->val);

                // �ӽڵ������
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