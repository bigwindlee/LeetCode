#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

/*
698. ����Ϊk����ȵ��Ӽ�
����һ����������  nums ��һ�������� k���ҳ��Ƿ��п��ܰ��������ֳ� k ���ǿ��Ӽ������ܺͶ���ȡ�

˼·������
���ϻ������⣬��һ�����ϻ���Ϊ��������������Ӽ����ǻ��ݷ��ľ���Ӧ�á�
������ÿ��Ԫ�ض�Ҫ�����Ž���ÿһ���Ӽ���Ͱ����ÿһ��Ͱ����һ����������
���������У��������������Ҫ��֦��
1�������Ͱ������������֦��
2����ͬ������·������֤��ʧ�ܣ���֦��
*/
class Solution_0698 {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) {
            return false;
        }
        vector<int> bucket(k);
        sort(nums.rbegin(), nums.rend()); // �������У����ٷ�֧��
        return backtrack(nums, bucket, k, 0, totalSum / k);
    }

    bool backtrack(vector<int>& nums, vector<int>& bucket, int k, int idx, int targetSum)
    {
        if (idx == nums.size()) {
            // �ߵ������˵��ÿ��idx����Ͱ�ˣ�����ÿ��Ͱ��û�������ôֻ��һ�ֿ��ܣ�ÿ��Ͱ�ĺͶ���targetSum��
            return true;
        }
        // ÿһ��Ͱ����һ������·����nums[idx]Ҫ�����Ž���ÿһ��Ͱ��ʧ������ݡ�
        for (int i = 0; i < k; ++i) {
            // (i > 0 && bucket[i - 1] == bucket[i]) ��һ����Ҫ�ļ�֦���ɣ�
            // ��Ϊ���ձ�����ռ��˳��nums[idx]����ܽ���bucket[i]��������(i > 0 && bucket[i - 1] == bucket[i])��
            // ����ζ��nums[idx]����bucket[i]�ͽ���bucket[i-1]��һ����ͬ������·��������ǰһ���Ѿ�֤������һ��ʧ�ܵ�·����������ͷ���true�ˣ���
            if (bucket[i] + nums[idx] > targetSum || (i > 0 && bucket[i - 1] == bucket[i])) {
                continue;
            }
            bucket[i] += nums[idx];
            if (backtrack(nums, bucket, k, idx + 1, targetSum)) {
                return true;
            }
            bucket[i] -= nums[idx];
        }
        // ����������е�����·��֮��ʵ���Ҳ����Ϸ��Ľ⣬�Ż᷵��false��
        // ���ܷ���һ������·��ʧ�ܣ��ͷ���false��
        return false;
    }
};