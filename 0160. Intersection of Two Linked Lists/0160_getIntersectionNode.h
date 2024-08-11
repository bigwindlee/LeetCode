#pragma once
#include "ListNode.h"

/*
160. 相交链表
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
题目数据 保证 整个链式结构中不存在环。
注意，函数返回结果后，链表必须 保持其原始结构 。

思路分析：
本题的思路有点巧妙，更像一个脑筋急转弯。
链表A的长度 + 链表B的长度 == 链表B的长度 + 链表A的长度。
指针pA的行走路径是，先走A，再走B；指针pB的行走路径是，先走B，再走A。
pA和pB总的行程长度是相等的。如果存在交点，从交点开始的行程是重合的，因此pA和pB一定相遇在交点！
如果不存在交点，pA和pB各自走完行程后，都指向nullptr，这时也是相等的。
所以pA和pB沿着各自行程，每次各走一步，一定会相等。要么相遇在交点，要么都完成各自行程后都指向nullptr。
*/
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};