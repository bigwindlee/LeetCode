﻿#pragma once

/*
258. 各位相加
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。
示例 1:
输入: num = 38
输出: 2 
解释: 各位相加的过程为：
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
由于 2 是一位数，所以返回 2。

示例 2:
输入: num = 0
输出: 0
*/

/*
思路分析：数论 -- 求树根
考虑到：18 --> 1 + 8 高位数字1变成1本身，损失了1个9；
推广：任何一个高位数字（非个位数），变成这个数字本身，都会损失若干一个9；
所以模9运算，取余数应该就是答案；
但是，9的倍数，其树根显然为9，所有应该想办法，把余数范围从[0, 8]调整到[1, 9]；
其实非9的倍数，模9运算的余数是对的；只需要考虑9的倍数，把余数从0调整为9；
有2种方法：
    1）模9运算前先减一，完成运算再加回来；
    2）针对9的倍数单独处理；return (num%9 == 0) ? 9 : num%9 ;
*/
class Solution {
public:
    int addDigits(int num)
    {
        return (num - 1) % 9 + 1; // 其实是把模9的余数的范围调整为：[1, 9]闭区间
    }
};

/*
思路分析2：递归
*/
class Solution_0258_02 {
public:
    int addDigits(int num)
    {
        while (num >= 10) {
            num = num % 10 + addDigits(num / 10);
        }
        return num;
    }
};