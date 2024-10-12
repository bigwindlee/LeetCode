#pragma once
#include <algorithm>
#include <array>
#include <set>
#include <vector>
using namespace std;

/*
218. 天际线问题
城市的 天际线 是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回 由这些建筑物形成的 天际线 。
每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti] 表示：
  ● lefti 是第 i 座建筑物左边缘的 x 坐标。
  ● righti 是第 i 座建筑物右边缘的 x 坐标。
  ● heighti 是第 i 座建筑物的高度。
你可以假设所有的建筑都是完美的长方形，在高度为 0 的绝对平坦的表面上。
天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序 。关键点是水平线段的左端点。列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0 ，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。
注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]
*/

/*
思路分析：扫描线
关键点是一个水平线段的左端点，我们注意到当 最大高度发生变化时，一定会遇到一个新的关键点。（可以想象一条直线永远压着最高的楼，高度发生变化时，
天际线一定会产生一条新的线段起点，即为一个关键点。）

重要技巧：
将左边界的高度设置为负数，这样可以区分左右边界，同时保证排序后：
  ● 左右边界重叠时，左边界优先，这样可以及时更新当前最大高度；这样可避免高度降为0，生成一个不正确的“关键点”；
  ● 左边界重叠时，高楼优先，这样可以正确更新当前最大高度；
  ● 右边界重叠时，矮楼优先，这样在erase矮楼右边界高度时，不改变当前最大高度；


参考答案：
https://leetcode-cn.com/problems/the-skyline-problem/solution/tian-ji-xian-gen-ju-zuo-you-bian-jie-pai-apj3/
*/
class Solution_0218 {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<vector<int>> ans;
        multiset<pair<int, int>> events; // 有序（默认升序），允许重复元素。
        for (auto& b : buildings) {
            // 正负用于判别是左边界还是右边界，同时保证排序后：
            // 左边界相同时，最高的楼排在前面，insert的一定是相同左边界中最大的高度
            // 右边界相同时，最低的楼排在前面，erase的时候不会改变最大高度（改变意味着生成“关键点”）
            events.insert({ b[0], -b[2] }); // 左边界
            events.insert({ b[1], b[2] }); // 右边界
        }

        multiset<int> height; // 维护当前最大高度
        height.insert(0);
        int pre = 0; // 上一次的最大高度
        for (auto& [x, h] : events) {
            if (h < 0) { // 左边界
                height.insert(-h);
            } else { // 右边界
                height.erase(height.find(h)); // 不能根据值来删除，否则会把重复的值全部删掉
            }

            int cur = *height.rbegin(); // 当前最大高度
            // 最大高度发生改变，一定是一个“关键点”，即一个水平线段的左端点
            if (cur != pre) {
                ans.push_back({ x, cur });
                pre = cur;
            }
        }
        return ans;
    }
};