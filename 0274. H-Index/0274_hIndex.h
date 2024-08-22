#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
* 274. H 指数
给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
根据维基百科上 h 指数的定义：h 代表“高引用次数” ，一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，并且 至少 有 h 篇论文被引用次数大于等于 h 。
如果 h 有多种可能的值，h 指数 是其中最大的那个。

思路分析：
题目表达晦涩，说人话就是：数组中有h个不小于h的值，求最大的h。
只需将数组降序排列，挨个比较元素值和元素下标。
*/
class Solution_0274 {
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.rbegin(), citations.rend());
        int i;
        for (i = 0; i < citations.size() && citations[i] > i; ++i)
            ;
        return i;
    }
};