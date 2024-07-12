#pragma once
#include <algorithm>
using namespace std;

/*
2571. 将整数减少到零需要的最少操作数
给你一个正整数 n ，你可以执行下述操作 任意 次：

n 加上或减去 2 的某个 幂
返回使 n 等于 0 需要执行的 最少 操作数。

思路分析：位运算 + dfs
见到2的幂，就要联想到`位运算`。因为二进制的每个比特位都是2的幂。
见到多种可能的操作（加上或减去2的某个幂），就要联想到dfs。
难点：本题的搜索方向，绝不是加减所有可能的2的幂，这会引起搜索路径的爆炸。
真正的搜索方向，从lowbit入手。
lowbit的定义：整数的2进制表示中最低位的`1`比特。通过 n & -n 把lowbit提取出来。
从lowbit往左，可能有连续的1比特；因此可能的搜索方向是2个：
    1）+ lowbit : 这样可以把连续的1置为0；
    2) - lowbit : 这样可以把最低位的1干掉；

位运算技巧：
判断n是否是2的幂：(n & (n - 1)) == 0 表示n是2的幂；
提取lowbit：(n & -n) 因为 -n 是 n 的二进制补码表示，即 n 取反加 1（补码表示法）。
*/
class Solution_2571 {
public:
    int minOperations(int n)
    {
        if ((n & (n - 1)) == 0) {
            return 1;
        }
        int lb = n & -n; // 提取整数 n 的二进制表示中最低位的 1，这是一种常见的位操作技巧；
        return 1 + min(minOperations(n + lb), minOperations(n - lb));
    }
};