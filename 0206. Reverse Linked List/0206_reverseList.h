#pragma once
#include "ListNode.h"

/*
方法1：三指针法
记住q的下一跳，反转q的下一跳；
*/
class Solution_0206_01 {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p = head, *q = head->next, *r;
        p->next = nullptr;
        while (q) {
            // 记住q的下一跳，反转q的下一跳
            r = q->next;
            q->next = p;

            // p/q前进
            p = q;
            q = r;
        }
        return p;
    }
};

/*
方法2：递归法
回溯的顺序正好是相反的，所有利用回溯做文章。
假设子集完成了反转，那么head->next成为了子集反转后的末节点！利用它的定位把当前head节点移动到末尾。
*/
class Solution_0206_02 {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode* p = reverseList(head->next);
        // head->next成为了子集反转后的末节点，利用它的定位把head移动到最后
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

/*
方法3：头插法
p指向第一个节点保存不变，通过p的定位把p后面的节点逐个的移动到头部；
头插法可以实现链表的部分反转。
*/
class Solution_0206_03 {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p = head, *q;
        while (q = p->next) {
            // p下一跳越过q，把q摘出来
            p->next = q->next;
            // 把q插入到最前面，成为新的head
            q->next = head;
            head = q;
        }
        return head;
    }
};