#pragma once
#include <vector>
using namespace std;

/*
leetcode 338. ����λ����
����һ������ n ������ 0 <= i <= n �е�ÿ�� i ������������Ʊ�ʾ�� 1 �ĸ��� ������һ������Ϊ n + 1 ������ ans ��Ϊ�𰸡�

˼·����1��
����˼·��������i��������1λ����ͳ�����λ1bit�ĸ�����

˼·����2��
��̬�滮��DP�ı�����Ѱ�ҵ��ƹ�ʽ�����Ӽ���������ʽ����ʾȫ����Ҳ���� dp[i] = f(dp[j1], dp[j2])������ j1 < i, j2 < i��
�����У�������i�Ķ����Ʊ�ʾ���ֳ�2�����֣����λ���أ��Լ����ʣ�µĲ��֡�
���ʣ�µĲ����е�1���ظ�������ʾΪdp[i>>1]����ô����dp[i]��ʲô�����أ�����������λ���أ�������λ��1bit����ôdp[i]�Ͷ�1����
�����ҵ��˵��ƹ�ʽ��dp[i] = dp[i>>1] + (i&1);
*/
class Solution {
public:
    // ����ⷨ��ͨ����������ͳ�����λ1���صĸ�����
    vector<int> countBits_1(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; ++i) {
            int b = i, count = 0;
            while (b) {
                count += b & 1;
                b >>= 1;
            }
            ans[i] = count;
        }
        return ans;
    }

    // DP�ⷨ
    vector<int> countBits_2(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i >> 1] + (i & 1); // ���Ʊ��ʽ
        }
        return dp;
    }
};