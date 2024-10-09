#pragma once
#include <queue>
using namespace std;

/*
215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

/*
思路分析：
TopK问题，优先级队列的经典应用场景。
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> q; // 此处需要小顶堆
        for (int num : nums) {
            if (q.size() < k) { // 名额未满，直接入堆。
                q.push(num);
            } else {
                if (num > q.top()) { // 名额已满，比堆顶的大，就把堆顶元素挤出来。
                    q.pop();
                    q.push(num);
                }
            }
        }
        return q.top();
    }
};