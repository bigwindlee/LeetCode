#pragma once
#include <string>
#include <unordered_map>
using namespace std;

/*
思路分析：滑动窗口 + 哈希表
是否包含字符的组合，不在乎字符的顺序，也就是每个字符的出现频率一样，很容易想到哈希表。
从n2长度字符串中找一个n1长度的子集，很容易想到滑动窗口。

要点：
  ● 不能使用`异或操作`的结果来判断2个字符串包含的字符一样，例如：'k' ^ 'e' = 14, 'g' ^ 'i' = 14，都是14。
  ● 哈希表可以直接进行相等性判断，但是要注意把数量是0的key删掉，否则会影响比较结果；
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) {
            return false;
        }

        unordered_map<int, int> hash1;
        unordered_map<int, int> hash2;
        for (int i = 0; i < n1; ++i) {
            ++hash1[s1[i]];
            ++hash2[s2[i]];
        }
        if (hash1 == hash2) {
            return true;
        }
        // j指向滑动窗口的末字符
        for (int j = n1; j < n2; ++j) {
            // 窗口滑动，左边字符掉出窗口；右边字符新进入；
            if (--hash2[s2[j - n1]] == 0) { // 把数量降到0的key删掉，否则会影响相等性比较结果；
                hash2.erase(s2[j - n1]);
            };
            ++hash2[s2[j]];
            if (hash1 == hash2) {
                return true;
            }
        }
        return false;
    }
};