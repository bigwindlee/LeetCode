#pragma once

/*
3370. 仅含置位位的最小整数
给你一个正整数 n。
返回 大于等于 n 且二进制表示仅包含 置位 位的 最小 整数 x 。
置位 位指的是二进制表示中值为 1 的位。

思路分析：位操作
1）首先确定最高比特位；
2）最高比特位右边的低比特位，全部置1；
*/

int smallestNumber(int n)
{
    bool highest = false;
    for (int i = 31; i >= 0; --i) {
        if (highest) {
            n |= (1 << i); // 最高比特位右边的每一个低比特位，全部置1；
        } else {
            if (n >> i) {
                highest = true; // 确定最高比特位
            }
        }
    }
    return n;
}