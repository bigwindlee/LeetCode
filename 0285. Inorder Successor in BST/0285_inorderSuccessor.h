#pragma once
#include <iostream>

// ����������ڵ�ṹ
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

/*
����Ĺؼ��ǣ�������ö�����������Binary Search Tree�����BST�����ص㣬��root�ڵ㿪ʼ������/���߽���������

�����̣��������бȸ���ֵ������棬��С��һ����Ҳ������ӽ�����ֵ���Ǹ���

�ڵ� p �ĺ����ֵ�� p.val ��Ľڵ��м�ֵ��С�Ľڵ㣻��ô���б� p.val ��Ľڵ㶼�п����ǽ⣻
һ��ͨ�õļ����ǣ��ѵ�һ�����������Ľ⸳ֵ��successor������`��`���������Ľ��successor����ˢ�£����õ���successor���ǽ⣻
*/
class Solution_0285 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        TreeNode* successor = NULL;
        while (root) {
            if (p->val < root->val) {
                successor = root; // ���з��������Ľڵ㶼�п����ǽ⣬������BST�����������ÿ���Ѱ��`��`���������Ľ⣻
                root = root->left; // �����ߣ�������û�и�Сһ��ġ����ֱ�p.val��Ľڵ㣻
            } else {
                root = root->right; // �����ߣ���Ϊ��ǰ�ڵ㲻����p.val������Ǳ�ڵĽ⣻
            }
        }
        return successor;
    }
};

// ���������������½ڵ㵽����������
TreeNode* insert(TreeNode* root, int val)
{
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// �������������ҽڵ�
TreeNode* search(TreeNode* root, int val)
{
    if (root == NULL || root->val == val) {
        return root;
    }
    if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}
