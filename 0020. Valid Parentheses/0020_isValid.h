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
class Solution_0020_01 {
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

/*
�Ľ��棺
Ϊ�˱��ⵥ��дһ������match���ж������Ƿ�ƥ�䣬ÿ������������ʱ��ֱ�Ӱ����������Ŷ��ѣ�����ֵ����ջ��
ɨ���ַ���s����������ʱ���Ƚ����Ƿ��ջ��������ֵ�Ƚϣ������ƥ�䡣
*/
class Solution_0020_02 {
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (char c : s) {
            if (c == '(') {
                stk.push(')');
            } else if (c == '[') {
                stk.push(']');
            } else if (c == '{') {
                stk.push('}');
            } else {
                if (stk.empty() || stk.top() != c) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};