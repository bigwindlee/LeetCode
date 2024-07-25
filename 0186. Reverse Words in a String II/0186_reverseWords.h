#pragma once
#include <algorithm>
#include <vector>
using namespace std;

/*
186. ��ת�ַ����еĵ��� II
����һ���ַ����� s ����ת���� ���� ��˳��
���� �Ķ���Ϊ��������һ���ɷǿո��ַ���ɵ����С�s �еĵ��ʽ����ɵ����ո�ָ���
������Ʋ�ʵ�� ԭ�� �ⷨ����������⣬�����������Ŀռ䡣

˼·������
������ת�ַ�������Ҫ���뵽����ɨ�裻�Ե���Ϊ��λ���з�ת����Ҫ����2�η�ת��
1���Ƕ�����ķ�ת�����������ڲ�Ҳ����ת�ˣ���2�����ÿ�����ʽ��з�ת�������Ͱѵ���ԭ�ص���Ϊ�����ˡ�

�ѵ㣺
��left/rightָ��綨ÿ�����ʡ�
*/
class Solution {
public:
    void reverseWords(vector<char>& s)
    {
        int n = s.size();
        int right = n - 1;
        int p = 0, q = right; // p/q�����ڷ�ת��˫ָ��
        // ��һ�η�ת����������charΪ��λ���е���
        while (p < q) {
            swap(s[p], s[q]);
            ++p;
            --q;
        }
        // �ڶ��η�ת����left/right�綨ÿ�����ʣ���ÿ������ԭ�ط�ת��
        while (right >= 0) {
            while (right >= 0 && s[right] == ' ') {
                --right;
            }
            if (right < 0) {
                return;
            }
            int left = right; // left��right��ʼ����ɨ��Ѱ�ҿո��ַ���2��ָ������綨һ�����ʡ�
            while (left >= 0 && s[left] != ' ') {
                --left;
            }
            p = left + 1, q = right;
            while (p < q) { // ��ÿ������ԭ�ط�ת
                swap(s[p], s[q]);
                ++p;
                --q;
            }
            right = left; // ����Ѱ����һ�����ʲ����з�ת
        }
    }
};