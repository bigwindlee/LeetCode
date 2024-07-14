#pragma once
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
3035. �����ַ������������ ����ϣͳ�� + ̰�ģ�
����һ���±�� 0 ��ʼ���ַ������� words ������ĳ���Ϊ n ���Ұ����±�� 0 ��ʼ�������ַ�����
�����ִ�����²��� ���� ������������Σ���
ѡ������i��j��x��y������0 <= i, j < n��0 <= x < words[i].length��0 <= y < words[j].length������ �ַ� words[i][x] �� words[j][y] ��
����һ����������ʾ��ִ��һЩ������words �п��԰����Ļ��Ĵ��� ��� ������
ע�⣺�ڲ��������У�i �� j ������ȡ�

˼·������
�ַ������е������ַ����������޴ν�������������˼�����ǰ������ַ��ռ���һ���ڻ���ַ����У��������γ����Ļ��Ĵ���
̰�ģ�
    �����ַ���ʱ��Ҫ���Ȼ�����̵��ַ��������������ĸ��ٵĳɶ��ַ�pair���γ����Ļ��Ĵ���
ע�⣺
    ����Ϊlen���ַ����������ʱ����Ҫ���� len/2 ���ַ�pair���ܹ��ɻ��Ĵ���lenΪ����������lenΪ1�������������赥������������
    ������Ƕȿ������⣬�Ǳ���Ĺؼ���
*/
class Solution_3035 {
public:
    int maxPalindromesAfterOperations(vector<string>& words)
    {
        // Ƶ��ͳ��һ��ʹ�ù�ϣ��unordered_map�����Ǳ���ȫ������Сд�ַ��������ػ���һ������26��int���鼴�ɡ�
        // ��a��z��Ӧ�����±�0~25��ע��ת���ļ��ɣ�char - 'a'
        vector<int> freq(26);
        // ��¼ÿ���ַ����ĳ��ȣ�һ�����Ҫ���ݳ�������
        vector<int> lens;
        for (const string& word : words) {
            for (char c : word) {
                ++freq[c - 'a'];
            }
            lens.push_back(word.size());
        }
        int pairs = 0;
        for (int f : freq) {
            pairs += f / 2; // �ܹ����һ�Ե��ַ�pairs����
        }
        // Ĭ��������Ϊ����Ҫ���Ȼ���ȸ��̵��ַ�����
        sort(lens.begin(), lens.end());
        int ans = 0;
        for (int len : lens) {
            pairs -= len / 2; // ���ĵ����ַ�pairs
            if (pairs < 0)
                break;
            ++ans;
        }
        return ans;
    }
};