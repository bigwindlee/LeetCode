#pragma once
#include <vector>
using namespace std;

/*
* 33. ������ת��������
�������� nums ���������У������е�ֵ ������ͬ ��
�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת��ʹ�����Ϊ [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]���±� �� 0 ��ʼ �����������磬 [0,1,2,4,5,6,7] ���±� 3 ������ת����ܱ�Ϊ [4,5,6,7,0,1,2] ��
���� ��ת�� ������ nums ��һ������ target ����� nums �д������Ŀ��ֵ target ���򷵻������±꣬���򷵻� -1 ��
��������һ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣

˼·���������ֲ��ҵı���

����Ĺؼ����ڣ���midΪ���������л��ֳ�����2�����䣻
ֻ��2�ֿ����ԣ�1�����������������䲿������2�������䲿����������������

��� nums[left] <= nums[mid]���������� left ~ mid Ϊ�������������䣻
    1�����target��������������䣬������������ų�����right�߽����գ�
    2�����û���룬������������ų�����left�߽����գ�

��� nums[left] > nums[mid]���������� mid ~ right Ϊ�������������䣻
    1�����target��������������䣬������������ų�����left�߽����գ�
    2�����û���룬������������ų�����right�߽����ա�

��ת����ı��ʣ�
������ֳ�2�룬һ����һ��������ġ�����target�Ƿ����������������䣬��left/right�߽�������գ��𽥱ƽ�target��
��ʵֻ��Ҫһ�����������������۰룡
*/
class Solution_0033 {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + right >> 1;
            if (nums[mid] == target)
                return mid;

            if (nums[left] <= nums[mid]) { // ����������������
                if (nums[left] <= target && target < nums[mid]) {
                    // �����������䣬right�߽�����
                    right = mid - 1;
                } else {
                    // û���룬�ų������䣬left�߽�����
                    left = mid + 1;
                }
            } else { // ����������������
                if (nums[mid] < target && target <= nums[right]) {
                    // �����������䣬left�߽�����
                    left = mid + 1;
                } else {
                    // û���룬�ų������䣬right�߽�����
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};