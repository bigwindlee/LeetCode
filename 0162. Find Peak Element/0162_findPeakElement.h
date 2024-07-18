#pragma once
#include <vector>
using namespace std;

/*
162. Ѱ�ҷ�ֵ
��ֵԪ����ָ��ֵ�ϸ������������ֵ��Ԫ�ء�
����һ���������� nums���ҵ���ֵԪ�ز�������������������ܰ��������ֵ������������£����� �κ�һ����ֵ ����λ�ü��ɡ�
����Լ��� nums[-1] = nums[n] = -�� ��
�����ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨����������⡣

˼·������
����ʱ�临�Ӷ�Ϊ O(log n)����Ҫ���뵽���ֲ��ҷ���
û�����������Ҳ����ʹ�ö��ֲ��ҷ�����Ϊ��ĿҪ�󷵻ء��κ�һ����ֵ����ֻ��Ҫ�����ҵ��ھӱȽϼ��ɡ�
�ѵ㣺����left��right�ĵ�����rightҪ�������һ����leftҪ���Ҷ���һ����ֻ��һ������Ҳ�У������������ߣ���������ѭ����

�Ż��㣺
1. ���ȿ���ĩԪ���ǲ��Ƿ�ֵ������ɵ��ˣ����ǳ���ʱ�临�Ӷȣ�
*/
class Solution_0162 {
public:
    int findPeakElement(vector<int>& nums)
    {
        size_t n = nums.size();
        // �߽紦�������׽ڵ��ǲ��Ƿ�ֵ
        if (n == 1 || nums[0] > nums[1]) {
            return 0;
        }
        // �߽紦������ĩ�ڵ��ǲ��Ƿ�ֵ
        if (nums[n - 2] < nums[n - 1]) {
            return n - 1;
        }
        // �۰����
        size_t left = 1, right = n - 2, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid - 1] > nums[mid]) {
                right = mid - 1; // right�������һ��
            } else {
                left = mid + 1; // left���Ҷ���һ��
            }
        }
        return left; // ��ʱleft/right�غ�
    }
};