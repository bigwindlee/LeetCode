#pragma once
#include <queue>
#include <vector>
using namespace std;

/* -------------------------------------------------------------------------------------------------------------------
871. 最低加油次数
汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。
沿途有加油站，用数组 stations 表示。其中 stations[i] = [positioni, fueli] 表示第 i 个加油站位于出发位置东面 positioni 英里处，并且有 fueli 升汽油。
假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。它每行驶 1 英里就会用掉 1 升汽油。当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。
为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1 。
注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。
*/

/* -------------------------------------------------------------------------------------------------------------------
思路分析：优先级队列

核心要点：
  ● 在可达范围内选取最多油的station，停一次车加一次油，很有可能是不够的，不足以支撑到下一跳；这也是为什么必须把沿途的加油站都记住；
  ● 把startFuel的意义转化为`总的加油量`，用`总的加油量`和`绝对距离`进行比较，避免计算油箱剩余和相对距离！
  ● 把终点也作为一个加油站，加入到stations，便于在遍历stations时统一处理！
*/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        stations.push_back({ target, 0 }); // 技巧：在遍历stations时统一处理
        int n = stations.size();

        priority_queue<int> q; // 记住沿途的加油站
        for (auto& station : stations) {
            // 用总的加油量和绝对距离进行比较，避免计算油箱剩余和相对距离！
            while (startFuel < station[0]) {
                // 当前总加油量不能到达下一站
                if (q.empty()) { // 无油可加
                    return -1;
                }
                startFuel += q.top(); // 优先加最多的油
                q.pop();
            }
            q.push(station[1]);
        }
        return n - q.size();
    }
};