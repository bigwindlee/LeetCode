#pragma once
#define _USE_MATH_DEFINES
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

/*
1610. 可见点的最大数目
给你一个点数组 points 和一个表示角度的整数 angle ，你的位置是 location ，其中 location = [posx, posy] 且 points[i] = [xi, yi] 都表示 X-Y 平面上的整数坐标。
最开始，你面向东方进行观测。你 不能 进行移动改变位置，但可以通过 自转 调整观测角度。换句话说，posx 和 posy 不能改变。你的视野范围的角度用 angle 表示， 
这决定了你观测任意方向时可以多宽。设 d 为你逆时针自转旋转的度数，那么你的视野就是角度范围 [d - angle/2, d + angle/2] 所指示的那片区域。
对于每个点，如果由该点、你的位置以及从你的位置直接向东的方向形成的角度 位于你的视野中 ，那么你就可以看到它。
同一个坐标上可以有多个点。你所在的位置也可能存在一些点，但不管你的怎么旋转，总是可以看到这些点。同时，点不会阻碍你看到其他点。
返回你能看到的点的最大数目。

思路分析：
探照灯在旋转的过程中，同时能看见的最多点数。

在这个问题中，滑动窗口算法的应用可以分解为以下几个步骤：
计算角度：
    对于给定的每个点，计算其相对于观察点 location 和向东方向（x 轴正方向）的角度。
    使用 atan2(y - posY, x - posX) 可以得到这个角度，然后将弧度转换为度。
处理边界问题：
    由于角度的范围是循环的（0度和360度实际上是同一个方向），我们可以将角度数组复制并扩展，例如原有角度为 [10, 20, 30]，
    可以扩展为 [10, 20, 30, 370, 380, 390]。这样做是为了方便处理视角跨越360度的情况。
排序和滑动窗口：
    对扩展后的角度数组进行排序。
    使用两个指针 start 和 end 表示当前窗口的起始和结束位置。初始化时两个指针都指向数组的起始位置。
    移动 end 指针扩大窗口直到窗口内的角度范围大于 angle。
    一旦窗口内角度范围超过 angle，开始移动 start 指针缩小窗口直到窗口内的角度范围再次小于或等于 angle。
    在每一步操作中记录窗口内最多包含的点的数量。
返回结果：
    返回在任何可能的视角下观察到的最大点的数量。

难点：
1. 和探照灯原点坐标重合的点总是可见，要特殊处理，而不进入angles数组；
2. 为处理边界问题（探照灯的视野跨越x轴，同时处于1和4象限），复制并平移角度列表。

知识点：
double atan2(double y,double x) 返回的是原点至点(x,y)的方位角，即与 x 轴的夹角。返回值的单位为弧度，取值范围为（-π, π]。
结果为正表示从 X 轴逆时针旋转的角度，结果为负表示从 X 轴顺时针旋转的角度。若要用度表示反正切值，请将结果再乘以 180/π。
*/
class Solution_1610 {
public:
    int visiblePoints(vector<vector<int>>& points, int angle,
        vector<int>& location)
    {
        vector<double> angles;
        int sameCount = 0;
        int posX = location[0], posY = location[1];

        // 和探照灯所在坐标重合的点始终可见，无论探照灯怎么旋转。
        // 直接计入sameCount，不要进入angles数组。
        for (const vector<int>& p : points) {
            int x = p[0], y = p[1];
            if (x == posX && y == posY) {
                sameCount++; // 相同点总是可见
                continue;
            }
            // 计算弧度并转换为角度
            double ang = atan2(y - posY, x - posX) * 180 / M_PI;
            angles.push_back(ang);
        }

        sort(angles.begin(), angles.end()); // 排序所有角度
        int n = angles.size();
        // 为处理边界问题，复制并平移角度列表
        for (int i = 0; i < n; ++i) {
            angles.push_back(angles[i] + 360);
        }

        int maxCount = 0;
        // 双指针滑动窗口找到最大可见点
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < 2 * n && angles[j] <= angles[i] + angle) {
                ++j;
            }
            maxCount = max(maxCount, j - i);
        }

        return maxCount + sameCount; // 添加总是可见的点
    }
};