#pragma once
#include "ListNode.h"

/*
19. 删除链表的倒数第 N 个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

思路分析：（双指针）
设置left/right双指针，其中right领先left指针n步。那么当right指向倒数第一个节点的时候，left指向倒数第n个节点的前一个节点。
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode dummyNode(-1, head); // 哨兵节点，便于删除头节点。
        ListNode *dummy = &dummyNode, *left = dummy, *right = dummy;

        // right领先left n步
        while (n--) {
            right = right->next;
        }

        // 退出本循环时，right指向倒数第一个节点，left指向待删节点的前一个节点。
        while (right->next) {
            left = left->next;
            right = right->next;
        }

        ListNode* target = left->next; // 记住待删节点，便于稍后删除。
        left->next = left->next->next; // 摘除待删节点
        delete target;
        return dummy->next;
    }
};