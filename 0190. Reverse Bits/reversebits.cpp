#pragma once
#include <cstdint>

/*
190. 颠倒二进制位
颠倒给定的 32 位无符号整数的二进制位。

思路分析：
常规的比特位运算：左移、右移、与、或操作。
*/
class Solution_0190 {
public:
    uint32_t reverseBits(uint32_t n)
    {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            // ans必须先左移再接纳最低位比特，这样才能保证左移和接纳是同步的；
            // 如果左移放在后面，最后一次循环会失去同步。
            // 首次左移时，ans为0，不影响结果正确，并达成统一处理；
            ans <<= 1;
            ans |= n & 1;
            n >>= 1;
        }
        return ans;
    }
};
