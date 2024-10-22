#pragma once
#include <stack>
using namespace std;

/*
772. 基本计算器 III
实现一个基本的计算器来计算简单的表达式字符串。
表达式字符串只包含非负整数，算符 +、-、*、/ ，左括号 ( 和右括号 ) 。整数除法需要 向下截断 。
你可以假定给定的表达式总是有效的。所有的中间结果的范围均满足 [-2^31, 2^31 - 1] 。
注意：你不能使用任何将字符串作为表达式求值的内置函数，比如 eval() 。
*/

/*
思路分析：栈
*/
class Solution {
public:
    int calculate(string s)
    {
        int num = 0;
        char sign = '+';
        stack<int> stk;

        s += "+0"; // 重要技巧：解决最后一个num的归拢难题！
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isspace(c)) {
                continue;
            }
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                continue;
            }
            if (c == '(') {
                int left = 1, j = i;
                // 利用i/j定位，把小括号里面的子表达式提取出来，交给递归函数处理；
                // left表示左括号净余量（被右括号消耗后），left为0表示找到了匹配的右括号；
                // 这种方法可以处理小括号多层嵌套的情况！
                while (left > 0) {
                    ++j;
                    if (s[j] == '(') {
                        ++left;
                    } else if (s[j] == ')') {
                        --left;
                    }
                }
                // j指向右括号，提取括号里面的子表达式，交给递归函数处理
                num = calculate(s.substr(i + 1, j - i - 1));
                // i开始下一轮循环时会自动加1
                i = j;
                continue;
            }

            // 经过了上面的continue，到达此处的s[i]一定是运算符 + - * /
            // 注意这里的sign不是当前运算符，而是上一次的运算符，也就是num之前的运算符!
            if (sign == '+') {
                stk.push(num);
            } else if (sign == '-') {
                stk.push(-num);
            } else if (sign == '*') {
                stk.top() *= num;
            } else {
                stk.top() /= num;
            }

            // num清零，运算符迭代
            num = 0;
            sign = c;
        }

        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};