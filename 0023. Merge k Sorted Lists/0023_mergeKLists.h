#pragma once
#include "ListNode.h"
#include <queue>
#include <vector>
using namespace std;

/* ---------------------------------------------------------------------------------------------------------------
23. 合并 K 个升序链表
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
*/

/* ---------------------------------------------------------------------------------------------------------------
思路分析：优先级队列
把所有链表的头节点入队列，弹出最小的一个，并把它的后继节点拽进来。
*/

/* ---------------------------------------------------------------------------------------------------------------
知识点：
优先级队列需要自定义比较函数时的2种写法：

写法1：lambda表达式
作为对象，需要在实例化 priority_queue 时传入 lambda 实例对象，因为它是一个具体的实例对象。
---------------------------------------------------------------------------------------
auto cmp = [](ListNode* p1, ListNode* p2) {
    return p1->val > p2->val;
};
priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp); // 必须传入 cmp
---------------------------------------------------------------------------------------

写法2：仿函数functor
作为类型，它不需要传递任何额外参数，因为在 priority_queue 的模板参数中已经指定了 comp 类型，priority_queue 会自动创建一个 comp 对象并使用它。
---------------------------------------------------------------------------------------
struct comp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
priority_queue<ListNode*, vector<ListNode*>, comp> q;  // 不需要传入额外的参数
---------------------------------------------------------------------------------------


*/
struct cmp {
    // 小顶堆（默认大顶堆用less，所以小顶堆用greater）
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode dummy, *p = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (ListNode* node : lists) {
            if (node) {
                q.push(node);
            }
        }
        while (!q.empty()) {
            p->next = q.top(); // 连接在p指针后面
            q.pop();
            p = p->next; // p指针进一格，指向弹出节点
            if (p->next) { // 弹出最小的节点后，要把它的后继节点拽进来
                q.push(p->next);
            }
        }
        return dummy.next;
    }
};