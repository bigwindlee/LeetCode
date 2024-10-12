#pragma once

#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

/*
850. 矩形面积 II
给你一个轴对齐的二维数组 rectangles 。 对于 rectangle[i] = [x1, y1, x2, y2]，其中（x1，y1）是矩形 i 左下角的坐标，（x2，y2）是矩形 i 左下角的坐标。
计算平面中所有 rectangles 所覆盖的 总面积 。任何被两个或多个矩形覆盖的区域应只计算 一次 。
返回 总面积 。因为答案可能太大，返回 1e9 + 7 的 模 。
*/

/* 
* 思路分析：扫描线算法
  ● 将矩形的左边界和右边界视为“事件”。每个矩形的左边界表示“进入”一个新的矩形，右边界表示“退出”当前的矩形。
  ● 通过扫描线从左到右处理这些边界，在每次处理边界时维护当前被扫描线覆盖的所有矩形的纵坐标范围。
  ● 当扫描线移动时，更新覆盖的矩形高度，并计算面积的变化。
*/
class Solution_0850 {
public:
    // 常见的大质数，在编程竞赛和算法中常用作模数。使用它的目的是防止整数溢出。
    const int MOD = 1e9 + 7;

    int rectangleArea(vector<vector<int>>& rectangles)
    {
        unordered_set<int> yset; // 用于Y坐标去重
        vector<vector<int>> events; // 将矩形的左边界和右边界视为“事件”
        for (auto& rect : rectangles) {
            yset.insert(rect[1]);
            yset.insert(rect[3]);
            events.push_back({ rect[0], rect[1], rect[3], 1 }); // 左边界事件
            events.push_back({ rect[2], rect[1], rect[3], -1 }); // 右边界事件
        }

        vector<int> Y(yset.begin(), yset.end());
        sort(Y.begin(), Y.end()); // Y坐标去重并排序
        sort(events.begin(), events.end()); // 对事件按x坐标排序

        // Y坐标线段标记数组；count[i]对应线段Y[i+1] - Y[i]的标记次数
        vector<int> count(Y.size() - 1);
        int prev_x = events[0][0];
        long long area = 0;

        for (auto& event : events) {
            int x = event[0], y1 = event[1], y2 = event[2], type = event[3];
            long long delta_y = 0; // 当前x对应的Y线段长度
            for (int i = 0; i < count.size(); ++i) {
                if (count[i] > 0) {
                    delta_y += Y[i + 1] - Y[i];
                }
                if (Y[i] >= y1 && Y[i + 1] <= y2) {
                    count[i] += type; // 刷新线段Y[i+1] - Y[i]的标记次数
                }
            }
            area = (area + (x - prev_x) * delta_y) % MOD; // 累加面积
            prev_x = x;
        }
        return area;
    }
};