#pragma once
#include <queue>
#include <vector>
using namespace std;

/*
1046. 最后一块石头的重量
有一堆石头，每块石头的重量都是正整数。
每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

思路分析：（优先级队列/大顶堆）
见到“从中选出两块 最重的 石头”，就要联想到大顶堆。
优先级队列（大顶堆）的应用，动态数据流中自动选取最值。
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> q; // 默认大顶堆
        for (int i : stones) {
            q.push(i);
        }
        while (q.size() > 1) { // 堆中至少还有2块石头
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (x < y) {
                q.push(y - x);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};