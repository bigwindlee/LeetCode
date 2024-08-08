#pragma once
#include <queue>
#include <vector>
using namespace std;

/*
1046. ���һ��ʯͷ������
��һ��ʯͷ��ÿ��ʯͷ������������������
ÿһ�غϣ�����ѡ������ ���ص� ʯͷ��Ȼ������һ����顣����ʯͷ�������ֱ�Ϊ x �� y���� x <= y����ô����Ŀ��ܽ�����£�
��� x == y����ô����ʯͷ���ᱻ��ȫ���飻
��� x != y����ô����Ϊ x ��ʯͷ������ȫ���飬������Ϊ y ��ʯͷ������Ϊ y-x��
������ֻ��ʣ��һ��ʯͷ�����ش�ʯͷ�����������û��ʯͷʣ�£��ͷ��� 0��

˼·�����������ȼ�����/�󶥶ѣ�
����������ѡ������ ���ص� ʯͷ������Ҫ���뵽�󶥶ѡ�
���ȼ����У��󶥶ѣ���Ӧ�ã���̬���������Զ�ѡȡ��ֵ��
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> q; // Ĭ�ϴ󶥶�
        for (int i : stones) {
            q.push(i);
        }
        while (q.size() > 1) { // �������ٻ���2��ʯͷ
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (x < y) {
                q.push(y - x);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};