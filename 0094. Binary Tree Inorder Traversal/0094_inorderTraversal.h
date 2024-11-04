#pragma once
#include "TreeNode.h"
#include <functional>
#include <stack>
#include <vector>
using namespace std;

/*
思路分析1：非递归版，使用栈
要点：
    1）沿着左子树压栈到尽头，然后弹出，并把弹出节点的右子树压栈；
*/
class Solution_0094_01 {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        stack<TreeNode*> stk; // 节点指针入栈
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};

/*
思路分析2：递归版，常规dfs
*/
class Solution_0094_02 {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode* root, vector<int>& ans)
    {
        if (!root) {
            return;
        }
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
};

/*
思路3：显示指定类型的lambda表达式
要点：
    1）如果要单独指定捕获的符号，必须指定dfs自身；
*/
class Solution_0094_03 {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;

        // 如果要单独指定捕获的符号，必须指定dfs自身；
        function<void(TreeNode*)> dfs = [&ans, &dfs](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            ans.push_back(root->val);
            dfs(root->right);
        };

        dfs(root);
        return ans;
    }
};