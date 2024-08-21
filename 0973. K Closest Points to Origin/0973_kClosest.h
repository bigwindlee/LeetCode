#pragma once
#include <queue>
#include <vector>
using namespace std;

/*
* 973. ��ӽ�ԭ��� K ����
����һ������ points ������ points[i] = [xi, yi] ��ʾ X-Y ƽ���ϵ�һ���㣬������һ������ k ��������ԭ�� (0,0) ����� k ���㡣
���ƽ��������֮��ľ����� ŷ����¾��루 ��(x1 - x2)2 + (y1 - y2)2 ����
����԰� �κ�˳�� ���ش𰸡����˵������˳��֮�⣬�� ȷ�� �� Ψһ �ġ�

˼·�����������ȼ����У�
����TopK���⣬�����ȼ����н����

֪ʶ�㣺
  - �Զ���ȽϺ�����ʹ��lambda���ʽ���������ͱ����`const`���Ρ�
  - �������ȼ�������Ҫ�������������������ͣ�Ҫ��decltype��ȡ�Զ��庯�������ͣ�
        template<
            class T,
            class Container = std::vector<T>,
            class Compare = std::less<typename Container::value_type>
        > class priority_queue;
  - ���ʶѶ�Ԫ��ʹ��top()��������Ҫ��queue��front()����������  
*/
class Solution_0973 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        // �Զ���ȽϺ�����lambda���ʽ��
        auto cmp = [](const vector<int>& p1, const vector<int>& p2) {
            return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);
        };
        // ע�ⶨ�����ȼ�������Ҫ������������Ҫ��decltype��ȡ�Զ��庯�������ͣ�
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q;
        for (auto& point : points) {
            if (q.size() < k) {
                q.push(point);
            } else {
                if (cmp(point, q.top())) { // �󶥶ѣ���̭��ģ����µĶ���С�ġ�
                    q.pop(); // ����Ϊk����Ϊ��TopK���⡣
                    q.push(point);
                }
            }
        }
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};