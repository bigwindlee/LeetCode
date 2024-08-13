#pragma once
#include <vector>
using namespace std;

/*
268. ��ʧ������
����һ������ [0, n] �� n ���������� nums ���ҳ� [0, n] �����Χ��û�г����������е��Ǹ�����

˼·����1��
���������⣬�����Կ��ǹ�ϣ�����߹�ϣ��ı��� -- ���飩��
[0, n]�ı�����һ���� n+1 ����������ȱʧ��һ������һ���� n ����Ҳ����nums�ĳ���Ϊn��
��׼��һ������Ϊ n+1 ������arr��ʹ��nums�е�������Ϊarr���±꣬���б�ǣ���ôһ����һ���±�û�б���ǣ�
û����ǵ��±���Ƕ�ʧ�����֣�

˼·����2��
��ʵ����һ���򵥵���ѧ�⡣�ѱ�����[0, n]�����е����ּ�������Ȼ�����μ�ȥnums�е����֣��ͻ��ȱʧ�����ֱ�¶������
˼·2�Ľ��棺���ǵ�������գ��ĳɡ��߼ӱ߼�����

˼·����3��
������ȥ���ظ����֡�����Ҫ���뵽����򡱲�����
*/

class Solution_0268_03 { // ˼·3��λ���㣨���
public:
    int missingNumber(vector<int>& nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i <= n; ++i) {
            ans ^= i;
        }
        for (int i : nums) {
            ans ^= i;
        }
        return ans;
    }

    // ���Ľ��棺��������һ��ѭ����
    int missingNumber_plus(vector<int>& nums)
    {
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans ^= (i ^ nums[i]);
        }
        return ans;
    }
};

class Solution_0268_02 { // ˼·2����ѧ����
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        // �ѱ�����[0, n]�����е����ּ�����
        int sum = n * (n + 1) / 2;
        // ���μ�ȥnums�е�����
        for (int i : nums) {
            sum -= i;
        }
        return sum;
    }

    // ˼·2�Ľ��棺���ǵ�������գ��ĳɡ��߼ӱ߼�����
    int missingNumber_plus(vector<int>& nums)
    {
        int n = nums.size();
        int ans = n; // �±�i�ķֲ���[0, n-1]��������ǰ��n�ӽ�����
        for (int i = 0; i < n; ++i) {
            ans += i - nums[i];
        }
        return ans;
    }
};

class Solution_0268_01 { // ˼·1����ϣ����
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> arr(n + 1); // ������飨��ϣ����壩
        for (int i : nums) {
            arr[i] = 1; // ���
        }
        // ����Ѱ��δ����ǵ��±�
        for (int i = 0; i <= n; ++i) {
            if (arr[i] == 0) { // δ�����
                return i;
            }
        }
        return -1;
    }
};