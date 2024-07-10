#pragma once
#include <unordered_map>
#include <vector>
using namespace std;

/*
349. ��������Ľ���
������������ nums1 �� nums2 ������ ���ǵ� ���� ���������е�ÿ��Ԫ��һ���� Ψһ �ġ����ǿ��� ��������������˳�� ��

˼·������
����ǳ���������ù�ϣ��ļ������ܽ���ظ����ֵ����⣡��nums1�е�����i��Ϊkey������ϣ��ʹ��nums2�е�����jֱ�Ӳ�����ϣ����1����
���j����nums1�У�um[j]ֵΪ-1��
���j��nums1�У���j�ظ���um[j]�ͻᱻ����2�Σ�

unordered_map�����ѧ��
unordered_map �� operator[] ���ʲ����ڵ�key���Զ����루����ֵ���͵�Ĭ�Ϲ��캯���������Ϊ�Զ������ǳ������ܺͼ򻯴���Ŀ��ǣ�
�� Python �� dict ��ѡ���׳��쳣���ṩ����ʽ�Ĵ�������ơ���������Ʒ�ӳ�����������ڲ�ͬӦ�ó�����ʹ����ѧ�ϵĲ��졣
*/
class Solution_0349 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        unordered_map<int, int> um;
        for (int i : nums1) {
            um[i] = 1; // nums1�е�������Ϊkey����ֵ����Ϊ1�����ؿ����ظ������֡�
        }
        for (int j : nums2) {
            --um[j]; // ���j���ظ������֣���ôum[j]������2�Σ�
            if (um[j] == 0)
                ans.push_back(j);
        }
        return ans;
    }
};