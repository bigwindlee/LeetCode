#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
*/

/*
思路分析：
vector数据结构的特点是常数时间内的随机访问，但是删除元素很慢，每次删除都可能引起内存中大量元素的移动。
所以不要考虑原地合并，而是应该枚举intervals中的每个线段，取挑战ans的末尾线段。
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end()); // 默认按照字典序进行排序
        vector<vector<int>> ans;
        for (auto& i : intervals) {
            if (!ans.empty() && i[0] <= ans.back()[1]) { // 枚举intervals，挑战ans末尾线段；
                ans.back()[1] = max(ans.back()[1], i[1]); // 合并，改写右边界；
            } else {
                ans.emplace_back(i); // 不合并，独立线段插入到末尾；
            }
        }
        return ans;
    }
};