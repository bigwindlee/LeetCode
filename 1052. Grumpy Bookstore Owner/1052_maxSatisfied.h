#pragma once
#include <vector>
using namespace std;

/*
1052. 爱生气的书店老板
有一个书店老板，他的书店开了 n 分钟。每分钟都有一些顾客进入这家商店。给定一个长度为 n 的整数数组 customers ，其中 customers[i] 是在第 i 分钟开始时进入商店的顾客数量，所有这些顾客在第 i 分钟结束后离开。
在某些分钟内，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。
当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。
书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 minutes 分钟不生气，但却只能使用一次。
请你返回 这一天营业下来，最多有多少客户能够感到满意 。
*/

/*
思路分析：定长滑动窗口
本题的本质上用一个定长的滑动窗口尽可能的挽救最大数量的客户。

技巧：
假设i顶着保护罩minutes的右边界往前走；这是使代码保持简洁和逻辑统一的重要假设，
否则的话，需要单独计算滑动窗口整个处于最左边的条件，作为进入循环之前的初始条件；
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int ans = 0, saved = 0, n = customers.size();
        for (int i = 0; i < n; ++i) {
            // 假设i顶着保护罩minutes的右边界往前走；
            // 那么循环体内要处理右边新进入保护罩的元素，以及左边离开保护罩的元素；
            if (grumpy[i] == 1) {
                saved += customers[i];
            }
            if (i >= minutes && grumpy[i - minutes] == 1) {
                saved -= customers[i - minutes]; // [i-minutes]离开保护罩
            }
            ans = max(ans, saved); // 挑战最大的挽救客户数量
        }

        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                ans += customers[i];
            }
        }
        return ans;
    }
};