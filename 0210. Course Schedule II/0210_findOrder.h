#pragma once
#include <vector>
using namespace std;

#define DEPTH_FIRST_SEARCH
//#define BREADTH_FIRST_SEARCH

#ifdef DEPTH_FIRST_SEARCH

class Solution_0210 {
private:
    // �洢����ͼ����һ����
    vector<vector<int>> edges;

    // ���ÿ���ڵ��״̬��0=δ������1=�����У�2=�����
    vector<int> visited;

    // ��������ģ��ջ���±� 0 Ϊջ�ף�n-1 Ϊջ��
    vector<int> result;

    // �ж�����ͼ���Ƿ��л�
    bool valid = true;

public:
    void dfs(int u)
    {
        // dfs���뵽u�ڵ㣬���ڵ���Ϊ�������С�
        visited[u] = 1;

        // �������е���һ���ڵ㣬���ֻ�·����ֹͣ��
        // ��һ��״̬Ϊ0��dfsǰ����Ϊ1���ʾ���ֻ�·��Ϊ2��ڵ�������ϣ�dfs���衣
        for (int v : edges[u]) {
            if (visited[v] == 0) { // dfsǰ��
                dfs(v);
                if (!valid) {
                    return;
                }
            } else if (visited[v] == 1) { // ���ֻ�·
                valid = false;
                return;
            }
        }

        // �ߵ������ʾu�ڵ�û����һ����������һ���Ѿ�������ϣ���ɱ�Ǻ���ջ�������Ǳ��u�ڵ㲢��ջ��
        visited[u] = 2;

        // �ѵ㣺����������������ҪһЩ����˼ά��dfs��������ĩ�˵Ľڵ㣬��ʾ�Ѿ�û����һ����������һ����ժ����
        // ��ʱu�ڵ����Ϊ�����һ�ſγ̣�û�б�Ŀγ���������
        // ��˰�u�ڵ���ջ��˳�򷴹������͵õ�һ�ֺϷ�����������
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        // ÿ����ѡһ����δ�������Ľڵ㣬��ʼ���������������
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (!valid) {
            return {};
        }
        // ���û�л�����ô������������
        // ע���±� 0 Ϊջ�ף������Ҫ�����鷴�����
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
