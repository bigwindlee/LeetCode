#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/*
451. 根据字符出现频率排序
给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。
返回 已排序的字符串 。如果有多个答案，返回其中任何一个。

知识点：
1）频率统计通常用哈希表；使用 operator[] 来访问一个不存在的 key，std::unordered_map 会自动插入一个新的元素，该元素的 key 是你访问的 key，值是默认构造的。
2）要针对哈希表的key/value中的value进行降序排列，通常要把哈希表先展开成vector<pair<type1, type2>>，然后定义一个排序用的lambda表达式（匿名函数）；
3）哈希表的遍历（结构化绑定）：for(const auto& [c, n] : mp)
*/
class Solution_0451 {
public:
    string frequencySort(string s)
    {
        // 频率统计
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // 针对哈希表的value排序：哈希表展开成vector，定义lambda表达式
        vector<pair<char, int>> rankMap(freq.begin(), freq.end());
        auto comparator = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        };
        sort(rankMap.begin(), rankMap.end(), comparator);

        // 遍历哈希表，生成答案
        string ans;
        for (const auto& [c, n] : rankMap) {
            for (int i = 0; i < n; ++i)
                ans += c;
        }
        return ans;
    }
};