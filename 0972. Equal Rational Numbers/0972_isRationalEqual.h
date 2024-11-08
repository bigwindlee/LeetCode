#pragma once
#include <array>
#include <numeric>
#include <string>
using namespace std;

/* --------------------------------------------------------------------------------------------------------------------
972. 相等的有理数
给定两个字符串 s 和 t ，每个字符串代表一个非负有理数，只有当它们表示相同的数字时才返回 true 。字符串中可以使用括号来表示有理数的重复部分。
有理数 最多可以用三个部分来表示：整数部分 <IntegerPart>、小数非重复部分 <NonRepeatingPart> 和小数重复部分 <(><RepeatingPart><)>。
数字可以用以下三种方法之一来表示：
<IntegerPart> 
例： 0 ,12 和 123 

<IntegerPart><.><NonRepeatingPart>
例： 0.5 , 1. , 2.12 和 123.0001

<IntegerPart><.><NonRepeatingPart><(><RepeatingPart><)> 
例： 0.1(6) ， 1.(9)， 123.00(1212)

十进制展开的重复部分通常在一对圆括号内表示。例如：
1 / 6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66)
*/

/* --------------------------------------------------------------------------------------------------------------------
思路分析：小数转分数，约分后分别比较分子和分母；
通过字符串解析把数据拆成整数部分，不循环小数部分，循环小数部分，然后化成分数，然后通过通分取最大公约数化简分数，最后通过比较分子分母；

要点：
    1）数据拆分成3部分：整数、不循环小数部分、循环小数部分
    2）小数0.(abc)  <==>  abc/999；注意数学推导过程
*/
class Solution {
public:
    bool isRationalEqual(string s, string t)
    {
        // 数据拆分成3部分：整数、不循环小数部分、循环小数部分
        auto [intPart1, nonRepPart1, repPart1] = parseNumber(s);
        auto [intPart2, nonRepPart2, repPart2] = parseNumber(t);

        // 转成分数（字符串形式的`分子_分母`）
        string num1 = convertToFraction(intPart1, nonRepPart1, repPart1);
        string num2 = convertToFraction(intPart2, nonRepPart2, repPart2);

        return num1 == num2;
    }

private:
    // 解析字符串，将其分解为整数部分、非重复小数部分和重复小数部分
    array<string, 3> parseNumber(const string& s)
    {
        int pos_dot = s.find('.');
        int pos_left_paren = s.find('(');

        string integerPart = (pos_dot != string::npos) ? s.substr(0, pos_dot) : s;
        string nonRepeatingPart = (pos_dot != string::npos && pos_left_paren != string::npos)
            ? s.substr(pos_dot + 1, pos_left_paren - pos_dot - 1)
            : (pos_dot != string::npos ? s.substr(pos_dot + 1) : "");
        string repeatingPart = (pos_left_paren != string::npos)
            ? s.substr(pos_left_paren + 1, s.length() - pos_left_paren - 2)
            : "";

        return { integerPart, nonRepeatingPart, repeatingPart };
    }

    // 将字符串的整数部分、非重复小数部分和重复小数部分转换为分数表示
    string convertToFraction(const string& integerPart, const string& nonRepeatingPart, const string& repeatingPart)
    {
        long long intPart = stoll(integerPart);
        long long numerator, denominator;

        if (repeatingPart.empty()) {
            // 没有重复部分
            if (nonRepeatingPart.empty()) {
                numerator = intPart;
                denominator = 1;
            } else {
                long long nonRep = stoll(nonRepeatingPart);
                long long scale = pow(10, nonRepeatingPart.size());
                numerator = intPart * scale + nonRep;
                denominator = scale;
            }
        } else {
            // 有重复部分
            long long nonRep = (nonRepeatingPart.empty() ? 0 : stoll(nonRepeatingPart));
            long long rep = stoll(repeatingPart);
            long long scale1 = pow(10, nonRepeatingPart.size());
            long long scale2 = pow(10, repeatingPart.size());

            // 分子
            numerator = intPart * scale1 * (scale2 - 1) + nonRep * (scale2 - 1) + rep;
            // 分母
            denominator = scale1 * (scale2 - 1);
        }

        // 约分：分别除以最大公约数(Greatest Common Divisor)
        long long gcd_val = gcd(numerator, denominator); // since c++17
        return to_string(numerator / gcd_val) + "_" + to_string(denominator / gcd_val);
    }
};