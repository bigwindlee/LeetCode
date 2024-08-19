#pragma once
#include <map>
#include <stack>
#include <vector>
using namespace std;

/*
853. 车队
在一条单行道上，有 n 辆车开往同一目的地。目的地是几英里以外的 target 。
给定两个整数数组 position 和 speed ，长度都是 n ，其中 position[i] 是第 i 辆车的位置， speed[i] 是第 i 辆车的速度(单位是英里/小时)。
一辆车永远不会超过前面的另一辆车，但它可以追上去，并以较慢车的速度在另一辆车旁边行驶。
车队 是指并排行驶的一辆或几辆汽车。车队的速度是车队中 最慢 的车的速度。
即便一辆车在 target 才赶上了一个车队，它们仍然会被视作是同一个车队。
返回到达目的地的车队数量 。

思路分析：（单调栈）
因为不能超车，所以由近及远的方向，每辆车的实际到达时间是一个递增数列。
如果后车的`无遮挡到达时间`比前车短，那么按照规则，后车会加入前车形成车队，降速到前车的速度一并行驶。
由近及远的方向，把每辆车的无遮挡到达时间逐一入栈（单调递增栈）；
如果待入栈元素（后车）`不大于`栈顶元素（前车），则前车构成遮挡，待入栈元素不能入栈。
数据结构映射为`单调递增栈`，非常合适！

难点：
数据结构的映射（单调栈）
*/
class Solution_0853 {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        map<int, int, greater<int>> ps; // 因为由近及远，所以降序排列。
        for (int i = 0; i < position.size(); i++) {
            ps[position[i]] = speed[i];
        }
        stack<double> stk;
        for (auto& [pos, spd] : ps) {
            double time = static_cast<double>(target - pos) / spd;
            if (stk.empty() || time > stk.top()) {
                // 后车的无遮挡达到时间更长，才能避免加入前车。
                stk.push(time);
            }
        }
        return stk.size();
    }
};
