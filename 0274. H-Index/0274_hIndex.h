#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
* 274. H ָ��
����һ���������� citations ������ citations[i] ��ʾ�о��ߵĵ� i ƪ���ı����õĴ��������㲢���ظ��о��ߵ� h ָ����
����ά���ٿ��� h ָ���Ķ��壺h ���������ô����� ��һ��������Ա�� h ָ�� ��ָ�����������ٷ����� h ƪ���ģ����� ���� �� h ƪ���ı����ô������ڵ��� h ��
��� h �ж��ֿ��ܵ�ֵ��h ָ�� �����������Ǹ���

˼·������
��Ŀ����ɬ��˵�˻����ǣ���������h����С��h��ֵ��������h��
ֻ�轫���齵�����У������Ƚ�Ԫ��ֵ��Ԫ���±ꡣ
*/
class Solution_0274 {
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.rbegin(), citations.rend());
        int i;
        for (i = 0; i < citations.size() && citations[i] > i; ++i)
            ;
        return i;
    }
};