#pragma once
#include <stack>
#include <string>
using namespace std;

/*
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
  - 左括号必须用相同类型的右括号闭合。
  - 左括号必须以正确的顺序闭合。
  - 每个右括号都有一个对应的相同类型的左括号。
  
思路分析：
括号匹配问题，stack的典型应用场景。
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