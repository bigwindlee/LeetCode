#pragma once
#include "ListNode.h"

/*
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
*/

/*
思路分析：链表指针操作技巧
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode dummyHead, *p = &dummyHead;
        // list1和list2分别指向2个待比较的节点，较小的会连接在p指针所指节点的后面；
        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            } else {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
        p->next = list1 ? list1 : list2;
        return dummyHead.next;
    }
};