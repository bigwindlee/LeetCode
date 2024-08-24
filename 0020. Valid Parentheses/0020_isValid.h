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
改进版：
为了避免单独写一个函数match来判断括号是否匹配，每次遇到左括号时，直接把它的右括号队友（期望值）入栈。
扫描字符串s遇到右括号时，比较它是否和栈顶的期望值比较，相等则匹配。
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