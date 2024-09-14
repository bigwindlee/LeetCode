﻿#pragma once
#include <vector>
using namespace std;

/*
* 137. 只出现一次的数字 II
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。
*/

/*
思路分析：（位运算）
记得异或操作的本质是在每个比特位上做“模2加法”，通过异或操作可以把相同的2个数湮灭掉；
但是本题的相同元素恰好出现3次，本质上，我们要对每个比特位做“模3加法”，才能把出现3次的元素湮灭掉！
对于第i个比特，i取值范围[0, 32)，要遍历整个nums数组，统计第i个比特出现1的次数，如果孤立元素在i比特也是1，那么统计结果必然是3X + 1；
对3取模，就可以把出现3次的元素在这个比特位上湮灭！

复杂度：
  - 整个算法的时间复杂度为 O(n)，虽然每个数字遍历了32次，但 32 是一个常数，所以总体上仍然可以认为时间复杂度是 O(n)，即与输入数组的长度线性相关。
  - 空间复杂度是 O(1)，因为我们只使用了常数级的空间来存储变量。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int mask = 1 << i;
            int cnt = 0;
            for (int num : nums) {
                if ((num & mask) != 0) {
                    ++cnt; // 遍历整个数组统计第i个比特出现1的次数
                }
            }
            ans |= (cnt % 3) << i; // 如果孤立元素在i比特也是1，那么统计结果必然是3X + 1；
        }
        return ans;
    }
};