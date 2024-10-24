#pragma once
#include "ListNode.h"

/*
25. K 个一组翻转链表
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
*/

/*
思路分析：头插法 + 递归
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        // 统计节点个数，不够k个则保持原样；
        int count = 0;
        ListNode* p = head;
        while (p) {
            ++count;
            p = p->next;
        }
        if (count < k) {
            return head;
        }

        // 头插法反转k个节点
        p = head;
        ListNode* q = p->next;
        int i = k;
        while (--i) { // 头插法移动k-1个节点
            p->next = q->next;
            q->next = head;
            head = q;
            q = p->next;
        }

        // 剩下的交给递归函数去做
        p->next = reverseKGroup(p->next, k);
        return head;
    }
};