#pragma once
#include <algorithm>
using namespace std;

/*
* 397. 整数替换
给定一个正整数 n ，你可以做如下操作：
    1. 如果 n 是偶数，则用 n / 2替换 n 。
    2. 如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
返回 n 变为 1 所需的 最小替换次数 。

思路分析：DFS / 位操作 / 递归
要点：当n是奇数而且用n+1替换n时，先左移在加1；目的是使n尽快下降（相当于折半），避免递归堆栈爆炸；

*/
class Solution_0397 {
public:
    int integerReplacement(int n)
    {
        if (n == 1) { // 递归出口
            return 0;
        }
        int ans = 1; // 无论如何都要左移1位，先把这一步算上；
        if (n & 1) {
            // 如果n是奇数，有2个搜索方向：用n+1或者n-1替换n；选择其中最小的替换次数；
            // 因为n是奇数，如果用n-1替换，那么等价于直接左移1位；
            // 如果用n+1替换：因为n是奇数，加1会导致进位，而且加1后变成偶数，只能左移；
            // 所有这里我们先把n左移（舍弃最低位1比特），然后再加1（进位）；
            // 这样做完全等价于先加1在左移；好处是使n尽快下降（相当于折半），避免递归堆栈爆炸；
            ans += 1 + min(integerReplacement(n >> 1), integerReplacement((n >> 1) + 1));
        } else {
            // 如果n是偶数，只能左移；
            ans += integerReplacement(n >> 1);
        }
        return ans;
    }
};