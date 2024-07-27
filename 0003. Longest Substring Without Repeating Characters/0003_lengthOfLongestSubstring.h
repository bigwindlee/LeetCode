#pragma once
#include <string>
#include <unordered_set>
using namespace std;

/*
3. ���ظ��ַ�����Ӵ�
����һ���ַ��� s �������ҳ����в������ظ��ַ��� � �Ӵ� �ĳ��ȡ�

˼·���������������ڣ�
��������̣������飬��Ҫ���뵽�������ڣ�
��2��ָ��(i/j)����ʾ�������ڵı߽硣

�ѵ㣺
1. ����������`int hash[128]`����unordered_set���������ٶȣ������ڴ�ռ�ã�
2. i��j��Ҫ����������������
*/

class Solution_0003 {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        // �˴�������������ʵ����ģ��unordered_set�������ж��ظ��ַ���
        // ��Ϊstring�е�Ԫ������Ϊchar��ռһ���ֽڣ�ȡֵ��Χ[0, 127]����`int hash[128]`��ʾ�㹻�ˡ�
        // ��������������unordered_set�ٶȿ죬�ڴ�ռ���٣�
        int hash[128] = { 0 };
        int i = 0, j = 0, ans = 0; // i/j�ֱ��ǻ������ڵ����ұ߽�
        while (i < n) {
            // �ұ߽�j�������һ�����ֱ��Խ�磬����ָ���ظ��ַ���
            while (j < n && hash[s[j]] == 0) {
                ++hash[s[j++]]; // ����set����
            }
            // ��ǰj���������Ҳ����ָ���ظ��ַ���[i, j)֮����ַ�����һ����ѡ���ظ��Ӵ���
            ans = max(ans, j - i);
            // j��ͷ�ˣ�ѭ��û��Ҫ�ټ����ˣ������ٲ����Ĳ��ظ��Ӵ����Ȳ��ᳬ����ǰ��j-i
            if (j == n) {
                break;
            }

            // ��ʱj��Ȼָ���ظ��ַ�����߽�i�������һ�����ֱ�����ظ����ַ�ɾ����
            do {
                --hash[s[i++]]; // ��set�����а���ɾ��
            } while (s[i - 1] != s[j]);
        }
        return ans;
    }
};

// ��`unordered_set<char>`ʵ��
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        unordered_set<char> us; // �����ж��ظ��ַ�
        int i = 0, j = 0, ans = 0; // i/j�ֱ��ǻ������ڵ����ұ߽�
        while (i < n) {
            // �ұ߽�j�������һ�����ֱ��Խ�磬����ָ���ظ��ַ���
            while (j < n && us.count(s[j]) == 0) {
                us.insert(s[j++]);
            }
            // j��ͷ�ˣ�ѭ��û��Ҫ�ټ����ˣ������ٲ����Ĳ��ظ��Ӵ����Ȳ��ᳬ����ǰ��j-i
            if (j == n) {
                return max(ans, j - i);
            }
            // ��ǰj��ָ���ظ��ַ���[i, j)֮����ַ�����һ����ѡ���ظ��Ӵ���
            ans = max(ans, j - i);

            // ��߽�i�������һ�����ֱ�����ظ����ַ�ɾ����
            do {
                us.erase(s[i++]);
            } while (s[i - 1] != s[j]);
        }
        return ans;
    }
};