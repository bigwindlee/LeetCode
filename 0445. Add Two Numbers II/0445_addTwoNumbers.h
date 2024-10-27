#pragma once
#include "ListNode.h"
#include <stack>
using namespace std;

/*
445. 两数相加 II
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
*/

/*
思路分析：双栈
凡是需要逆序操作的要考虑使用stack；
凡是模拟竖式加法的要是用一个变量carry保存“进位”；
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int> stk1, stk2;

        // l1链表的所有值压栈
        while (l1) {
            stk1.push(l1->val);
            l1 = l1->next;
        }

        // l2链表的所有值压栈
        while (l2) {
            stk2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0; // 进位
        ListNode* ans = nullptr;
        while (!stk1.empty() || !stk2.empty() || carry > 0) {
            if (!stk1.empty()) {
                carry += stk1.top();
                stk1.pop();
            }
            if (!stk2.empty()) {
                carry += stk2.top();
                stk2.pop();
            }
            ListNode* newNode = new ListNode(carry % 10, ans);
            ans = newNode;
            carry /= 10;
        }

        return ans;
    }
};
