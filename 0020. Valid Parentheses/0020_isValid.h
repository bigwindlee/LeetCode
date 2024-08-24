#pragma once
#include <stack>
#include <string>
using namespace std;

/*
20. ��Ч������
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺
  - �����ű�������ͬ���͵������űպϡ�
  - �����ű�������ȷ��˳��պϡ�
  - ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
  
˼·������
����ƥ�����⣬stack�ĵ���Ӧ�ó�����
*/
class Solution {
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (!stk.empty() && match(stk.top(), c)) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }

    bool match(char a, char b)
    {
        return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
    }
};