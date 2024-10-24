#pragma once
#include "TreeNode.h"

/*
114. 二叉树展开为链表
给你二叉树的根结点 root ，请你将它展开为一个单链表：
  ● 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
  ● 展开后的单链表应该与二叉树 先序遍历 顺序相同。
*/

/*
思路分析：二叉树DFS先序（根-左-右）的逆序 —— （右-左-根）
题目要求单链表与二叉树先序遍历的顺序相同，而且left指针置空；
如果按照先序访问节点，先处理根节点，此时左子树还没处理，把left置空的话，就失去和左子树的联系了。
逆向思维：如果先序的序列为1,2,3,4,5,6；那么（右-左-根）的序列必然是6,5,4,3,2,1
此时我们首先访问的是链表的末节点6；而且把它的left置空没有问题，因为按照（右-左-根）的顺序，左子树已经处理过了。
弄一个全局指针cur指向当前处理的节点，就能把链表串起来。
*/
class Solution {
public:
    void flatten(TreeNode* root)
    {
        if (!root) {
            return;
        }
        // 先序（根 - 左 - 右）的逆序 —— （右 - 左 - 根）
        flatten(root->right);
        flatten(root->left);
        root->right = cur;
        root->left = nullptr; // 此时把left置为空没有问题
        cur = root;
    }

private:
    TreeNode* cur = nullptr;
};