#pragma once
#include <string>
using namespace std;

/*
796. ��ת�ַ���
���������ַ���, s �� goal����������ɴ���ת����֮��s �ܱ�� goal ����ô���� true ��
s �� ��ת���� ���ǽ� s ����ߵ��ַ��ƶ������ұߡ� 
����, �� s = 'abcde'������תһ��֮��������'bcdea' ��

˼·������
����ⷨ��
    ����һ���ȽϺ��������ַ���s��start��㿪ʼ����goal�ַ����е��ַ���һ�Ƚϣ�s���±굽��ĩβ�����ֻص�s���±���㡣��`ȡ��`���������±ꡣ
    ö���ַ���s���±꣬��Ϊ���start��goal���бȽϡ������ַ�������������ء�
�����Խⷨ��
    �����ת����ȣ���ô(s+s)һ������goal������ֻ��Ҫһ��find������

֪ʶ�㣺
    std::string��find����������string::npos
*/
class Solution_0796_2 {
public:
    // �����Խⷨ�������ת����ȣ���ô(s+s)һ������goal������ֻ��Ҫһ��find������
    bool rotateString(string s, string goal)
    {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};

class Solution_0796_1 {
public:
    // ����ⷨ��ö��s��ÿһ���±���Ϊ��goal�Ƚϵ���㡣
    bool rotateString(string s, string goal)
    {
        int n = s.size();
        if (n != goal.size()) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (cmpString(s, i, goal)) {
                return true;
            }
        }
        return false;
    }

    // ����ⷨ�ıȽϺ������趨�Ƚϵ����start������`ȡ��`���������±ꡣ
    bool cmpString(string s, int start, string goal)
    {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int j = (i + start) % n;
            if (s[j] != goal[i]) {
                return false;
            }
        }
        return true;
    }
};
