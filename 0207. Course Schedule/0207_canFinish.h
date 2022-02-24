#pragma once
#include <queue>
#include <vector>
using namespace std;

/*
本质是有向图的搜索。建模：用有向图来表示课程之间的依赖关系。
prerequisites[i] = [a, b] ，表示如果要学习课程 a 则 必须 先学习课程  b ；有向图上 b -> a 。
用邻接表edges表示有向图，则edges[b].push_back(a)
*/

#define DEPTH_FIRST_SEARCH

#ifdef DEPTH_FIRST_SEARCH
class Solution_0207 {
private:
    vector<vector<int>> edges; // 邻接表（搜索方向），edges[i]存储所有从i出发所指向的节点，也就是所有依赖于i的节点。
    vector<int> visited; // 标记数组，对节点i进行标记：0 - 未曾访问；1 - 正在检测；2 - 从i节点出发的检测完毕，未发现环路。
    bool valid = true; // false表示存在环路，课程不能完成。

public:
    // 初始状态，所有的节点状态都为0（未曾访问），任选一个节点，沿着箭头方向指向dfs，如果不存在环路，那么所有的“下一跳”都应该是0，
    // 也只有0状态能让dfs前进，变成1，表示把当前节点加入正在被检测的链条。
    // 如果dfs在前进过程中，发现一个下一跳节点的状态为1（正在被检测），表示出现了环路！
    // 任何一个节点，如果存在于环路上，那么一定会在首次检测这个节点时发现环路。如果状态为2，表示已经检测过了，从这个节点出发肯定没有环路。
    void dfs(int u)
    {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            } else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2; // 表示从u出发的所有路径都经过检测，没有发现环路。下一轮dfs遇到状态为2的节点，会遇阻。
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // 创建邻接表和标记数组
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }

        // 遍历节点，对每个节点执行dfs。
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};

#else
class Solution_0207 {
private:
    vector<vector<int>> edges; // 邻接表，edges[i]表示i节点的“下一跳”集合。
    vector<int> indeg; // 入度indegree。有多少个箭头指向自己，也就是有多个节点把自己当做“下一跳”。入度为0表示没有节点把自己当“下一跳”，那么自己就是可能的“第一跳”。

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // 构建邻接表，和入度数组。
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        // 只有入度为0的节点才可以入队列，表示这门课当前不依赖任何其它课程，可以访问。
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0; // 当前已经访问的节点个数。
        while (!q.empty()) {
            ++visited;

            // 把当前访问的节点弹出队列
            int u = q.front();
            q.pop();

            // 遍历当前访问节点的“下一跳”，因为当前节点被访问了（上了这门课），所有“下一跳”的入度减1（依赖因子减1），如果减为0，则入队列。
            for (int v : edges[u]) {
                if (--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};
#endif