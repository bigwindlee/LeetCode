#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

思路分析：（哈希表）
异位词所用的字母是一样的，只是排列不同；把它们排序后得到的字符串是一样的；
因此可以用一个哈希表，以排序后的字符串作为索引，把异位词组织在一起。
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash; // 以排序后的字符串作为索引，存储同组异位词。
        for (const string& s : strs) {
            string copy(s); // 副本用于原地排序，然后作为哈希表索引。
            sort(copy.begin(), copy.end());
            hash[copy].push_back(s);
        }
        for (const auto& pair : hash) { // iterate the hash table
            ans.push_back(pair.second);
        }
        return ans;
    }
};