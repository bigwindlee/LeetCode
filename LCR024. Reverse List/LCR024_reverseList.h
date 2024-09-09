#pragma once
#include "ListNode.h"

/*
LCR 024. 反转链表
给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。

思路分析：
递归是处理链表的一个重要方法，尤其是这种可以分解为规模较小但与原问题结构相似的子问题。
技巧是在递归函数体内只处理一个节点，剩下的节点交给递归函数去处理；而且要用子问题的解来表达当前节点（部分表达整体）。
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* p = reverseList(head->next); // 把当前节点摘出来，剩下的是一个结构相似的子问题，交给递归解决。
        head->next->next = head; // head的下一个节点就是子集反转后的末节点，把head添加到这个末节点之后。
        head->next = nullptr; // head成了末节点
        return p;
    }
};