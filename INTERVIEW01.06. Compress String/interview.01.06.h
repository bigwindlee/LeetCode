#pragma once
#include <string>
using namespace std;

/*
* 面试题 01.06. 字符串压缩
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:

 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:

 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：

字符串长度在[0, 50000]范围内。
*/

/*
思路分析：
双指针扫描字符串
*/
class Solution {
public:
    string compressString(string S)
    {
        string ans;
        int n = S.size(), i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && S[i] == S[j]) {
                ++j;
            }
            ans.push_back(S[i]);
            ans += to_string(j - i); // 有可能是2位数，不可以使用单个数字转字符的技巧：num - '0';
            i = j;
        }
        return ans.size() < S.size() ? ans : S;
    };
};