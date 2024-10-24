#pragma once
#include <queue>
using namespace std;

/*
117. 填充每个节点的下一个右侧节点指针 II
给定一个二叉树：
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
初始状态下，所有 next 指针都被设置为 NULL 。
*/

/*
思路分析：二叉树BFS
二叉树的层次遍历，需要使用bfs算法；
注意下一层入队列的顺序：先右后左，便于串接next指针；
*/
class Solution {
public:
    Node* connect(Node* root)
    {
        if (!root) {
            return root;
        }
        queue<Node*> q; // BFS需要使用队列辅助
        q.push(root);
        while (!q.empty()) { // 一次循环处理的是二叉树中的一层，并把下一层压入队列。
            int n = q.size(); // 队列size动态变化，必须提前缓存
            Node* last = nullptr;
            while (n--) {
                Node* cur = q.front();
                q.pop();
                cur->next = last;
                last = cur;
                // 顺序很关键：先右后左；便于串接next指针；
                if (cur->right)
                    q.push(cur->right);
                if (cur->left)
                    q.push(cur->left);
            }
        }
        return root;
    }
};

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node()
        : val(0)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {
    }

    Node(int _val)
        : val(_val)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {
    }

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val)
        , left(_left)
        , right(_right)
        , next(_next)
    {
    }
};