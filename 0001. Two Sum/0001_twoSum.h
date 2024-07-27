#pragma once
#include <unordered_map>
#include <vector>
using namespace std;

/*
1. ����֮��
����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
����԰�����˳�򷵻ش𰸡�

˼·����������ϣ��
����������ʹ��2��ѭ�������еĳɶ���Ͻ��б������ж�����Ƿ����target��ʱ�临�Ӷ�O(n^2)��
�Ż��棺ʹ�ù�ϣ��������value��index��ӳ�䣬�������Կ��ٵ�֪��ĳ��ֵ�Ƿ���ڣ��Լ���Ӧ��index��
��ϣ��Ĳ�����O(1)��������ֻ��Ҫ����һ�����飬ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)��

�����ܽ᣺
�������飬������value��index�Ĺ�ϣ��ӳ�䣬mp[nums[i]] = i����һ�ֳ��ü�����
*/
class Solution_0001 {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> um; // ������value��index�Ĺ�ϣ��ӳ��
        for (int i = 0; i < nums.size(); ++i) {
            if (um.count(target - nums[i]) > 0) { // ��������Ƿ���ڣ��Ѿ���������
                return { um[target - nums[i]], i };
            }
            um[nums[i]] = i; // ���
        }
        return { -1, -1 };
    }
};
