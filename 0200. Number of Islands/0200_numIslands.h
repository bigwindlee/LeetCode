#pragma once
#include <vector>
using namespace std;

/*
200. ��������
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γɡ�
���⣬����Լ��������������߾���ˮ��Χ��

˼·������
���������Ǿ����dfs�������ص��ǣ�ÿ������·�����ж�������㡣

�ѵ㣺
  - �Զ�ά����ִ��dfs��ÿ������·�������ж������ġ�����Ч�������м��������ǵ����������

֪ʶ�㣺 
  - ������ʼ��һ����άvector���飿

�Ż�˼·��
  - �ռ��Ż�������grid��������ǣ������Ͳ���Ҫvisited�����ˡ����Ѿ����ʹ���'1'Ԫ������Ϊ'X'��
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // ÿ������·���ж�������㣬������Ч���ĸ�����
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, m, n, i, j, visited);
                    ++ans;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j, vector<vector<bool>>& visited)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        // 4�����������������ң�
        dfs(grid, m, n, i - 1, j, visited);
        dfs(grid, m, n, i + 1, j, visited);
        dfs(grid, m, n, i, j - 1, visited);
        dfs(grid, m, n, i, j + 1, visited);
    }
};