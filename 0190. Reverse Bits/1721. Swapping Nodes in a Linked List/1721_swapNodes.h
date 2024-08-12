#pragma once
#include "ListNode.h"
#include <algorithm>
using namespace std;
/*
1721. ���������еĽڵ�
���������ͷ�ڵ� head ��һ������ k ��
���� ���������� k ���ڵ�͵����� k ���ڵ��ֵ�󣬷��������ͷ�ڵ㣨���� �� 1 ��ʼ��������

˼·������
����Ҫ������á�92. ��ת���� II���ĳɹ�����2�������������ת��
�ǵ�k���ڵ�͵�����k���ڵ�ı����left, right��ֱ������leetcode 92��ĳɹ�����left��right���ɵ���������ת��
Ȼ����������ұ߽�ֱ�����һ���ڵ㣬Ҳ����++left, --right��Ȼ����µ���������һ����ת��
�µ������侭����2����ת���൱�ڻָ���ԭ����˳�򣬶���k���͵�����k���ڵ㽻����λ�á�
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        // ����������
        ListNode* pc = head;
        int size = 0;
        while (pc) {
            ++size;
            pc = pc->next;
        }

        // ��k���͵�����k���ڵ㹹�ɵ����䣬��һ����ת��
        int left = min(k, size - k + 1), right = max(k, size - k + 1);
        head = reverseBetween(head, left, right);
        if (++left < --right) { // �������ұ߽�ֱ����գ�������µ�����������һ����ת��
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

        // �̶��ڵ�p/q��λ
        while (--left) {
            p = p->next;
        }
        q = p->next;

        // ����q��r���ж�λ������rժ�������Ƶ�p�ڵ�ĺ��档
        while (count--) {
            // ��λr��ժ��
            r = q->next;
            q->next = r->next;

            // ��r���Ƶ�p�ĺ���
            r->next = p->next;
            p->next = r;
        }
        return dummy->next;
    }
};