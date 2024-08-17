#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
836. 矩形重叠
矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。矩形的上下边平行于 x 轴，左右边平行于 y 轴。
如果相交的面积为 正 ，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。
给出两个矩形 rec1 和 rec2 。如果它们重叠，返回 true；否则，返回 false 。

思路分析：
矩形在x轴、y轴的投影是2个线段。2个矩形重叠，意味着它们在x轴、y轴的投影产生的线段都有部分重合。

思路1：
怎样判断2个线段重合？如果重合，那么2个线段的长度之和，必然大于从最小x到最大x之间的长度：max(rec1[2], rec2[2]) - min(rec1[0], rec2[0])
这个解法要避免加减法的溢出。

思路2：
在坐标图上画一下就知道，如果2个线段重合，那么必须同时满足：任一线段的右边 > 另一线段的左边。
也就是说，只要发现有某一线段的右边 不大于 另一线段的左边，则认为线段没有部分重叠。
只要x轴或y轴的投影没有同时满足重合，则任务2个矩形没有重叠部分！
*/
class Solution_0836_1 {
public:
    // 常规解法：要避免加减法的溢出，这也是为什么要把(rec1[2] - rec1[0])挪到小于号的左边！
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        return (max(rec1[2], rec2[2]) - min(rec1[0], rec2[0]) - (rec1[2] - rec1[0]) < rec2[2] - rec2[0])
            && (max(rec1[3], rec2[3]) - min(rec1[1], rec2[1]) - (rec1[3] - rec1[1]) < rec2[3] - rec2[1]);
    }
};

class Solution_0836_2 {
public:
    // 技巧性解法：要理解2个线段部分重叠的条件：必须同时满足任一线段的右边 > 另一线段的左边。
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        // 题眼：只要发现有某一线段的右边 不大于 另一线段的左边，则认为线段没有重叠部分。
        return !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
    }
};