#pragma once
#include "TreeNode.h"

/*
572. ��һ����������
�������ö����� root �� subRoot ������ root ���Ƿ������ subRoot ������ͬ�ṹ�ͽڵ�ֵ��������������ڣ����� true �����򣬷��� false ��
������ tree ��һ���������� tree ��ĳ���ڵ������ڵ�����к���ڵ㡣tree Ҳ���Կ����������һ��������

˼·������
���������ĵݹ鶨�塣
*/
class Solution_0572 {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root || !subRoot) {
            return root == subRoot;
        }
        return sameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    // ���������ĵݹ鶨��
    bool sameTree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root || !subRoot) {
            return root == subRoot;
        }
        return root->val == subRoot->val && sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
    }
};
