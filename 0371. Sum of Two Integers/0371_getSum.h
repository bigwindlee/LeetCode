#pragma once

/*
371. 两整数之和
给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。

思路分析：位操作（从二进制层面实现加法）
要点：
    1）进位的提取：与操作的结果左移一位；
    2）异或操作（模2加法）
*/
class Solution_0371 {
public:
    int getSum(int a, int b)
    {
        while (b) {
            int carry = (a & b) << 1; // 提取进位
            a ^= b;
            b = carry;
        }
        return a;
    }
};