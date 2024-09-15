#pragma once
#include "ListNode.h"

/*
142. 环形链表 II
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
不允许修改 链表。
*/

/*
思路分析：Floyd 判圈算法（也叫快慢指针方法）
  ● 慢指针每次走一步，快指针每次走两步，如果链表存在环，那么快慢指针一定会相遇；
  ● 相遇后，快指针回到起点并降速（每次一步），那么快慢指针一定相遇在环的入口（入环的第一个节点）。
*/
class Solution {
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) { // fast在前面开路，不必对slow判空。
            slow = slow->next;
            fast = fast->next->next;
            while (slow == fast) { // 存在环则一定相遇
                slow = head; // 相遇后，任意指针回到起点
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next; // 快指针降速
                }
                return slow; // 再次相遇必然是环的入口
            }
        }
        return nullptr;
    }
};