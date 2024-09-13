#pragma once
#include <vector>
using namespace std;

/*
605. 种花问题
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。
*/

/*
思路分析：
数组扫描。在扫描的过程中统计连续0的个数；每遇到1，归拢一次。
思考一下`连续0的个数`和`可插入1的个数`之间存在怎样的规律？
连续0的个数      可插入1的个数
3               1
5               2
7               3
可总结出，连续0的个数为zeros，产生的可插入1的个数为：(zeros - 1) / 2

第二个要注意的问题是边界问题。例如[0, 0, 1, 0, 0]
很显然，左边界的0和右边界的0的位置都可以插入1；为了保证公式(zeros - 1) / 2的统一有效，在数组头部和尾部分别添加一个0.
只需要添加到zeros里面即可，并不需要真的修改数组。
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        // ans统计可插入1的个数；zeros统计连续0的个数；
        int ans = 0, zeros = 1; // 头部补一个0
        for (int i : flowerbed) {
            if (i == 1) { // 每遇到1，归拢一次。
                if (zeros > 0) {
                    ans += (zeros - 1) / 2;
                    if (ans >= n) {
                        return true;
                    }
                    zeros = 0;
                }
            } else { // 统计连续0的个数。
                ++zeros;
            }
        }
        ans += (++zeros - 1) / 2; // 尾部补一个0
        return ans >= n;
    }
};