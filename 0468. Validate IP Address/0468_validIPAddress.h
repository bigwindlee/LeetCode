#pragma once
#include <string>
using namespace std;

/*
468. ��֤IP��ַ
����һ���ַ��� queryIP���������Ч�� IPv4 ��ַ������ "IPv4" ���������Ч�� IPv6 ��ַ������ "IPv6" ����������������͵� IP ��ַ������ "Neither" ��

˼·��������˫ָ�룩
IPv4��delimiter��'.'
IPv6��delimiter��':'
delimiter�ָ���������˫ָ�루last��cur������λ�����䳤��Ϊ��cur - last - 1
���ɣ�
1��last�ĳ�ֵΪ-1��cur����ֵΪqueryIP.size()����������׼ȷ�ķָ���4�����䡣
2�������ǰ�����һ�����䣬ֱ�ӽ�cur��ֵ����ΪqueryIP.size()��

�Ϸ�Ipv4���������������
1��delimiter����ֳ�4�����䣻
2��ÿ������ĳ��ȱ���Ϸ���
3��������ÿ���ַ������������֣�
4�������ַ���ת�����ֱ��벻����255��
5������������ִ���0����ô������ǰ��0��

�Ϸ�IPv6���������������
1��delimiter����ֳ�8�����䣻
2��ÿ������ĳ��ȱ���Ϸ���
3��ÿ�����������һ��16�����ַ���������ǰ��0��

֪ʶ�㣺
1��std::isxdigit()�ж�һ���ַ��Ƿ��ǺϷ���16�������֣�
*/
class Solution_0468 {
public:
    string validIPAddress(string queryIP)
    {
        if (queryIP.find('.') != string::npos) {
            // IPv4
            int last = -1;
            for (int i = 0; i < 4; ++i) { // IPv4��4������
                int cur = (i == 3 ? queryIP.size() : queryIP.find('.', last + 1)); // ��һ��delimiter
                if (cur == string::npos) { // û�ҵ�delimiter��˵��������Ŀ���ԣ�
                    return "Neither";
                }
                if (cur - last - 1 < 1 || cur - last - 1 > 3) { // ���䳤�ȱ�����[1, 3]
                    return "Neither";
                }
                int addr = 0;
                for (int j = last + 1; j < cur; ++j) {
                    if (!isdigit(queryIP[j])) { // ÿ���ַ����붼������
                        return "Neither";
                    }
                    addr = addr * 10 + (queryIP[j] - '0'); // �����ַ���ת��������
                }
                if (addr > 255) { // ����ת�������ֺ󣬲��ܴ���255
                    return "Neither";
                }
                if (queryIP[last + 1] == '0' && cur - last - 1 > 1) { // ���������2λ���������ϣ�����ô������ǰ��0��
                    return "Neither";
                }
                last = cur; // ˫ָ��ǰ�ƣ�ָ����һ�����䣻
            }
            return "IPv4";
        } else {
            // IPv6
            int last = -1;
            for (int i = 0; i < 8; ++i) { // IPv6��8������
                int cur = (i == 7 ? queryIP.size() : queryIP.find(':', last + 1));
                if (cur == string::npos) { // û�ҵ�delimiter��˵��������Ŀ���ԣ�
                    return "Neither";
                }
                if (cur - last - 1 < 1 || cur - last - 1 > 4) { // ���䳤�ȱ�����[1, 4]
                    return "Neither";
                }
                for (int j = last + 1; j < cur; ++j) { // �����ڱ���
                    if (!isxdigit(queryIP[j]))
                        return "Neither";
                }
                last = cur;
            }
            return "IPv6";
        }
    }
};