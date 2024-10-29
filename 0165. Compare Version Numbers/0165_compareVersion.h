#pragma once
#include <string>
using namespace std;

/*
165. 比较版本号
给你两个 版本号字符串 version1 和 version2 ，请你比较它们。版本号由被点 '.' 分开的修订号组成。修订号的值 是它 转换为整数 并忽略前导零。
比较版本号时，请按 从左到右的顺序 依次比较它们的修订号。如果其中一个版本字符串的修订号较少，则将缺失的修订号视为 0。
返回规则如下：
  ● 如果 version1 < version2 返回 -1，
  ● 如果 version1 > version2 返回 1，
  ● 除此之外返回 0。
*/

/*
比较修订号时，只需比较 忽略任何前导零后的整数值 。也就是说，修订号 1 和修订号 001 相等 。

如果版本号没有指定某个下标处的修订号，则该修订号视为 0 。（默认为0）

本质：以“点号”分区间，比较相同区间的整数（忽略前导0）。不存在的区间默认为0.

技巧：
    1）字符形式的数字 c 转整形，例如 '6' - '0' 转成整形的6.
    2）多个连续字符则：x *= 10; x += c -'0';
*/
class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0;
        while (i < n1 || j < n2) { // 任意下标有效
            long x = 0; // 不存在的区间默认为0
            while (i < n1 && version1[i] != '.') {
                x = x * 10 + (version1[i] - '0'); // 自动忽略前导0
                ++i;
            }
            ++i; // skip '.'

            long y = 0; // 不存在的区间默认为0
            while (j < n2 && version2[j] != '.') {
                y = y * 10 + (version2[j] - '0');
                ++j;
            }
            ++j; // skip '.'

            if (x != y) {
                return (x > y) ? 1 : -1;
            }
        }
        return 0;
    }
};