#pragma once
#include "ListNode.h"
#include <stdlib.h>

/*
382. 链表随机节点
给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点 被选中的概率一样 。

思路分析：
见到等概率的随机抽样，就要联想到“蓄水池抽样算法”！

算法要点：
1）确定蓄水池的大小k（随机抽样的样本个数）；数据流的前k个元素进入蓄水池；
2）对于数据流中的第n个元素(n > k)，生成一个[0, n)之间的随机数；也就是 rand() / 当前已遍历的元素个数；
   以数组为例，nums[i]是第i+1个元素，也就是当前子数组长度为i+1，随机数j = rand() / (i+1)；也就是j在[0, i]范围内；
3）判断生成的随机数j是否是蓄水池的有效下标，如果是，当前节点就进入蓄水池（把reservoir[j]替换出来）。
   更好的理解是：下标为i的元素，在当前遍历过的下标[0, i]中选取随机数，是否落在蓄水池中。
   前k个元素对应的随机数肯定落在蓄水池中，这也就是前k个元素要进入蓄水池的原因！

算法介绍：
蓄水池抽样（Reservoir Sampling）是一种用于从未知大小的数据流中随机抽取样本的算法。
这在处理大数据或流数据时特别有用，因为我们无法提前知道数据的总量，也无法一次性将所有数据加载到内存中。
该算法可以保证在数据流的任意时刻，每个数据被选中的概率相等。

蓄水池抽样算法核心思想提炼：
在所有遍历过的下标[0, i]范围内`等概率`随机生成j，如果j落入蓄水池reservoir，则nums[i]进入蓄水池，占据reservoir[j]。
*/
class Solution {
public:
    Solution(ListNode* head)
    {
        this->head = head;
    }

    int getRandom()
    {
        int ans = 0; // 蓄水池
        int count = 0; // 当前元素个数计数；
        for (ListNode* p = head; p != nullptr; p = p->next) {
            if (rand() % ++count == 0) { // 蓄水池的有效下标只有一个，就是0；
                ans = p->val; // 随机数是有效下标，则当前节点进入蓄水池
            }
        }
        return ans;
    }

    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
