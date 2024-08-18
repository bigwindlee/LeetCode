#pragma once
#include <vector>
using namespace std;

/*
198. ��ҽ���
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�

˼·������
��Ŀ����˼�ǴӸ����������ҳ�������������ʹ������
���������е��κ�һ��������ֻ��2�п��ܣ��ڡ����߲������յ����������С��������뵽 0-1 �������⡣����DP���⡣
dp[i]��ʾ�±������[0, i]���������Ĳ��������ͣ���ô����ĺ����ǣ�dp[i]��dp[i-1]������dp[i-2]֮����ʲô��ϵ��
��ʱnums[i]ֻ��2�п��ܣ����� or ���ڣ����������У�
1������ڣ���ônums[i-1]�϶����ڣ���Ϊ��������������ʱdp[i]�͵��� dp[i-2] + nums[i]
2��������ڣ���ʱdp[i]�͵��� dp[i-1]
dp[i]ȡ2������е����ֵ�������ҵ��˵��ƹ�ʽ��dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
*/
class Solution_0198 {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};