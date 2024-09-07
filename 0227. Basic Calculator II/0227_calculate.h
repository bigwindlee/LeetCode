#pragma once
#include <stack>
#include <string>
using namespace std;

/*
227. 基本计算器 II
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
整数除法仅保留整数部分。
你可以假设给定的表达式总是有效的。所有中间结果将在 [-231, 231 - 1] 的范围内。
注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
*/

/*
思路分析：
加减的操作数直接入栈；乘除的操作数直接在栈顶进行运算！
扫描字符串时遇到运算符（加减乘除），把之前的num入栈，或者与栈顶元素进行计算（取决于num之前的运算符是什么，记在sign里面）；
然后用当前运算符迭代sign。

技巧：
  ● 在s字符串的末尾"+0"，解决了最后一个num归拢的难题。因为最后一个num面临的问题是，num之前的运算符有可能是"加减乘除"中的一个，最好是放在循环体内统一处理。

知识点：
  ● std::stack::top()返回的栈顶元素的引用，可以直接修改！避免弹出再插入的冗余操作！

*/
class Solution_0227_01 {
public:
    int calculate(string s)
    {
        int result = 0, num = 0;
        char sign = '+'; // 记住num之前的运算符；
        stack<int> stk;

        s += "+0"; // 解决最后一个num的归拢难题！
        for (char c : s) {
            if (isspace(c)) {
                continue;
            }
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                continue;
            }
            // 之前的continue，保证此处只剩下"+-*/"运算符了；这样方便在循环体末尾统一的对num清零，对sign迭代。
            if (sign == '+') {
                stk.push(num);
            } else if (sign == '-') {
                stk.push(-num);
            } else if (sign == '*') {
                stk.top() *= num; // 直接修改栈顶元素
            } else {
                stk.top() /= num; // 直接修改栈顶元素
            }
            num = 0;
            sign = c; // 操作符迭代
        }

        // 此时最后一个数字没有归拢，但是因为在末尾添加了"+0"，无需归拢了！
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};
