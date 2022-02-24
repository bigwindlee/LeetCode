#pragma once
#include <queue>
#include <vector>
using namespace std;

/*
����������ͼ����������ģ��������ͼ����ʾ�γ�֮���������ϵ��
prerequisites[i] = [a, b] ����ʾ���Ҫѧϰ�γ� a �� ���� ��ѧϰ�γ�  b ������ͼ�� b -> a ��
���ڽӱ�edges��ʾ����ͼ����edges[b].push_back(a)
*/

#define DEPTH_FIRST_SEARCH

#ifdef DEPTH_FIRST_SEARCH
class Solution_0207 {
private:
    vector<vector<int>> edges; // �ڽӱ��������򣩣�edges[i]�洢���д�i������ָ��Ľڵ㣬Ҳ��������������i�Ľڵ㡣
    vector<int> visited; // ������飬�Խڵ�i���б�ǣ�0 - δ�����ʣ�1 - ���ڼ�⣻2 - ��i�ڵ�����ļ����ϣ�δ���ֻ�·��
    bool valid = true; // false��ʾ���ڻ�·���γ̲�����ɡ�

public:
    // ��ʼ״̬�����еĽڵ�״̬��Ϊ0��δ�����ʣ�����ѡһ���ڵ㣬���ż�ͷ����ָ��dfs����������ڻ�·����ô���еġ���һ������Ӧ����0��
    // Ҳֻ��0״̬����dfsǰ�������1����ʾ�ѵ�ǰ�ڵ�������ڱ�����������
    // ���dfs��ǰ�������У�����һ����һ���ڵ��״̬Ϊ1�����ڱ���⣩����ʾ�����˻�·��
    // �κ�һ���ڵ㣬��������ڻ�·�ϣ���ôһ�������״μ������ڵ�ʱ���ֻ�·�����״̬Ϊ2����ʾ�Ѿ������ˣ�������ڵ�����϶�û�л�·��
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
        visited[u] = 2; // ��ʾ��u����������·����������⣬û�з��ֻ�·����һ��dfs����״̬Ϊ2�Ľڵ㣬�����衣
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // �����ڽӱ�ͱ������
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }

        // �����ڵ㣬��ÿ���ڵ�ִ��dfs��
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
    vector<vector<int>> edges; // �ڽӱ�edges[i]��ʾi�ڵ�ġ���һ�������ϡ�
    vector<int> indeg; // ���indegree���ж��ٸ���ͷָ���Լ���Ҳ�����ж���ڵ���Լ���������һ���������Ϊ0��ʾû�нڵ���Լ�������һ��������ô�Լ����ǿ��ܵġ���һ������

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // �����ڽӱ���������顣
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        // ֻ�����Ϊ0�Ľڵ�ſ�������У���ʾ���ſε�ǰ�������κ������γ̣����Է��ʡ�
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0; // ��ǰ�Ѿ����ʵĽڵ������
        while (!q.empty()) {
            ++visited;

            // �ѵ�ǰ���ʵĽڵ㵯������
            int u = q.front();
            q.pop();

            // ������ǰ���ʽڵ�ġ���һ��������Ϊ��ǰ�ڵ㱻�����ˣ��������ſΣ������С���һ��������ȼ�1���������Ӽ�1���������Ϊ0��������С�
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