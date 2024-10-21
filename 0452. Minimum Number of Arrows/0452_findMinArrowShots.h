#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
452. 用最少数量的箭引爆气球
有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。
一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
*/

/*
思路分析：排序
把线段排序，默认按照左端点升序；
第一支箭从末尾线段的左端点射出（要干掉末尾线段，又要尽量往左）；凡是和这个左端点有交集的都要一起引爆！

*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end()); // 排序很关键；默认左端点升序；
        int ans = 0;
        while (!points.empty()) {
            int left = points.back()[0]; // 末尾线段左端点
            points.pop_back();
            while (!points.empty() && points.back()[1] >= left) { // 左邻线段有交集，一起引爆！
                points.pop_back();
            }
            ++ans;
        }
        return ans;
    }
};