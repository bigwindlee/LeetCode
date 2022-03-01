#pragma once
#include <vector>
using namespace std;

#define DEPTH_FIRST_SEARCH
//#define BREADTH_FIRST_SEARCH

#ifdef DEPTH_FIRST_SEARCH

class Solution_0210 {
private:
    // 存储有向图（下一跳表）
    vector<vector<int>> edges;

    // 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成
    vector<int> visited;

    // 用数组来模拟栈，下标 0 为栈底，n-1 为栈顶
    vector<int> result;

    // 判断有向图中是否有环
    bool valid = true;

public:
    void dfs(int u)
    {
        // dfs进入到u节点，将节点标记为「搜索中」
        visited[u] = 1;

        // 遍历所有的下一跳节点，发现环路立即停止。
        // 下一跳状态为0则dfs前进，为1则表示发现环路，为2则节点搜索完毕，dfs受阻。
        for (int v : edges[u]) {
            if (visited[v] == 0) { // dfs前进
                dfs(v);
                if (!valid) {
                    return;
                }
            } else if (visited[v] == 1) { // 发现环路
                valid = false;
                return;
            }
        }

        // 走到这里表示u节点没有下一跳，或者下一跳已经搜索完毕（完成标记和入栈），于是标记u节点并入栈。
        visited[u] = 2;

        // 难点：这里求拓扑排序需要一些逆向思维。dfs搜索链条末端的节点，表示已经没有下一跳，或者下一跳已摘除，
        // 此时u节点可认为是最后一门课程，没有别的课程依赖它。
        // 因此把u节点入栈的顺序反过来，就得到一种合法的拓扑排序。
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        // 每次挑选一个「未搜索」的节点，开始进行深度优先搜索
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (!valid) {
            return {};
        }
        // 如果没有环，那么就有拓扑排序
        // 注意下标 0 为栈底，因此需要将数组反序输出
        reverse(result.begin(), result.end());
        return result;
    }
};
#endif

#ifdef BREADTH_FIRST_SEARCH

class Solution_0210 {
private:
    vector<vector<int>> edges;
    vector<int> indeg;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> ans;

        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);

            for (int v : edges[u]) {
                if (--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (ans.size() == numCourses) {
            return ans;
        }

        return vector<int>();
    }
};

#endif
