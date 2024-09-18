#pragma once
#include <stack>
#include <string>
using namespace std;

/*
* 394. 字符串解码
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
*/

/*
思路分析：双栈
在扫描字符串的过程中，使用2个收集器，2个存储器；
ans:        收集字符
cnt:        收集数字
cntStack:   遇到左括号，把收集到的数字入栈，并清空收集器；
ansStack:   遇到左括号，把收集到的字符入栈，请清空收集器；

遇到右括号，弹出之前收集的字符和数字，对当前ans进行重复拼接，组成新的ans；拼接过程见图示。

双栈模式通常涉及两个独立的栈，分别用来处理不同类型的数据或任务。本题中收集到的字符和数字，就是两种不同类型的数据；
将不同的处理逻辑分开，简化操作，同时提高代码的可读性和可维护性。
*/
class Solution {
public:
    string decodeString(string s)
    {
        // 2个收集器，2个存储器；
        string ans;
        int cnt = 0;
        stack<int> cntStack;
        stack<string> ansStack;

        for (char c : s) {
            if (isdigit(c)) { // collect numbers
                cnt = cnt * 10 + (c - '0');
            } else if (c == '[') { // 遇到'['，把2个收集器的数据入栈，并把2个收集器清零。
                cntStack.push(cnt);
                ansStack.push(ans);
                cnt = 0;
                ans.clear();
            } else if (c == ']') { // 遇到']'，出栈，拼接。弹出的字符和当前的ans组成新的ans；
                string temp = ansStack.top();
                ansStack.pop();
                int repeatCnt = cntStack.top();
                cntStack.pop();
                for (int i = 0; i < repeatCnt; ++i) {
                    temp.append(ans); // 对当前ans按照重复次数进行拼接
                }
                ans = temp; // 完成拼接，组成新的ans；
            } else { // collect characters
                ans.push_back(c);
            }
        }
        return ans;
    }
};