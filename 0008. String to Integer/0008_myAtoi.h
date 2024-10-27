#pragma once
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size(), sign = 1;
        // 跳过前导空格
        while (i < n && s[i] == ' ') {
            ++i;
        }

        // 处理符号
        bool isPositive = true;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+') ? 1 : -1;
            ++i;
        }

        // 转换数字
        long num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if (num * sign > INT_MAX) return INT_MAX;
            if (num * sign < INT_MIN) return INT_MIN;
            ++i;
        }

        return num * sign;
    }
};