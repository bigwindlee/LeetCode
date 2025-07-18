#pragma once

/*
201. 数字范围按位与
给你两个整数 left 和 right ，表示区间 [left, right] ，返回此区间内所有数字 按位与 的结果（包含 left 、right 端点）。

思路分析：位运算
本质上是求二进制表示的公共前缀。依次同时右移一位，记录右移的次数，取得公共前缀后，再左移回来。
*/
class Solution_0201 {
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left << shift;
    }
};