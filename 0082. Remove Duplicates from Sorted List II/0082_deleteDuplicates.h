#pragma once
#include "ListNode.h"

/*
82. 删除排序链表中的重复元素 II
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

思路分析：（递归）
递归是处理链表的一个重要方法，尤其是这种可以分解为规模较小但与原问题结构相似的子问题。
技巧是在递归函数体内只处理一个节点，剩下的节点交给递归函数去处理；而且要用子问题的解来表达当前节点（部分表达整体）。
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next); // 把当前节点摘出来，剩下的是一个结构相似的子问题，交给递归解决。
            return head;
        }
        // 此时确定有重复元素；跳过重复元素；
        while (head->next != nullptr && head->val == head->next->val) {
            head = head->next;
        }
        // 此时head指向重复元素的最后一个元素，后面的子集交给递归解决。
        return deleteDuplicates(head->next);
    }
};