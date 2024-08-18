#pragma once
#include <string>
using namespace std;

/*
345. ��ת�ַ����е�Ԫ����ĸ
����һ���ַ��� s ������ת�ַ����е�����Ԫ����ĸ�������ؽ���ַ�����
Ԫ����ĸ���� 'a'��'e'��'i'��'o'��'u'���ҿ����Դ�Сд������ʽ���ֲ�ֹһ�Ρ�

˼·������
��������ת�ַ���������Ҫ���뵽һͷһβ��˫ָ�������˶����������ݡ�
*/
class Solution_0345 {
public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isVowel(s[i])) {
                ++i; // ��Ԫ����������
            } else if (!isVowel(s[j])) {
                --j; // ��Ԫ����������
            } else {
                // i, jͬʱָ��Ԫ��
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};