#pragma once
#include "ListNode.h"
#include <algorithm>
using namespace std;
/*
1721. 交换链表中的节点
给你链表的头节点 head 和一个整数 k 。
交换 链表正数第 k 个节点和倒数第 k 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。

思路分析：
本题要充分利用“92. 反转链表 II”的成果，做2次链表的区间逆转。
记第k个节点和倒数第k个节点的编号是left, right。直接利用leetcode 92题的成果，对left和right构成的区间做逆转。
然后区间的左右边界分别内收一个节点，也就是++left, --right。然后对新的子区间做一次逆转。
新的子区间经过了2次逆转，相当于恢复了原来的顺序，而第k个和倒数第k个节点交换了位置。
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        // 计算链表长度
        ListNode* pc = head;
        int size = 0;
        while (pc) {
            ++size;
            pc = pc->next;
        }

        // 第k个和倒数第k个节点构成的区间，做一次逆转。
        int left = min(k, size - k + 1), right = max(k, size - k + 1);
        head = reverseBetween(head, left, right);
        if (++left < --right) { // 区间左右边界分别内收，并针对新的子区间再做一次逆转。
            head = reverseBetween(head, left, right);
        }
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (!head || !head->next || left == right) {
            return head;
        }
        ListNode dummyNode(-1, head);
        ListNode* dummy = &dummyNode;
        ListNode *p = dummy, *q, *r;
        int count = right - left;

        // 固定节点p/q就位
        while (--left) {
            p = p->next;
        }
        q = p->next;

        // 利用q对r进行定位，并把r摘除、搬移到p节点的后面。
        while (count--) {
            // 定位r并摘除
            r = q->next;
            q->next = r->next;

            // 把r搬移到p的后面
            r->next = p->next;
            p->next = r;
        }
        return dummy->next;
    }
};