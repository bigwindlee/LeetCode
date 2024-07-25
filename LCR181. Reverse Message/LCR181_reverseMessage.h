#pragma once
#include <string>
using namespace std;

/*
LCR 181. �ַ����еĵ��ʷ�ת
������һλϰ�ߴ��������Ķ������ѷ���Ϣ��������������˳���������෴������������ȷ��Ϊ�˺���˳�����������дһ��ת�����򣬰�����������Ϣ message ת��Ϊ��������
ע�⣺�����ַ��� message �п��ܻ����ǰ���ո�β��ո���ߵ��ʼ�Ķ���ո񡣷��صĽ���ַ����У����ʼ�Ӧ�����õ����ո�ָ����Ҳ������κζ���Ŀո�

˼·��������˫ָ�룩
���ַ�������ɨ�裬����ʹ��˫ָ�롣�������뵽���ַ�����β����ͷ����������ɨ�衣
һ��ָ��right��ĩ�ַ���ʼɨ�裬Ѱ�ҵ�һ���ǿ��ַ���һ��ָ��left�ӵ�ǰָ��ǿ��ַ���right��ʼ����ɨ�裬Ѱ����һ���ǿ��ַ���
������left��right֮��ĵ��ʣ�����һ����Ҫ���صĵ��ʡ�

�ѵ㣺
1. ��ν��˫ָ�룬�����������Ҫʹ��ָ������char*�����ǰ��ַ����������飬��������±���ַ�������ɨ�裡
   �������Գ�ֵ�����string���͵�substr()�������ѵ�����ȡ������
2. ÿ��ȡһ�����ʣ���Ҫ�ں������һ���ո������е�����ȡ��Ϻ�ȥ�����Ŀո�
*/
class Solution_LCR181 {
public:
    string reverseMessage(string message)
    {
        int n = message.size();
        string ans;
        int right = n - 1; // �������±���Ϊָ�룬��β����ͷ������ɨ�衣
        while (right >= 0) {
            while (right >= 0 && message[right] == ' ') {
                --right;
            }
            if (right < 0) {
                break;
            }
            int left = right; // left��right�������綨һ�����ʡ�
            while (left >= 0 && message[left] != ' ') {
                --left;
            }
            ans += message.substr(left + 1, right - left);
            ans += ' ';
            right = left; // ������right��left��ʼ��������Ѱ����һ���ǿ��ַ�
        }
        // ���messageȫ�ǿո���ôansΪ�ա����Ա������ж�һ��ans�Ƿ�Ϊ���ٵ���ĩβ�Ŀո�
        if (ans.size() > 0) {
            ans.pop_back();
        }
        return ans;
    }
};