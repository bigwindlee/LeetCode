#pragma once
#include "ListNode.h"

/*
160. �ཻ����
���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null ��
��Ŀ���� ��֤ ������ʽ�ṹ�в����ڻ���
ע�⣬�������ؽ����������� ������ԭʼ�ṹ ��

˼·������
�����˼·�е��������һ���Խת�䡣
����A�ĳ��� + ����B�ĳ��� == ����B�ĳ��� + ����A�ĳ��ȡ�
ָ��pA������·���ǣ�����A������B��ָ��pB������·���ǣ�����B������A��
pA��pB�ܵ��г̳�������ȵġ�������ڽ��㣬�ӽ��㿪ʼ���г����غϵģ����pA��pBһ�������ڽ��㣡
��������ڽ��㣬pA��pB���������г̺󣬶�ָ��nullptr����ʱҲ����ȵġ�
����pA��pB���Ÿ����г̣�ÿ�θ���һ����һ������ȡ�Ҫô�����ڽ��㣬Ҫô����ɸ����г̺�ָ��nullptr��
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