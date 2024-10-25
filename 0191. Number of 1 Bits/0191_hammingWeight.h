#pragma once

/*
191. 位1的个数
给定一个正整数 n，编写一个函数，获取一个正整数的二进制形式并返回其二进制表达式中 `设置位` 的个数（也被称为汉明重量）。
*/

/*
思路分析：
题目要求统计1bit的数量，常规的思路是逐一的比较每一个bit：
while(n){
    ans += n & 1;
    n >>= 1;
}
更加高效的方法是使用 n&(n-1) 干掉lowbit的技巧。
lowbit是最低位的1bit。
*/
class Solution {
public:
    int hammingWeight(int n)
    {
        int ans = 0;
        while (n) {
            n &= (n - 1);
            ++ans;
        }
        return ans;
    }
};