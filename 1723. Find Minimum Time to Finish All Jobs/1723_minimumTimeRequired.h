#pragma once
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

/*
1723. 完成所有工作的最短时间
给你一个整数数组 jobs ，其中 jobs[i] 是完成第 i 项工作要花费的时间。
请你将这些工作分配给 k 位工人。所有工作都应该分配给工人，且每项工作只能分配给一位工人。工人的 工作时间 是完成分配给他们的所有工作花费时间的总和。请你设计一套最佳的工作分配方案，使工人的 最大工作时间 得以 最小化 。
返回分配方案中尽可能 最小 的 最大工作时间 。
*/

/*
思路分析：经典回溯（m个球进入n个桶，要求最重的桶的重量尽可能的小。）
注意：
  - 降序排列可以尽快的触发剪枝；
  - 把每条搜索路径上最大的bucket放在参数中传递下去，到达叶子节点时就是一个合法的备选ans；
  - 搜索过程中发现当前搜索路径中，最大的bucket已经超出了合法的备选ans，立刻剪枝！
  - 回溯过程中发现当前bucket为空，那么没必要尝试下一个bucket，因为最终每个桶都至少有一个球（k <= jobs.length）。
*/
class Solution_1723 {
public:
    int minimumTimeRequired(vector<int>& jobs, int k)
    {
        int ans = INT_MAX;
        vector<int> bucket(k);

        // 把每条搜索路径上最大的bucket放在参数中传递下去，到达叶子节点的时候，表示完成了一次合法的配置，此时用最大的bucket挑战ans！
        function<void(int, int)> backtrack = [&](int idx, int maxtime) {
            if (idx == jobs.size()) {
                // 搜索路径到达叶子节点
                ans = min(ans, maxtime);
                return;
            }
            // 搜索过程中发现当前最大的bucket已经超出了合法的备选ans，立刻剪枝！
            if (maxtime >= ans) {
                return;
            }

            // 当前小球jobs[idx]尝试进入每一个bucket，对应着搜索的方向。
            for (int i = 0; i < bucket.size(); ++i) {
                if (bucket[i] + jobs[idx] >= ans)
                    continue;
                bucket[i] += jobs[idx]; // 尝试进入bucket[i]
                backtrack(idx + 1, max(maxtime, bucket[i]));
                bucket[i] -= jobs[idx]; // 撤销
                if (bucket[i] == 0)
                    return;
            }
        };

        sort(jobs.begin(), jobs.end(), greater<int>()); // 降序排列，尽快触发剪枝！
        backtrack(0, 0);
        return ans;
    }
};