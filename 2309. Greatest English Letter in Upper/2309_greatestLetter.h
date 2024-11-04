#pragma once
#include <string>
using namespace std;

/*
2309. 兼具大小写的最好英文字母
给你一个由英文字母组成的字符串 s ，请你找出并返回 s 中的 最好 英文字母。返回的字母必须为大写形式。如果不存在满足条件的字母，则返回一个空字符串。
最好 英文字母的大写和小写形式必须 都 在 s 中出现。
英文字母 b 比另一个英文字母 a 更好 的前提是：英文字母表中，b 在 a 之 后 出现。
*/

/*
思路分析：哈希表
把26个字母映射成数组下标，并对数组进行标记，是一种常用的技法。
其实还是哈希表的思想，可以把数组理解成一种特化的哈希表。
*/
class Solution {
public:
    string greatestLetter(string s)
    {
        int arr1[26] = { 0 }, arr2[26] = { 0 };
        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                arr1[c - 'a'] = 1;
            } else {
                arr2[c - 'A'] = 1;
            }
        }

        string ans;
        for (int i = 25; i >= 0; --i) { // 逆序遍历，因为“最好英文字母”的定义是越大越好；
            if (arr1[i] == 1 && arr2[i] == 1) {
                ans.push_back('A' + i);
                return ans;
            }
        }
        return ans;
    }
};