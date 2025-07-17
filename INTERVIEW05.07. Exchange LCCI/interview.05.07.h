#pragma once

class Solution_I0507 {
public:
    int exchangeBits(int num)
    {
        for (int i = 0; i < 16; ++i) {
            int mask = (1 << 2 * i) | (1 << 2 * i + 1); // 相邻奇偶位的掩码
            if (((num >> 2 * i) & 1) != ((num >> 2 * i + 1) & 1)) {
                num ^= mask; // 相邻的奇偶位比特不同，则与掩码`11`异或执行翻转，效果等同于交换；
            }
        }
        return num;
    }
};