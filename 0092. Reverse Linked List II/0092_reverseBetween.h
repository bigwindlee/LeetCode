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
92. ��ת���� II
���㵥�����ͷָ�� head ���������� left �� right ������ left <= right �����㷴ת��λ�� left ��λ�� right ������ڵ㣬���� ��ת������� ��

˼·������
 ������ת - ͷ�巨�������ȫ����ת��������ת��������ʹ��ͷ�巨��
 ͷ�巨��Ҫ3��ָ�룺
 p: �̶��ڵ㣬��Ҫ��ס��ת�����ǰһ���ڵ㣬��Ϊ��ת�������Ҫ���ӵ�����ڵ���档�����ת������׽ڵ㿪ʼ�أ����Ա�����Ҫһ��dummy�ڵ㡣 
 q: �̶��ڵ㣬ָ��ת����ĵ�һ���ڵ㣬ͨ��q�Ķ�λ�����ΰ�q����Ľڵ������p�ڵ�ĺ��档
 r: ��̬�ڵ㣬ͨ��q�Ķ�λ��ָ��q����������Ľڵ㡣ע��r�ǲ��뵽p�ĺ��棬�Լ���һ�εı������ڵ��ǰ�档
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

        // p ָ���λ���̶�ָ��ת�����ǰһ���ڵ㣻�������ڵ���뵽p�ĺ��档
        // qָ���λ���̶�ָ��ת����ĵ�һ���ڵ㣬ͨ��q�Ķ�λ�����ΰ�q����Ľڵ������p�ڵ�ĺ��档
        while (--left) {
            p = p->next;
        }
        q = p->next;

        // ����ͷ��
        while (count--) {
            r = q->next; // ��̬�ڵ㣬ָ��������ڵ㡣
            q->next = r->next; // ժ��r�ڵ�

            // ͨ��pָ��Ķ�λ����r�ڵ���뵽pָ��ĺ��档
            r->next = p->next;
            p->next = r;
        }
        return dummy->next;
    }
};