#pragma once
#include <string>
using namespace std;

/*
468. 验证IP地址
给定一个字符串 queryIP。如果是有效的 IPv4 地址，返回 "IPv4" ；如果是有效的 IPv6 地址，返回 "IPv6" ；如果不是上述类型的 IP 地址，返回 "Neither" 。

思路分析：（双指针）
IPv4的delimiter是'.'
IPv6的delimiter是':'
delimiter分隔的区间用双指针（last和cur）来定位；区间长度为：cur - last - 1
技巧：
1）last的初值为-1；cur的终值为queryIP.size()；这样可以准确的分隔出4个区间。
2）如果当前是最后一个区间，直接将cur的值设置为queryIP.size()；

合法Ipv4必须满足的条件：
1）delimiter必须分成4个区间；
2）每个区间的长度必须合法；
3）区间内每个字符都必须是数字；
4）区间字符串转成数字必须不大于255；
5）如果区间数字大于0，那么不能有前导0；

合法IPv6必须满足的条件：
1）delimiter必须分成8个区间；
2）每个区间的长度必须合法；
3）每个区间必须是一个16进制字符串；允许前导0；

知识点：
1）std::isxdigit()判断一个字符是否是合法的16进制数字；
*/
class Solution {
public:
    string validIPAddress(string queryIP) {
        int last = -1, cur; // 双指针
        if (queryIP.find('.') != string::npos) {
            for (int i = 0; i < 4; ++i) {
                cur = (i == 3) ? queryIP.size() : queryIP.find('.', last + 1);
                if (cur - last - 1 < 1 || cur - last - 1 > 3) return "Neither"; // 坑：区间不为空（有2个delimiter在一起的case）
                if (cur - last - 1 > 1 && queryIP[last + 1] == '0') return "Neither"; // 前导0
                int num = 0;
                for (int j = last + 1; j < cur; ++j) {
                    if (!isdigit(queryIP[j])) return "Neither"; // 非数字字符
                    num = num * 10 + (queryIP[j] - '0');
                }
                if (num > 255) return "Neither";
                last = cur; // 迭代准备下一轮循环
            }
            return "IPv4";
        }
        if (queryIP.find(':') != string::npos) {
            for (int i = 0; i < 8; ++i) {
                cur = (i == 7) ? queryIP.size() : queryIP.find(':', last + 1);
                if (cur - last - 1 < 1 || cur - last - 1 > 4) return "Neither"; // 坑：区间不为空（有2个delimiter在一起的case）
                for (int j = last + 1; j < cur; ++j) {
                    if (!isxdigit(queryIP[j])) return "Neither"; // 非16进制字符
                }
                last = cur; // 迭代准备下一轮循环
            }
            return "IPv6";
        }
        return "Neither";
    }
};
