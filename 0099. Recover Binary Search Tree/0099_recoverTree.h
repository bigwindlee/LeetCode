#pragma once
#include "TreeNode.h"
#include <algorithm>
#include <vector>
using namespace std;

/*
BST��������õ����������С������ڵ㱻���󽻻��������˳�򱻴��ơ�
���������֣�
����1�����������Բ�����ǰС�����Ҫ������һ�Եĵ�һ��Ԫ����ڶ��Եĵڶ���Ԫ�ء�
����2��ֻ����һ�Բ�����ǰС��󣬽�����һ��Ԫ�ؼ��ɡ�
���ɣ��Ѵ��Ƶ����ĳɶ�Ԫ�ؼ�¼������������һ�Ի������ԣ�������ǰѵ�һ��Ԫ�غ����һ��Ԫ�ؽ�����
��˲��ع�����һ�Ի������ԣ�ͳͳ��¼��vector�У�Ȼ��ѵ�һ��Ԫ�ص�ֵ�����һ��Ԫ�ص�ֵ���н�����
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