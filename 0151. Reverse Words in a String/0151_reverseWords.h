#pragma once
#include <string>
using namespace std;

/*
151. 反转字符串中的单词
给你一个字符串 s ，请你反转字符串中 单词 的顺序。
单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
*/

/*
思路分析：双指针/逆向扫描
凡是涉及到字符串中使用界定符划分区间的，要联想到双指针；
本题要求以单词为单位进行顺序颠倒，那么就涉及到单词的界定；
使用双指针：
    right: 从末尾开始逆向扫描，指向一个单词的末字符；
    left: 寻找right所指向单词的最边界；
从而可以用[left+1, right]区间界定一个单词！
*/
class Solution {
public:
    string reverseWords(string s)
    {
        int right = s.size() - 1;
        string ans;
        while (right >= 0) {
            while (right >= 0 && s[right] == ' ') { // 寻找单词的末字符（右边界）
                --right;
            }
            int left = right - 1;
            while (left >= 0 && s[left] != ' ') { // 寻找right所指向单词的左边界
                --left;
            }
            if (right >= 0) { // 只要right下标有效，所指向的单词就是存在的；left有可能为-1
                ans += s.substr(left + 1, right - left) + " ";
            }
            right = left - 1; // 迭代right下标
        }
        ans.pop_back(); // 删除末尾空位
        return ans;
    }
};