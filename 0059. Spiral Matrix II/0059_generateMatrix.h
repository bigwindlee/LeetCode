#pragma once
#include <vector>
using namespace std;

/*
59. �������� II
����һ�������� n ������һ������ 1 �� n^2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е� n x n �����ξ��� matrix ��

˼·������
�۲������Ԫ�ذ�˳ʱ����ת���˶����ɣ��ö�ά���鶨���4�����򡣾����ԭ�������Ͻǣ�������������(y+1)��������������(x+1)��
ת��ļ��ɣ�di = (++di) % 4;

֪ʶ�㣺
1. ��ά��̬����Ķ��壺vector<vector<int>> ans(n, vector<int>(n, 0));
2. ��ά��̬����Ķ��壺int direct[][2]
3. ת��ļ��ɣ�di = (++di) % 4;
*/
class Solution_0059 {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0)); // ���嶯̬��ά����
        int direct[][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; // ���徲̬��ά���鲻��vector
        int di = 0; // direction index����ʾ��ǰ����
        int i = 0, x = 0, y = 0; // i�������������֣����n*n��(x, y)��Ҫ�������ꡣ
        while (++i <= n * n) {
            ans[x][y] = i;
            // ��������ԭ����ǰ���������Ƿ���Ч
            int x1 = x + direct[di][0];
            int y1 = y + direct[di][1];
            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || ans[x1][y1] != 0) {
                di = (++di) % 4; // ������������������Ѿ������ģ�����ת��
            }
            x += direct[di][0];
            y += direct[di][1];
        }
        return ans;
    }
};