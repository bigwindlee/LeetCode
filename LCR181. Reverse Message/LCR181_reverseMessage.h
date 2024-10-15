#pragma once
#include <string>
using namespace std;

/*
LCR 181. 字符串中的单词反转
你在与一位习惯从右往左阅读的朋友发消息，他发出的文字顺序都与正常相反但单词内容正确，为了和他顺利交流你决定写一个转换程序，把他所发的消息 message 转换为正常语序。
注意：输入字符串 message 中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

思路分析：（双指针）
对字符串进行扫描，经常使用双指针。很容易想到从字符串的尾部向头部进行逆向扫描。
一个指针right从末字符开始扫描，寻找第一个非空字符；一个指针left从当前指向非空字符的right开始向左扫描，寻找下一个非空字符；
这样从left到right之间的单词，就是一个需要返回的单词。

难点：
1. 所谓的双指针，并不是真的需要使用指针类型char*，而是把字符串看出数组，用数组的下标对字符串进行扫描！
   这样可以充分的利用string类型的substr()方法，把单词提取出来。
2. 每提取一个单词，都要在后面添加一个空格；在所有单词提取完毕后，去掉最后的空格。
*/
class Solution {
public:
    string reverseMessage(string message)
    {
        string ans;
        int n = message.size(), right = n - 1; // 用数组下标作为指针，从尾部向头部逆向扫描。
        while (right >= 0) {
            while (right >= 0 && message[right] == ' ') {
                --right;
            }
            if (right < 0) {
                break;
            }
            int left = right - 1; // left和right合作，界定一个单词。
            while (left >= 0 && message[left] != ' ') {
                --left;
            }
            ans += message.substr(left + 1, right - left) + ' ';
            right = left - 1; // 迭代：right从left开始继续向左寻找下一个非空字符
        }
        // 如果message不包含`非空格字符`，那么ans为空。
        // 所以必须先判断一下ans是否为空再弹出末尾的空格。
        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};
