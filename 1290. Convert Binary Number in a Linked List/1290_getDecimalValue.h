#pragma once
#include "ListNode.h"

/*
1290. 二进制链表转整数 （位运算）
给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。
请你返回该链表所表示数字的 十进制值 。

思路分析：
节点值对应内存中的比特位，遍历节点就是模拟在比特位在内存中左移的操作！
需要考虑的是，要不要单独的定位到首个非0比特？不需要！循环可以统一的处理！
*/
class Solution {
public:
    int getDecimalValue(ListNode* head)
    {
        int ans = 0;
        ListNode* cur = head;
        // 这个循环也适合处理前导0甚至全0的情况，
        // 所以无需单独定位首个`1`比特！
        while (cur) {
            ans <<= 1;
            ans |= cur->val;
            cur = cur->next;
        }
        return ans;
    }
};