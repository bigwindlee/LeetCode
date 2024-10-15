#pragma once
#include "Node.h"
#include <unordered_map>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
记忆化dfs，防止重复创建节点。

链表中的节点有2个指针：next/random，意味着dfs有2个搜索（创建）的方向。

dfs沿着next方向前进并触底（到达链表末尾），会把所有节点都创建出来。递归函数不停的压栈结束，开始退栈；
注意退栈的顺序恰好是逆序的，在逆序退栈的过程中，依次把每个节点的random指针挂上。

递归函数原型：Node* copyRandomList(Node* head)
返回的是head节点对应的副本节点，查表，如果已经创建，则直接返回；
如果还没创建，则创建这个副本，并（利用递归）分别把next节点和random节点的副本挂上。

*/
class Solution {
public:
    unordered_map<Node*, Node*> hash; // 建立从旧节点指针到新节点指针的映射
    Node* copyRandomList(Node* head)
    {
        if (!head) {
            return nullptr;
        }
        Node* curr = new Node(head->val);
        hash[head] = curr; // 旧节点指针 => 新节点指针
        curr->next = copyRandomList(head->next); // DFS: 深度优先保证沿着next把所有节点创建完毕；
        curr->random = hash[head->random]; // 回溯时，所有节点已经创建完毕；
        return curr;
    }
};