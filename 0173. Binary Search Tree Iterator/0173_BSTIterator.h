#pragma once
#include "TreeNode.h"
#include <stack>
using namespace std;

/* ---------------------------------------------------------------------------------------------------------
173. 二叉搜索树迭代器
实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
  ● BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。
    指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
  ● boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
  ● int next()将指针向右移动，然后返回指针处的数字。

注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。
你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。
*/

/* ---------------------------------------------------------------------------------------------------------
思路分析：本题需要深刻理解二叉树的“中序遍历”

朴素解法：
对二叉树进行中序遍历，并把结果保存在一个数组中。利用数组来实现 next() 和 hasNext()。空间复杂度为O(n)。

如果要求：next() 和 hasNext() 操作均摊时间复杂度为 O(1) ，并使用 O(h) 内存。其中 h 是树的高度。
正规解法：
沿着 cur节点的 left child 方向把所有节点压栈，压到底。然后弹出一个节点，并保存弹出节点的 right child 到cur指针中。
*/
class BSTIterator {
private:
    TreeNode* cur; // 上一次弹出节点的 right child
    stack<TreeNode*> stk;

public:
    BSTIterator(TreeNode* root)
        : cur(root)
    {
    }

    int next()
    {
        // 左
        while (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        }

        // 中
        cur = stk.top();
        stk.pop();
        int ret = cur->val;

        // 右
        cur = cur->right;

        return ret;
    }

    bool hasNext()
    {
        return cur != nullptr || !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */