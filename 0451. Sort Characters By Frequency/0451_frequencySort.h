#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/*
451. �����ַ�����Ƶ������
����һ���ַ��� s �������ַ����ֵ� Ƶ�� ������� �������� ��һ���ַ����ֵ� Ƶ�� �����������ַ����еĴ�����
���� ��������ַ��� ������ж���𰸣����������κ�һ����

֪ʶ�㣺
1��Ƶ��ͳ��ͨ���ù�ϣ��ʹ�� operator[] ������һ�������ڵ� key��std::unordered_map ���Զ�����һ���µ�Ԫ�أ���Ԫ�ص� key ������ʵ� key��ֵ��Ĭ�Ϲ���ġ�
2��Ҫ��Թ�ϣ���key/value�е�value���н������У�ͨ��Ҫ�ѹ�ϣ����չ����vector<pair<type1, type2>>��Ȼ����һ�������õ�lambda���ʽ��������������
3����ϣ��ı������ṹ���󶨣���for(const auto& [c, n] : mp)
*/
class Solution_0451 {
public:
    string frequencySort(string s)
    {
        // Ƶ��ͳ��
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // ��Թ�ϣ���value���򣺹�ϣ��չ����vector������lambda���ʽ
        vector<pair<char, int>> rankMap(freq.begin(), freq.end());
        auto comparator = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        };
        sort(rankMap.begin(), rankMap.end(), comparator);

        // ������ϣ�����ɴ�
        string ans;
        for (const auto& [c, n] : rankMap) {
            for (int i = 0; i < n; ++i)
                ans += c;
        }
        return ans;
    }
};