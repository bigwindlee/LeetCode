#pragma once
#include "ListNode.h"

/*
2. 两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

思路分析：
本题基本上是链表的常规操作，要注意以下几点：
1. 引入dummy节点，避免在循环中单独处理链表的头节点；
2. 使用carry记录进位，并把carry加入到循环条件，避免跳出循环后单独处理最高位的进位；
3. 把2个数字和carry自己都累加到carry里，避免引入新的变量sum，可使代码简洁；
4. 使用三元运算符（?:），可使代码简洁；
5. 2个数字相加的和可能是2位数，获取低位数字：carry%10，获取高位数字：carry/10
*/
class Solution_0002 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode dummy;
        ListNode* p = &dummy;
        int carry = 0;
        // 把进位carry加入到循环条件中，避免跳出循环后单独处理最高位的进位。
        while (l1 || l2 || carry) {
            // 代码简洁：把2个数字以及carry都加到carry变量中，避免引入一个新的变量。
            carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            p->next = new ListNode(carry % 10);
            p = p->next;

            // 迭代：准备下次循环
            carry /= 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};