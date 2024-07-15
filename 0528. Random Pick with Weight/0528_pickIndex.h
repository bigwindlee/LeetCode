#pragma once
#include <vector>
using namespace std;

/*
528. ��Ȩ�����ѡ��
����һ�� �±�� 0 ��ʼ ������������ w ������ w[i] ����� i ���±��Ȩ�ء�
����ʵ��һ������ pickIndex �������� ����� �ӷ�Χ [0, w.length - 1] �ڣ��� 0 �� w.length - 1��ѡ��������һ���±ꡣѡȡ�±� i �� ���� Ϊ w[i] / sum(w) ��
���磬���� w = [1, 3]����ѡ�±� 0 �ĸ���Ϊ 1 / (1 + 3) = 0.25 ������25%������ѡȡ�±� 1 �ĸ���Ϊ 3 / (1 + 3) = 0.75������75%����

˼·������ǰ׺�� + ���ֲ���
*/
class Solution {
public:
    Solution(vector<int>& w) { this->w = w; }

    int pickIndex()
    {
        int n = w.size();
        vector<int> preSum(n); // ǰ׺������
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += w[i];
            preSum[i] = sum;
        }
        int r = rand() % sum + 1; // ��������ֲ����䣺[1, sum]
        // �۰���ң�Ϊr�ҵ����ʵķ��䣨�䷿��ž���Ҫ���ص��±꣩
        // r���ڵķ���i����������preSum[i-1] < r && r <= preSum[i]
        // ���i-1���ڵĻ���
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (r > preSum[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    vector<int> w;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */