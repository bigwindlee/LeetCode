#pragma once
#include <string>
using namespace std;

/*
67. 二进制求和
给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

思路分析：加法模拟
1）和“2. 两数相加”的思路基本一样，只不过本题涉及到字符和数字互相转换的技巧：
    ① 字符 - '0' => 数字 
    ② 数字 + '0' => 字符
2）合理利用carry承载每一轮的求和；二进制加法下的对2取余、模运算；
3）string操作的技巧：size / back / pop_back / push_back / reverse 
*/
class Solution {
public:
    string addBinary(string a, string b)
    {
        string ans;
        int carry = 0; // 合理利用carry承载每一轮的求和
        while (a.size() || b.size() || carry) {
            if (a.size()) {
                carry += a.back() - '0';
                a.pop_back();
            }
            if (b.size()) {
                carry += b.back() - '0';
                b.pop_back();
            }
            ans.push_back(carry % 2 + '0');
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};