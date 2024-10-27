#pragma once
#include <string>
#include <unordered_map>
using namespace std;

/*
387. 字符串中的第一个唯一字符
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
*/

/*
思路分析：哈希表
见到频率统计，就要联想到哈希表。
s 只包含小写字母，暗示可用数组模拟哈希表，提高效率。
*/
class Solution {
public:
    int firstUniqChar(string s)
    {
        vector<int> hash(26); // s 只包含小写字母，暗示可用数组模拟哈希表，提高效率。
        for (char c : s) {
            ++hash[c - 'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (hash[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};