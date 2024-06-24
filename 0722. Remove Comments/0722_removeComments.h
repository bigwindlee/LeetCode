#pragma once
#include <string>
#include <vector>
using namespace std;

/*
ʹ������������inBlockComment ��ʾ�Ƿ��ڶ���ע���У�newLine ���ڹ�����ǰ�е����ݡ�
����ÿһ��Դ���룬����ַ�����
    - �������`����ע�Ϳ�ʼ��־`����������ע��ģʽ��
    - �������`����ע�ͽ�����־`�����˳�����ע��ģʽ��
    - ������� //������Ը��к�������ݡ�
    - �������ע���У����ַ���ӵ� newLine �С�
�����ǰ�в���ע������ newLine �ǿգ�������ӵ�����С�
���ش����Ĵ����С�

����ؼ������4��״̬��
1���������ע��ģʽ��
2���˳�����ע��ģʽ��
3��������ע�ͷ�����ȡ����һ�е�ɨ�裻
4����ǰ��ע�ͣ�����ַ��ռ���
*/
class Solution_0722 {
public:
    vector<string> removeComments(vector<string>& source)
    {
        vector<string> ans;
        bool inBlockComment = false; // ��ǰ�Ƿ��ڶ���ע��ģʽ��
        string newLine; // ����ַ��ռ�ÿһ�еķ�ע������

        for (const string& line : source) {
            // ֻ���ڷǶ���ע��ģʽ�У��������newLine��
            // ��Ϊ�ڶ���ע��ģʽ�У�newLine���ܰ�����Ч�Ĵ��룬���һ�û���ռ���ϣ�����Ҫ�����ռ������μ��ٷ�case2��
            if (!inBlockComment)
                newLine = "";

            for (int i = 0; i < line.length(); i++) { // ����ַ�ɨ��
                if (!inBlockComment && i + 1 < line.length() && line[i] == '/' && line[i + 1] == '*') {
                    inBlockComment = true;
                    i++;
                } else if (inBlockComment && i + 1 < line.length() && line[i] == '*' && line[i + 1] == '/') {
                    inBlockComment = false;
                    i++;
                } else if (!inBlockComment && i + 1 < line.length() && line[i] == '/' && line[i + 1] == '/') {
                    break; // ֻ����������ע�ͷ���������ǰ����һ�е�ɨ�裻
                } else if (!inBlockComment) {
                    newLine += line[i]; // ����ַ��ռ�������������ע��ʱ������Ҫ�����ռ���
                }
            }

            if (!inBlockComment && !newLine.empty()) {
                ans.push_back(newLine);
            }
        }

        return ans;
    }
};
