#pragma once
#include <vector>
#include <numeric>
using namespace std;

/*
410. �ָ���������ֵ
����һ���Ǹ��������� nums ��һ������ k ������Ҫ���������ֳ� k ���ǿյ����������顣
���һ���㷨ʹ���� k ����������Ժ͵����ֵ��С��
*/

/*
˼·���������ֲ���
�������г�k�Σ�ÿһ�Σ��ǿգ�����һ��Ͱ���Ͱ��������Сֵ��
Ͱ���������ޣ�����Ҫ��֤���԰ѵ��������ֵװ�£�
Ͱ���������ޣ���������ȫ��Ԫ�ؽ���һ��Ͱ��
���֡���С�����ֵ��������ǳ��ʺ�ʹ�ö��ֲ��ң�
  �� ͨ��ȷ������������ޣ�������Ȼת��Ϊһ��`��������`�������ǵ����Ĺ������⡣
*/
class Solution_0410 {
public:
	int splitArray(vector<int>& nums, int k) {
		int left = *max_element(nums.begin(), nums.end());  // ��Сֵ�������е����Ԫ��
		int right = accumulate(nums.begin(), nums.end(), 0);  // ���ֵ��������ܺ�

		// ���ֲ���
		while (left < right) {
			int mid = left + (right - left) / 2; // ���м�ֵ��ͨ��д�����ɱ���Ǳ�ڵ������

			// ����Ƿ���Խ�����ָ�Ϊ k �Σ���ÿ�εĺͲ����� mid
			if (canSplit(nums, mid, k)) {
				right = mid;  // Ͱ����mid���ã��ս��ұ߽�
			}
			else {
				left = mid + 1;  // Ͱ����mid�����ã�mid�Ǹ���Чֵ�������������� + 1��
			}
		}

		return left;  // ���� left == right����������Ҫ�����С�����ֵ
	}

	// ���������������ж���Ͱ����Ϊ maxSum ������£��ܷ�����ֳ� k ��
	bool canSplit(const vector<int>& nums, int maxSum, int k) {
		int currentSum = 0;  // ��ǰĳ��Ͱ��ռ�õ�����
		int count = 1; // ��¼���������������ʼʱΪ 1

		for (int num : nums) {
			// �����ǰ������ĺͼ��ϵ�ǰԪ�ز����� maxSum
			if (currentSum + num <= maxSum) {
				currentSum += num;
			}
			else {
				// ����������Ҫװ��һ����Ͱ��
				count++;
				currentSum = num;

				// ������������������ k��˵����ǰ��Ͱ����maxSum�����á�
				if (count > k) {
					return false;
				}
			}
		}

		return true;
	}
};
