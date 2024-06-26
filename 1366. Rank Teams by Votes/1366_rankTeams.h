#pragma once
#include <string>
#include <vector>
using namespace std;

/* 
��Ҫ�������£�
1����ʼ��һ�� unordered_map ���洢ÿ��������ÿ��λ�õ�Ʊ����
2������ votes ���飬ͳ��ÿ��������ÿ��λ���ϵ�Ʊ����
3����ͳ�ƽ���洢��һ�� vector ���Ա�����
4��ʹ���Զ�����������Զ�������������ȸ���Ʊ�������������Ʊ����ͬ������ĸ˳������
5�������������������յ������ַ�����

��Ҫ������Ƴ�һ��ͳ��ÿ֧�����ڸ���λ�õĵ�Ʊ�������ݽṹ��
    unordered_map<char, vector<int>> rankMap;
ͳ��Ʊ��������֮����
    rankMap[vote[i]][i]++

֪ʶ�㣺
1�����ͳ��Ʊ�������ݽṹ��
2��ͳ��Ʊ����
3�������ϣ��չ����vector����������
4��ʹ��lambda���ʽʵ���������
5������lambda���ʽ��vector��������
*/
class Solution_1366 {
public:
    string rankTeams(vector<string>& votes)
    {
        int n = votes[0].size();
        unordered_map<char, vector<int>> rankMap; // ͳ��Ʊ�������ݽṹ

        // Initialize the rank map
        for (char c : votes[0]) {
            rankMap[c] = vector<int>(n, 0);
        }

        // Count the votes
        for (const string& vote : votes) {
            for (int i = 0; i < n; ++i) {
                rankMap[vote[i]][i]++; // �����ͳ��Ʊ��
            }
        }

        // Convert the rank map to a vector of pairs for sorting
        // ����ֵ���һ��(pair)����vector�У�Ŀ����Ϊ�˸���Ʊ������
        vector<pair<char, vector<int>>> rankVec(rankMap.begin(), rankMap.end());

        // Custom sort comparator
        // ���һ��lambda���ʽ��ʵ������������ΰ��ձ����ڵ�һλ�ĵ�Ʊ���������ڵڶ�λ�ĵ�Ʊ�����Դ����ơ�
        auto comparator = [](const pair<char, vector<int>>& a, const pair<char, vector<int>>& b) {
            for (int i = 0; i < a.second.size(); ++i) {
                if (a.second[i] != b.second[i]) {
                    return a.second[i] > b.second[i];
                }
            }
            return a.first < b.first; // �������ǲ��У��������ĸ˳��
        };

        // ������������������
        sort(rankVec.begin(), rankVec.end(), comparator);

        // Generate the result string
        string ans;
        for (const auto& p : rankVec) {
            ans += p.first;
        }

        return ans;
    }
};