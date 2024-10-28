#pragma once
#include <vector>
using namespace std;

/*
54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/

/*
核心要点：
    1）方向的定义，转向的技巧；
    2）元素个数递减作为循环条件；
    3）元素没收集完毕的时候，最多发生一次转向，就能得到一个有效坐标！
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> ans;
        vector<vector<int>> direct { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; // direction definition
        int di = 0; // direction index
        int m = matrix.size(), n = matrix[0].size(), count = m * n;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int i = 0, j = 0;
        while (count--) { // 元素个数递减作为循环条件
            ans.push_back(matrix[i][j]);
            visited[i][j] = true; // 标记已访问
            int ni = i + direct[di][0], nj = j + direct[di][1]; // 按当前方向计算下一步坐标
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || visited[ni][nj]) { // 坐标越界，或者已访问
                di = (di + 1) % direct.size(); // 转向的技巧
                ni = i + direct[di][0];
                nj = j + direct[di][1];
            }
            i = ni;
            j = nj;
        }
        return ans;
    }
};