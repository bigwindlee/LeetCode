#pragma once
#include <unordered_set>
#include <vector>
using namespace std;

/*
2367. �������Ȳ��Ԫ�����Ŀ
����һ���±�� 0 ��ʼ���ϸ���� ���������� nums ��һ�������� diff �������������ȫ������������Ԫ�� (i, j, k) ����һ�� ������Ԫ�� ��
i < j < k ��
nums[j] - nums[i] == diff ��
nums[k] - nums[j] == diff
���ز�ͬ ������Ԫ�� ����Ŀ��

˼·����1��
��ֱ�۵Ľⷨ������ѭ������ö�٣�����Ȼ��û�����á��ϸ��������������

˼·����2��
������á��ϸ��������һ�߱������飬һ���ڹ�ϣ���в��ҡ����ѡ��Ƿ������棬һ�߰��Լ������ϣ���͡�1. ����֮�͡���˼·��ȫһ����
ע�� i < j < k ����Ϊ�ϸ��������ô nums[i] < nums[j] < nums[k] ��
������nums[i]ʱ��nums[j] �� nums[k] �϶��ǲ��ڹ�ϣ�����档
�����ڱ��������У�Ҫѯ�ʡ���С�Ķ��ѡ��ڲ��ڣ���ΪСֵ�����

����������п��ܵ���Ԫ���ټ������ֵ������ֱ���ò�ֵ��������ѵ�ֵ�����ù�ϣ���ж϶����ǲ��Ǵ��ڣ�
*/
class Solution_2367_01 { // ����ѭ������ö��
public:
    int arithmeticTriplets(vector<int>& nums, int diff)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if ((nums[j] - nums[i] == diff) && (nums[k] - nums[j] == diff)) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution_2367_02 { // ��ϣ��
public:
    int arithmeticTriplets(vector<int>& nums, int diff)
    {
        int ans = 0;
        unordered_set<int> hash;
        for (int i : nums) {
            if (hash.count(i - diff) && hash.count(i - 2 * diff)) { // ѯ�ʡ���С���Ķ����ڲ��ڣ�Сֵ�����
                ++ans;
            }
            hash.insert(i); // �Լ������ϣ��
        }

        return ans;
    }
};