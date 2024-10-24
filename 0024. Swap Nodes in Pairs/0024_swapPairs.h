#pragma once
#include "ListNode.h"

/*
24. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/

/*
思路分析：递归处理链表问题
这是典型的用递归处理链表问题；只做前2个节点，后面的交给递归函数去做！
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode* ans = head->next; // 第2个节点
        ListNode* next = ans->next; // 第3个节点开始，交给递归函数去做
        ans->next = head;
        head->next = swapPairs(next);
        return ans;
    }
};