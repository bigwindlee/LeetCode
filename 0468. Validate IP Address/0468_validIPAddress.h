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
class Solution_0468 {
public:
    string validIPAddress(string queryIP)
    {
        if (queryIP.find('.') != string::npos) {
            // IPv4
            int last = -1;
            for (int i = 0; i < 4; ++i) { // IPv4有4个区间
                int cur = (i == 3 ? queryIP.size() : queryIP.find('.', last + 1)); // 下一个delimiter
                if (cur == string::npos) { // 没找到delimiter，说明区间数目不对；
                    return "Neither";
                }
                if (cur - last - 1 < 1 || cur - last - 1 > 3) { // 区间长度必须是[1, 3]
                    return "Neither";
                }
                int addr = 0;
                for (int j = last + 1; j < cur; ++j) {
                    if (!isdigit(queryIP[j])) { // 每个字符必须都是数字
                        return "Neither";
                    }
                    addr = addr * 10 + (queryIP[j] - '0'); // 区间字符串转换成数字
                }
                if (addr > 255) { // 区间转换成数字后，不能大于255
                    return "Neither";
                }
                if (queryIP[last + 1] == '0' && cur - last - 1 > 1) { // 如果区间是2位数（或以上），那么不能有前导0；
                    return "Neither";
                }
                last = cur; // 双指针前移，指向下一个区间；
            }
            return "IPv4";
        } else {
            // IPv6
            int last = -1;
            for (int i = 0; i < 8; ++i) { // IPv6有8个区间
                int cur = (i == 7 ? queryIP.size() : queryIP.find(':', last + 1));
                if (cur == string::npos) { // 没找到delimiter，说明区间数目不对；
                    return "Neither";
                }
                if (cur - last - 1 < 1 || cur - last - 1 > 4) { // 区间长度必须是[1, 4]
                    return "Neither";
                }
                for (int j = last + 1; j < cur; ++j) { // 区间内遍历
                    if (!isxdigit(queryIP[j]))
                        return "Neither";
                }
                last = cur;
            }
            return "IPv6";
        }
    }
};