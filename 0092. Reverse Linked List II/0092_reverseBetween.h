#pragma once
#include "ListNode.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

思路分析：
 链表逆转 - 头插法，链表的全部逆转，部分逆转，都可以使用头插法。
 头插法需要3个指针：
 p: 固定节点，需要记住反转区间的前一个节点，因为反转后的区间要附加到这个节点后面。如果反转区间从首节点开始呢？所以本题需要一个dummy节点。 
 q: 固定节点，指向反转区间的第一个节点，通过q的定位，依次把q后面的节点调动到p节点的后面。
 r: 动态节点，通过q的定位，指向q后面待调动的节点。注意r是插入到p的后面，以及上一次的被调动节点的前面。
 */
class Solution_0092 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (head == nullptr || head->next == nullptr || left == right) {
            return head;
        }
        ListNode dummyNode(0, head);
        ListNode* dummy = &dummyNode;
        ListNode *p = dummy, *q, *r;
        int count = right - left;

        // p 指针就位，固定指向反转区间的前一个节点；待调动节点插入到p的后面。
        // q指针就位，固定指向反转区间的第一个节点，通过q的定位，依次把q后面的节点调动到p节点的后面。
        while (--left) {
            p = p->next;
        }
        q = p->next;

        // 进行头插
        while (count--) {
            r = q->next; // 动态节点，指向待调动节点。
            q->next = r->next; // 摘除r节点

            // 通过p指针的定位，把r节点插入到p指针的后面。
            r->next = p->next;
            p->next = r;
        }
        return dummy->next;
    }
};