﻿#pragma once
#include <stack>
#include <string>
using namespace std;

/*
224. 基本计算器
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
*/

/*
思路分析：（栈：括号匹配问题）
1. 理解问题
这道题目要求我们实现一个基本计算器来计算并返回由数字、加号（+）、减号（-）、左右括号（(、)）、以及空格组成的字符串表达式的值。表达式只包含加减运算和括号，没有乘除运算。
核心问题是遇到左右括号怎么办？（开启新分段 + 用栈保存旧的result和新分段的符号 + 结束当前分段 + 弹出分段符号和旧的result）

2. 使用栈处理括号和操作符
由于表达式中包含括号，我们需要一种方法来处理不同优先级的计算，特别是嵌套括号的情况。栈（Stack）是一种理想的数据结构来管理这些计算的层次和顺序。

3. 遍历表达式
我们需要遍历整个字符串，对每个字符进行判断和处理：
  ● 数字：可能是多位数，因此需要从当前位置开始继续向后读取，直到不是数字为止，将其转换为整数。
  ● 操作符（+或-）：标记当前数字的符号。
  ● 括号：遇到左括号时，将之前的计算结果和当前的符号推入栈中，然后重置当前结果和符号以处理括号内的表达式。遇到右括号时，表示一个表达式的结束，需要将当前的计算结果与栈中的结果合并。

4. 计算结果
  ● 对于遇到的每个加号或减号，我们更新当前累计的结果。
  ● 遇到左括号，我们把之前的累计结果和符号存入栈中。
  ● 遇到右括号，我们将栈顶的符号乘以当前结果，并加上栈顶的累计结果。

5. 返回结果
最后，遍历完成后，我们将最后的数字（如果有）加到结果中，并返回该结果。

关键点
  ● 利用栈来处理和区分不同层级的表达式。
  ● 维护一个当前符号变量 sign，每次遇到数字都使用这个符号。
  ● 注意空格的处理，它们通常是为了可读性而存在，不影响计算逻辑。

这种方法能够有效地解决只含有加减运算和括号的复杂表达式的计算问题。
*/
class Solution_0224 {
public:
    int calculate(string s)
    {
        stack<int> results; // 开启新分段时，保存旧的result；
        stack<int> signs; // 开启新分段时，记录该分段的符号；等分段结束，恢复该分段的符号；
        int num = 0; // 扫描过程中收集数字
        int result = 0; // 分段的结果；遇见'('开启新分段，旧的result要入栈保存；
        int sign = 1; // 正/负符号

        for (char c : s) {
            if (isdigit(c)) {
                num = (num * 10) + (c - '0'); // 扫描过程中收集数字
            } else if (c == '+' || c == '-') {
                result += sign * num; // 收集的数字连带符号归拢到分段结果result
                num = 0; // 收集的数字清零
                sign = (c == '+') ? 1 : -1; // 当前符号，用于下一个数字的归拢；
            } else if (c == '(') {
                // 开启新分段，要把旧的result，以及该分段的符号入栈保存；
                results.push(result);
                signs.push(sign);

                // Reset the sign and result for the new sub-expression
                sign = 1;
                result = 0; // 记录新分段的结果
            } else if (c == ')') {
                // 结束当前分段，首先要把收集到的数字num带符号归拢，并把num清零；
                // 为什么num必须清零？①考虑到表达式以数字结尾的情况，返回时必须对num归拢；②如果后面出现+/-符号，num会被归拢到result；
                // 无论那种情况，都要避免对num的重复归拢。总之，num归拢之后，立即清零！
                result += sign * num;
                num = 0;

                // 当前分段的符号预存在signs栈中，弹出并用它设置result的符号；
                result *= signs.top();
                signs.pop();

                // 把保存在栈中旧的result弹出，并累加到当前result；
                result += results.top();
                results.pop();
            }
        }

        // 考虑到表达式以数字结尾的情况，例如"1+1"，此时最后一个数字还在num里面，没有归拢；
        // 所以必须在返回时归拢；
        return result + (sign * num); // Last number in the expression
    }
};