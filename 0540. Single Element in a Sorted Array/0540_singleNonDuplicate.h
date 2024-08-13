#pragma once
#include <vector>
using namespace std;

/*
540. ���������еĵ�һԪ��
����һ������������ɵ��������飬����ÿ��Ԫ�ض���������Σ�Ψ��һ����ֻ�����һ�Ρ�
�����ҳ�������ֻ����һ�ε��Ǹ�����
����ƵĽ�������������� O(log n) ʱ�临�ӶȺ� O(1) �ռ临�Ӷȡ�

˼·������
������������ͬ���֡�����Ҫ���뵽��������
*/
class Solution_0540 {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int ans = 0;
        for (int i : nums) {
            ans ^= i; // ������������ͬ�����֣�ʹ��һԪ�ر�¶������
        }
        return ans;
    }
};