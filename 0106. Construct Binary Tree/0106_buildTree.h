#pragma once
#include "TreeNode.h"
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
思路分析1：
利用postorder序列的特点，可确定根节点；左-右-根，最后一个元素就是根节点！
在inorder序列中查找这个根节点，把inorder分成左子树和右子树，
然后递归的构建左子树和右子树！这是典型的二叉树DFS算法！

要点：
    1）如何表示左右子树呢？不要去复制vector数组的分段，而是用迭代器指明区间！
    2）用数组下标也可以标识区间，但是可读性没有迭代器好！
    3）建立inorder序列从value到iterator的映射，可避免频繁的在inorder序列中查找根节点；
    4）dfs函数不需要第4个参数postorder.end()，因为inorder和postorder的长度肯定是一样的；
 
 知识点：
    1）对于 随机访问迭代器（如 vector 的迭代器），可直接进行算术运算；
 */
class Solution {
public:
    typedef vector<int>::iterator v_t; // 随机访问迭代器
    unordered_map<int, v_t> hash; // inorder中，从value到iterator的映射
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        for (auto it = inorder.begin(); it != inorder.end(); ++it) {
            hash[*it] = it; // 从value到iterator的映射
        }
        return dfs(inorder.begin(), inorder.end(), postorder.begin());
    }

    TreeNode* dfs(v_t ibegin, v_t iend, v_t pbegin)
    {
        if (ibegin >= iend) {
            return nullptr;
        }
        v_t pend = pbegin + (iend - ibegin); // 计算得出postorder的end()迭代器
        int val = *prev(pend); // 末位元素
        TreeNode* root = new TreeNode(val);
        v_t it = hash[val]; // 避免每次遍历数组，根据值查找迭代器
        root->left = dfs(ibegin, it, pbegin); // 左子树长度为(it - ibegin)
        root->right = dfs(it + 1, iend, pbegin + (it - ibegin)); // pbegin跳过左子树长度
        return root;
    }
};

/*
思路2：
和思路1是一样的，同样是为了避免复制vector数组，采用下标区间的方式来标识分段；
就可读性来讲，不如采用迭代器。
*/
class Solution_0106_02 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return helper(inorder, 0, inorder.size(), postorder, 0);
    }

    TreeNode* helper(vector<int>& inorder, int iStart, int len, vector<int>& postorder, int pStart)
    {
        if (len == 0) {
            return nullptr;
        }
        int val = postorder[pStart + len - 1];
        TreeNode* root = new TreeNode(val);
        if (len == 1) {
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }

        // 寻找根节点在inorder中的下标
        int pos;
        for (int i = iStart; i < iStart + len; ++i) {
            if (val == inorder[i]) {
                pos = i;
                break;
            }
        }
        int left_len = pos - iStart;
        int right_len = len - left_len - 1;
        root->left = helper(inorder, iStart, left_len, postorder, pStart);
        root->right = helper(inorder, pos + 1, right_len, postorder, pStart + left_len);
        return root;
    }
};